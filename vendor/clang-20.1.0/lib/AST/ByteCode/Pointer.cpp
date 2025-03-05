//===--- Pointer.cpp - Types for the constexpr VM ---------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Pointer.h"
#include "Boolean.h"
#include "Context.h"
#include "Floating.h"
#include "Function.h"
#include "Integral.h"
#include "InterpBlock.h"
#include "MemberPointer.h"
#include "PrimType.h"
#include "Record.h"
#include "clang/AST/ExprCXX.h"
#include "clang/AST/RecordLayout.h"

using namespace clang;
using namespace clang::interp;

Pointer::Pointer(Block *Pointee)
    : Pointer(Pointee, Pointee->getDescriptor()->getMetadataSize(),
              Pointee->getDescriptor()->getMetadataSize()) {}

Pointer::Pointer(Block *Pointee, uint64_t BaseAndOffset)
    : Pointer(Pointee, BaseAndOffset, BaseAndOffset) {}

Pointer::Pointer(const Pointer &P)
    : Offset(P.Offset), PointeeStorage(P.PointeeStorage),
      StorageKind(P.StorageKind) {

  if (isBlockPointer() && PointeeStorage.BS.Pointee)
    PointeeStorage.BS.Pointee->addPointer(this);
}

Pointer::Pointer(Block *Pointee, unsigned Base, uint64_t Offset)
    : Offset(Offset), StorageKind(Storage::Block) {
  assert((Base == RootPtrMark || Base % alignof(void *) == 0) && "wrong base");

  PointeeStorage.BS = {Pointee, Base};

  if (Pointee)
    Pointee->addPointer(this);
}

Pointer::Pointer(Pointer &&P)
    : Offset(P.Offset), PointeeStorage(P.PointeeStorage),
      StorageKind(P.StorageKind) {

  if (StorageKind == Storage::Block && PointeeStorage.BS.Pointee)
    PointeeStorage.BS.Pointee->replacePointer(&P, this);
}

Pointer::~Pointer() {
  if (!isBlockPointer())
    return;

  if (Block *Pointee = PointeeStorage.BS.Pointee) {
    Pointee->removePointer(this);
    PointeeStorage.BS.Pointee = nullptr;
    Pointee->cleanup();
  }
}

void Pointer::operator=(const Pointer &P) {
  // If the current storage type is Block, we need to remove
  // this pointer from the block.
  if (isBlockPointer()) {
    if (P.isBlockPointer() && this->block() == P.block()) {
      Offset = P.Offset;
      PointeeStorage.BS.Base = P.PointeeStorage.BS.Base;
      return;
    }

    if (Block *Pointee = PointeeStorage.BS.Pointee) {
      Pointee->removePointer(this);
      PointeeStorage.BS.Pointee = nullptr;
      Pointee->cleanup();
    }
  }

  StorageKind = P.StorageKind;
  Offset = P.Offset;

  if (P.isBlockPointer()) {
    PointeeStorage.BS = P.PointeeStorage.BS;
    PointeeStorage.BS.Pointee = P.PointeeStorage.BS.Pointee;

    if (PointeeStorage.BS.Pointee)
      PointeeStorage.BS.Pointee->addPointer(this);
  } else if (P.isIntegralPointer()) {
    PointeeStorage.Int = P.PointeeStorage.Int;
  } else if (P.isFunctionPointer()) {
    PointeeStorage.Fn = P.PointeeStorage.Fn;
  } else if (P.isTypeidPointer()) {
    PointeeStorage.Typeid = P.PointeeStorage.Typeid;
  } else {
    assert(false && "Unhandled storage kind");
  }
}

void Pointer::operator=(Pointer &&P) {
  // If the current storage type is Block, we need to remove
  // this pointer from the block.
  if (isBlockPointer()) {
    if (P.isBlockPointer() && this->block() == P.block()) {
      Offset = P.Offset;
      PointeeStorage.BS.Base = P.PointeeStorage.BS.Base;
      return;
    }

    if (Block *Pointee = PointeeStorage.BS.Pointee) {
      assert(P.block() != this->block());
      Pointee->removePointer(this);
      PointeeStorage.BS.Pointee = nullptr;
      Pointee->cleanup();
    }
  }

  StorageKind = P.StorageKind;
  Offset = P.Offset;

  if (P.isBlockPointer()) {
    PointeeStorage.BS = P.PointeeStorage.BS;
    PointeeStorage.BS.Pointee = P.PointeeStorage.BS.Pointee;

    if (PointeeStorage.BS.Pointee)
      PointeeStorage.BS.Pointee->addPointer(this);
  } else if (P.isIntegralPointer()) {
    PointeeStorage.Int = P.PointeeStorage.Int;
  } else if (P.isFunctionPointer()) {
    PointeeStorage.Fn = P.PointeeStorage.Fn;
  } else if (P.isTypeidPointer()) {
    PointeeStorage.Typeid = P.PointeeStorage.Typeid;
  } else {
    assert(false && "Unhandled storage kind");
  }
}

APValue Pointer::toAPValue(const ASTContext &ASTCtx) const {
  llvm::SmallVector<APValue::LValuePathEntry, 5> Path;

  if (isZero())
    return APValue(static_cast<const Expr *>(nullptr), CharUnits::Zero(), Path,
                   /*IsOnePastEnd=*/false, /*IsNullPtr=*/true);
  if (isIntegralPointer())
    return APValue(static_cast<const Expr *>(nullptr),
                   CharUnits::fromQuantity(asIntPointer().Value + this->Offset),
                   Path,
                   /*IsOnePastEnd=*/false, /*IsNullPtr=*/false);
  if (isFunctionPointer())
    return asFunctionPointer().toAPValue(ASTCtx);

  if (isTypeidPointer()) {
    TypeInfoLValue TypeInfo(PointeeStorage.Typeid.TypePtr);
    return APValue(
        APValue::LValueBase::getTypeInfo(
            TypeInfo, QualType(PointeeStorage.Typeid.TypeInfoType, 0)),
        CharUnits::Zero(), APValue::NoLValuePath{});
  }

  // Build the lvalue base from the block.
  const Descriptor *Desc = getDeclDesc();
  APValue::LValueBase Base;
  if (const auto *VD = Desc->asValueDecl())
    Base = VD;
  else if (const auto *E = Desc->asExpr()) {
    // Create a DynamicAlloc base of the right type.
    if (const auto *NewExpr = dyn_cast<CXXNewExpr>(E)) {
      QualType AllocatedType;
      if (NewExpr->isArray()) {
        assert(Desc->isArray());
        APInt ArraySize(64, static_cast<uint64_t>(Desc->getNumElems()),
                        /*IsSigned=*/false);
        AllocatedType =
            ASTCtx.getConstantArrayType(NewExpr->getAllocatedType(), ArraySize,
                                        nullptr, ArraySizeModifier::Normal, 0);
      } else {
        AllocatedType = NewExpr->getAllocatedType();
      }
      // FIXME: Suboptimal counting of dynamic allocations. Move this to Context
      // or InterpState?
      static int ReportedDynamicAllocs = 0;
      DynamicAllocLValue DA(ReportedDynamicAllocs++);
      Base = APValue::LValueBase::getDynamicAlloc(DA, AllocatedType);
    } else {
      Base = E;
    }
  } else
    llvm_unreachable("Invalid allocation type");

  if (isUnknownSizeArray())
    return APValue(Base, CharUnits::Zero(), Path,
                   /*IsOnePastEnd=*/isOnePastEnd(), /*IsNullPtr=*/false);

  CharUnits Offset = CharUnits::Zero();

  auto getFieldOffset = [&](const FieldDecl *FD) -> CharUnits {
    // This shouldn't happen, but if it does, don't crash inside
    // getASTRecordLayout.
    if (FD->getParent()->isInvalidDecl())
      return CharUnits::Zero();
    const ASTRecordLayout &Layout = ASTCtx.getASTRecordLayout(FD->getParent());
    unsigned FieldIndex = FD->getFieldIndex();
    return ASTCtx.toCharUnitsFromBits(Layout.getFieldOffset(FieldIndex));
  };

  // Build the path into the object.
  Pointer Ptr = *this;
  while (Ptr.isField() || Ptr.isArrayElement()) {

    if (Ptr.isArrayRoot()) {
      // An array root may still be an array element itself.
      if (Ptr.isArrayElement()) {
        Ptr = Ptr.expand();
        unsigned Index = Ptr.getIndex();
        Path.push_back(APValue::LValuePathEntry::ArrayIndex(Index));
        QualType ElemType = Ptr.getFieldDesc()->getElemQualType();
        Offset += (Index * ASTCtx.getTypeSizeInChars(ElemType));
        Ptr = Ptr.getArray();
      } else {
        Path.push_back(APValue::LValuePathEntry(
            {Ptr.getFieldDesc()->asDecl(), /*IsVirtual=*/false}));

        if (const auto *FD =
                dyn_cast_if_present<FieldDecl>(Ptr.getFieldDesc()->asDecl()))
          Offset += getFieldOffset(FD);

        Ptr = Ptr.getBase();
      }
    } else if (Ptr.isArrayElement()) {
      Ptr = Ptr.expand();
      unsigned Index;
      if (Ptr.isOnePastEnd())
        Index = Ptr.getArray().getNumElems();
      else
        Index = Ptr.getIndex();

      QualType ElemType = Ptr.getFieldDesc()->getElemQualType();
      Offset += (Index * ASTCtx.getTypeSizeInChars(ElemType));
      Path.push_back(APValue::LValuePathEntry::ArrayIndex(Index));
      Ptr = Ptr.getArray();
    } else {
      bool IsVirtual = false;

      // Create a path entry for the field.
      const Descriptor *Desc = Ptr.getFieldDesc();
      if (const auto *BaseOrMember = Desc->asDecl()) {
        if (const auto *FD = dyn_cast<FieldDecl>(BaseOrMember)) {
          Ptr = Ptr.getBase();
          Offset += getFieldOffset(FD);
        } else if (const auto *RD = dyn_cast<CXXRecordDecl>(BaseOrMember)) {
          IsVirtual = Ptr.isVirtualBaseClass();
          Ptr = Ptr.getBase();
          const Record *BaseRecord = Ptr.getRecord();

          const ASTRecordLayout &Layout = ASTCtx.getASTRecordLayout(
              cast<CXXRecordDecl>(BaseRecord->getDecl()));
          if (IsVirtual)
            Offset += Layout.getVBaseClassOffset(RD);
          else
            Offset += Layout.getBaseClassOffset(RD);

        } else {
          Ptr = Ptr.getBase();
        }
        Path.push_back(APValue::LValuePathEntry({BaseOrMember, IsVirtual}));
        continue;
      }
      llvm_unreachable("Invalid field type");
    }
  }

  // We assemble the LValuePath starting from the innermost pointer to the
  // outermost one. SO in a.b.c, the first element in Path will refer to
  // the field 'c', while later code expects it to refer to 'a'.
  // Just invert the order of the elements.
  std::reverse(Path.begin(), Path.end());

  return APValue(Base, Offset, Path, /*IsOnePastEnd=*/isOnePastEnd(),
                 /*IsNullPtr=*/false);
}

void Pointer::print(llvm::raw_ostream &OS) const {
  switch (StorageKind) {
  case Storage::Block: {
    const Block *B = PointeeStorage.BS.Pointee;
    OS << "(Block) " << B << " {";

    if (isRoot())
      OS << "rootptr(" << PointeeStorage.BS.Base << "), ";
    else
      OS << PointeeStorage.BS.Base << ", ";

    if (isElementPastEnd())
      OS << "pastend, ";
    else
      OS << Offset << ", ";

    if (B)
      OS << B->getSize();
    else
      OS << "nullptr";
    OS << "}";
  } break;
  case Storage::Int:
    OS << "(Int) {";
    OS << PointeeStorage.Int.Value << " + " << Offset << ", "
       << PointeeStorage.Int.Desc;
    OS << "}";
    break;
  case Storage::Fn:
    OS << "(Fn) { " << asFunctionPointer().getFunction() << " + " << Offset
       << " }";
    break;
  case Storage::Typeid:
    OS << "(Typeid)";
  }
}

std::string Pointer::toDiagnosticString(const ASTContext &Ctx) const {
  if (isZero())
    return "nullptr";

  if (isIntegralPointer())
    return (Twine("&(") + Twine(asIntPointer().Value + Offset) + ")").str();

  return toAPValue(Ctx).getAsString(Ctx, getType());
}

bool Pointer::isInitialized() const {
  if (!isBlockPointer())
    return true;

  if (isRoot() && PointeeStorage.BS.Base == sizeof(GlobalInlineDescriptor)) {
    const GlobalInlineDescriptor &GD =
        *reinterpret_cast<const GlobalInlineDescriptor *>(block()->rawData());
    return GD.InitState == GlobalInitState::Initialized;
  }

  assert(PointeeStorage.BS.Pointee &&
         "Cannot check if null pointer was initialized");
  const Descriptor *Desc = getFieldDesc();
  assert(Desc);
  if (Desc->isPrimitiveArray()) {
    if (isStatic() && PointeeStorage.BS.Base == 0)
      return true;

    InitMapPtr &IM = getInitMap();

    if (!IM)
      return false;

    if (IM->first)
      return true;

    return IM->second->isElementInitialized(getIndex());
  }

  if (asBlockPointer().Base == 0)
    return true;

  // Field has its bit in an inline descriptor.
  return getInlineDesc()->IsInitialized;
}

void Pointer::initialize() const {
  if (!isBlockPointer())
    return;

  assert(PointeeStorage.BS.Pointee && "Cannot initialize null pointer");
  const Descriptor *Desc = getFieldDesc();

  if (isRoot() && PointeeStorage.BS.Base == sizeof(GlobalInlineDescriptor)) {
    GlobalInlineDescriptor &GD = *reinterpret_cast<GlobalInlineDescriptor *>(
        asBlockPointer().Pointee->rawData());
    GD.InitState = GlobalInitState::Initialized;
    return;
  }

  assert(Desc);
  if (Desc->isPrimitiveArray()) {
    // Primitive global arrays don't have an initmap.
    if (isStatic() && PointeeStorage.BS.Base == 0)
      return;

    // Nothing to do for these.
    if (Desc->getNumElems() == 0)
      return;

    InitMapPtr &IM = getInitMap();
    if (!IM)
      IM =
          std::make_pair(false, std::make_shared<InitMap>(Desc->getNumElems()));

    assert(IM);

    // All initialized.
    if (IM->first)
      return;

    if (IM->second->initializeElement(getIndex())) {
      IM->first = true;
      IM->second.reset();
    }
    return;
  }

  // Field has its bit in an inline descriptor.
  assert(PointeeStorage.BS.Base != 0 &&
         "Only composite fields can be initialised");
  getInlineDesc()->IsInitialized = true;
}

void Pointer::activate() const {
  // Field has its bit in an inline descriptor.
  assert(PointeeStorage.BS.Base != 0 &&
         "Only composite fields can be activated");

  if (isRoot() && PointeeStorage.BS.Base == sizeof(GlobalInlineDescriptor))
    return;
  if (!getInlineDesc()->InUnion)
    return;

  getInlineDesc()->IsActive = true;

  // Get the union, iterate over its fields and DEactivate all others.
  Pointer UnionPtr = getBase();
  while (!UnionPtr.getFieldDesc()->isUnion())
    UnionPtr = UnionPtr.getBase();

  const Record *UnionRecord = UnionPtr.getRecord();
  for (const Record::Field &F : UnionRecord->fields()) {
    Pointer FieldPtr = UnionPtr.atField(F.Offset);
    if (FieldPtr == *this) {
    } else {
      FieldPtr.getInlineDesc()->IsActive = false;
      // FIXME: Recurse.
    }
  }

  Pointer B = getBase();
  while (!B.isRoot() && B.inUnion()) {
    // FIXME: Need to de-activate other fields of parent records.
    B.getInlineDesc()->IsActive = true;
    assert(B.isActive());
    B = B.getBase();
  }
}

void Pointer::deactivate() const {
  // TODO: this only appears in constructors, so nothing to deactivate.
}

bool Pointer::hasSameBase(const Pointer &A, const Pointer &B) {
  // Two null pointers always have the same base.
  if (A.isZero() && B.isZero())
    return true;

  if (A.isIntegralPointer() && B.isIntegralPointer())
    return true;
  if (A.isFunctionPointer() && B.isFunctionPointer())
    return true;
  if (A.isTypeidPointer() && B.isTypeidPointer())
    return true;

  if (A.isIntegralPointer() || B.isIntegralPointer())
    return A.getSource() == B.getSource();

  if (A.StorageKind != B.StorageKind)
    return false;

  return A.asBlockPointer().Pointee == B.asBlockPointer().Pointee;
}

bool Pointer::pointToSameBlock(const Pointer &A, const Pointer &B) {
  if (!A.isBlockPointer() || !B.isBlockPointer())
    return false;
  return A.block() == B.block();
}

bool Pointer::hasSameArray(const Pointer &A, const Pointer &B) {
  return hasSameBase(A, B) &&
         A.PointeeStorage.BS.Base == B.PointeeStorage.BS.Base &&
         A.getFieldDesc()->IsArray;
}

bool Pointer::pointsToLiteral() const {
  if (isZero() || !isBlockPointer())
    return false;

  if (block()->isDynamic())
    return false;

  const Expr *E = block()->getDescriptor()->asExpr();
  return E && !isa<MaterializeTemporaryExpr, StringLiteral>(E);
}

std::optional<APValue> Pointer::toRValue(const Context &Ctx,
                                         QualType ResultType) const {
  const ASTContext &ASTCtx = Ctx.getASTContext();
  assert(!ResultType.isNull());
  // Method to recursively traverse composites.
  std::function<bool(QualType, const Pointer &, APValue &)> Composite;
  Composite = [&Composite, &Ctx, &ASTCtx](QualType Ty, const Pointer &Ptr,
                                          APValue &R) {
    if (const auto *AT = Ty->getAs<AtomicType>())
      Ty = AT->getValueType();

    // Invalid pointers.
    if (Ptr.isDummy() || !Ptr.isLive() || !Ptr.isBlockPointer() ||
        Ptr.isPastEnd())
      return false;

    // Primitive values.
    if (std::optional<PrimType> T = Ctx.classify(Ty)) {
      TYPE_SWITCH(*T, R = Ptr.deref<T>().toAPValue(ASTCtx));
      return true;
    }

    if (const auto *RT = Ty->getAs<RecordType>()) {
      const auto *Record = Ptr.getRecord();
      assert(Record && "Missing record descriptor");

      bool Ok = true;
      if (RT->getDecl()->isUnion()) {
        const FieldDecl *ActiveField = nullptr;
        APValue Value;
        for (const auto &F : Record->fields()) {
          const Pointer &FP = Ptr.atField(F.Offset);
          QualType FieldTy = F.Decl->getType();
          if (FP.isActive()) {
            if (std::optional<PrimType> T = Ctx.classify(FieldTy)) {
              TYPE_SWITCH(*T, Value = FP.deref<T>().toAPValue(ASTCtx));
            } else {
              Ok &= Composite(FieldTy, FP, Value);
            }
            ActiveField = FP.getFieldDesc()->asFieldDecl();
            break;
          }
        }
        R = APValue(ActiveField, Value);
      } else {
        unsigned NF = Record->getNumFields();
        unsigned NB = Record->getNumBases();
        unsigned NV = Ptr.isBaseClass() ? 0 : Record->getNumVirtualBases();

        R = APValue(APValue::UninitStruct(), NB, NF);

        for (unsigned I = 0; I < NF; ++I) {
          const Record::Field *FD = Record->getField(I);
          QualType FieldTy = FD->Decl->getType();
          const Pointer &FP = Ptr.atField(FD->Offset);
          APValue &Value = R.getStructField(I);

          if (std::optional<PrimType> T = Ctx.classify(FieldTy)) {
            TYPE_SWITCH(*T, Value = FP.deref<T>().toAPValue(ASTCtx));
          } else {
            Ok &= Composite(FieldTy, FP, Value);
          }
        }

        for (unsigned I = 0; I < NB; ++I) {
          const Record::Base *BD = Record->getBase(I);
          QualType BaseTy = Ctx.getASTContext().getRecordType(BD->Decl);
          const Pointer &BP = Ptr.atField(BD->Offset);
          Ok &= Composite(BaseTy, BP, R.getStructBase(I));
        }

        for (unsigned I = 0; I < NV; ++I) {
          const Record::Base *VD = Record->getVirtualBase(I);
          QualType VirtBaseTy = Ctx.getASTContext().getRecordType(VD->Decl);
          const Pointer &VP = Ptr.atField(VD->Offset);
          Ok &= Composite(VirtBaseTy, VP, R.getStructBase(NB + I));
        }
      }
      return Ok;
    }

    if (Ty->isIncompleteArrayType()) {
      R = APValue(APValue::UninitArray(), 0, 0);
      return true;
    }

    if (const auto *AT = Ty->getAsArrayTypeUnsafe()) {
      const size_t NumElems = Ptr.getNumElems();
      QualType ElemTy = AT->getElementType();
      R = APValue(APValue::UninitArray{}, NumElems, NumElems);

      bool Ok = true;
      for (unsigned I = 0; I < NumElems; ++I) {
        APValue &Slot = R.getArrayInitializedElt(I);
        const Pointer &EP = Ptr.atIndex(I);
        if (std::optional<PrimType> T = Ctx.classify(ElemTy)) {
          TYPE_SWITCH(*T, Slot = EP.deref<T>().toAPValue(ASTCtx));
        } else {
          Ok &= Composite(ElemTy, EP.narrow(), Slot);
        }
      }
      return Ok;
    }

    // Complex types.
    if (const auto *CT = Ty->getAs<ComplexType>()) {
      QualType ElemTy = CT->getElementType();

      if (ElemTy->isIntegerType()) {
        std::optional<PrimType> ElemT = Ctx.classify(ElemTy);
        assert(ElemT);
        INT_TYPE_SWITCH(*ElemT, {
          auto V1 = Ptr.atIndex(0).deref<T>();
          auto V2 = Ptr.atIndex(1).deref<T>();
          R = APValue(V1.toAPSInt(), V2.toAPSInt());
          return true;
        });
      } else if (ElemTy->isFloatingType()) {
        R = APValue(Ptr.atIndex(0).deref<Floating>().getAPFloat(),
                    Ptr.atIndex(1).deref<Floating>().getAPFloat());
        return true;
      }
      return false;
    }

    // Vector types.
    if (const auto *VT = Ty->getAs<VectorType>()) {
      assert(Ptr.getFieldDesc()->isPrimitiveArray());
      QualType ElemTy = VT->getElementType();
      PrimType ElemT = *Ctx.classify(ElemTy);

      SmallVector<APValue> Values;
      Values.reserve(VT->getNumElements());
      for (unsigned I = 0; I != VT->getNumElements(); ++I) {
        TYPE_SWITCH(ElemT, {
          Values.push_back(Ptr.atIndex(I).deref<T>().toAPValue(ASTCtx));
        });
      }

      assert(Values.size() == VT->getNumElements());
      R = APValue(Values.data(), Values.size());
      return true;
    }

    llvm_unreachable("invalid value to return");
  };

  // Invalid to read from.
  if (isDummy() || !isLive() || isPastEnd())
    return std::nullopt;

  // We can return these as rvalues, but we can't deref() them.
  if (isZero() || isIntegralPointer())
    return toAPValue(ASTCtx);

  // Just load primitive types.
  if (std::optional<PrimType> T = Ctx.classify(ResultType)) {
    TYPE_SWITCH(*T, return this->deref<T>().toAPValue(ASTCtx));
  }

  // Return the composite type.
  APValue Result;
  if (!Composite(ResultType, *this, Result))
    return std::nullopt;
  return Result;
}

IntPointer IntPointer::atOffset(const ASTContext &ASTCtx,
                                unsigned Offset) const {
  if (!this->Desc)
    return *this;
  const Record *R = this->Desc->ElemRecord;
  if (!R)
    return *this;

  const Record::Field *F = nullptr;
  for (auto &It : R->fields()) {
    if (It.Offset == Offset) {
      F = &It;
      break;
    }
  }
  if (!F)
    return *this;

  const FieldDecl *FD = F->Decl;
  const ASTRecordLayout &Layout = ASTCtx.getASTRecordLayout(FD->getParent());
  unsigned FieldIndex = FD->getFieldIndex();
  uint64_t FieldOffset =
      ASTCtx.toCharUnitsFromBits(Layout.getFieldOffset(FieldIndex))
          .getQuantity();
  return IntPointer{F->Desc, this->Value + FieldOffset};
}

IntPointer IntPointer::baseCast(const ASTContext &ASTCtx,
                                unsigned BaseOffset) const {
  const Record *R = Desc->ElemRecord;
  const Descriptor *BaseDesc = nullptr;

  // This iterates over bases and checks for the proper offset. That's
  // potentially slow but this case really shouldn't happen a lot.
  for (const Record::Base &B : R->bases()) {
    if (B.Offset == BaseOffset) {
      BaseDesc = B.Desc;
      break;
    }
  }
  assert(BaseDesc);

  // Adjust the offset value based on the information from the record layout.
  const ASTRecordLayout &Layout = ASTCtx.getASTRecordLayout(R->getDecl());
  CharUnits BaseLayoutOffset =
      Layout.getBaseClassOffset(cast<CXXRecordDecl>(BaseDesc->asDecl()));

  return {BaseDesc, Value + BaseLayoutOffset.getQuantity()};
}
