//===-- RISCVRegisterBankInfo.cpp -------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
/// \file
/// This file implements the targeting of the RegisterBankInfo class for RISC-V.
/// \todo This should be generated by TableGen.
//===----------------------------------------------------------------------===//

#include "RISCVRegisterBankInfo.h"
#include "MCTargetDesc/RISCVMCTargetDesc.h"
#include "RISCVSubtarget.h"
#include "llvm/CodeGen/GlobalISel/GenericMachineInstrs.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/RegisterBank.h"
#include "llvm/CodeGen/RegisterBankInfo.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_TARGET_REGBANK_IMPL
#include "RISCVGenRegisterBank.inc"

namespace llvm {
namespace RISCV {

const RegisterBankInfo::PartialMapping PartMappings[] = {
    // clang-format off
    {0, 32, GPRBRegBank},
    {0, 64, GPRBRegBank},
    {0, 16, FPRBRegBank},
    {0, 32, FPRBRegBank},
    {0, 64, FPRBRegBank},
    {0, 64, VRBRegBank},
    {0, 128, VRBRegBank},
    {0, 256, VRBRegBank},
    {0, 512, VRBRegBank},
    // clang-format on
};

enum PartialMappingIdx {
  PMI_GPRB32 = 0,
  PMI_GPRB64 = 1,
  PMI_FPRB16 = 2,
  PMI_FPRB32 = 3,
  PMI_FPRB64 = 4,
  PMI_VRB64 = 5,
  PMI_VRB128 = 6,
  PMI_VRB256 = 7,
  PMI_VRB512 = 8,
};

const RegisterBankInfo::ValueMapping ValueMappings[] = {
    // Invalid value mapping.
    {nullptr, 0},
    // Maximum 3 GPR operands; 32 bit.
    {&PartMappings[PMI_GPRB32], 1},
    {&PartMappings[PMI_GPRB32], 1},
    {&PartMappings[PMI_GPRB32], 1},
    // Maximum 3 GPR operands; 64 bit.
    {&PartMappings[PMI_GPRB64], 1},
    {&PartMappings[PMI_GPRB64], 1},
    {&PartMappings[PMI_GPRB64], 1},
    // Maximum 3 FPR operands; 16 bit.
    {&PartMappings[PMI_FPRB16], 1},
    {&PartMappings[PMI_FPRB16], 1},
    {&PartMappings[PMI_FPRB16], 1},
    // Maximum 3 FPR operands; 32 bit.
    {&PartMappings[PMI_FPRB32], 1},
    {&PartMappings[PMI_FPRB32], 1},
    {&PartMappings[PMI_FPRB32], 1},
    // Maximum 3 FPR operands; 64 bit.
    {&PartMappings[PMI_FPRB64], 1},
    {&PartMappings[PMI_FPRB64], 1},
    {&PartMappings[PMI_FPRB64], 1},
    // Maximum 3 VR LMUL={1, MF2, MF4, MF8} operands.
    {&PartMappings[PMI_VRB64], 1},
    {&PartMappings[PMI_VRB64], 1},
    {&PartMappings[PMI_VRB64], 1},
    // Maximum 3 VR LMUL=2 operands.
    {&PartMappings[PMI_VRB128], 1},
    {&PartMappings[PMI_VRB128], 1},
    {&PartMappings[PMI_VRB128], 1},
    // Maximum 3 VR LMUL=4 operands.
    {&PartMappings[PMI_VRB256], 1},
    {&PartMappings[PMI_VRB256], 1},
    {&PartMappings[PMI_VRB256], 1},
    // Maximum 3 VR LMUL=8 operands.
    {&PartMappings[PMI_VRB512], 1},
    {&PartMappings[PMI_VRB512], 1},
    {&PartMappings[PMI_VRB512], 1},
};

enum ValueMappingIdx {
  InvalidIdx = 0,
  GPRB32Idx = 1,
  GPRB64Idx = 4,
  FPRB16Idx = 7,
  FPRB32Idx = 10,
  FPRB64Idx = 13,
  VRB64Idx = 16,
  VRB128Idx = 19,
  VRB256Idx = 22,
  VRB512Idx = 25,
};
} // namespace RISCV
} // namespace llvm

using namespace llvm;

RISCVRegisterBankInfo::RISCVRegisterBankInfo(unsigned HwMode)
    : RISCVGenRegisterBankInfo(HwMode) {}

const RegisterBank &
RISCVRegisterBankInfo::getRegBankFromRegClass(const TargetRegisterClass &RC,
                                              LLT Ty) const {
  switch (RC.getID()) {
  default:
    llvm_unreachable("Register class not supported");
  case RISCV::GPRRegClassID:
  case RISCV::GPRF16RegClassID:
  case RISCV::GPRF32RegClassID:
  case RISCV::GPRNoX0RegClassID:
  case RISCV::GPRNoX0X2RegClassID:
  case RISCV::GPRJALRRegClassID:
  case RISCV::GPRJALRNonX7RegClassID:
  case RISCV::GPRTCRegClassID:
  case RISCV::GPRTCNonX7RegClassID:
  case RISCV::GPRC_and_GPRTCRegClassID:
  case RISCV::GPRCRegClassID:
  case RISCV::GPRC_and_SR07RegClassID:
  case RISCV::SR07RegClassID:
  case RISCV::SPRegClassID:
  case RISCV::GPRX0RegClassID:
    return getRegBank(RISCV::GPRBRegBankID);
  case RISCV::FPR64RegClassID:
  case RISCV::FPR16RegClassID:
  case RISCV::FPR32RegClassID:
  case RISCV::FPR64CRegClassID:
  case RISCV::FPR32CRegClassID:
    return getRegBank(RISCV::FPRBRegBankID);
  case RISCV::VMRegClassID:
  case RISCV::VRRegClassID:
  case RISCV::VRNoV0RegClassID:
  case RISCV::VRM2RegClassID:
  case RISCV::VRM2NoV0RegClassID:
  case RISCV::VRM4RegClassID:
  case RISCV::VRM4NoV0RegClassID:
  case RISCV::VMV0RegClassID:
  case RISCV::VRM2_with_sub_vrm1_0_in_VMV0RegClassID:
  case RISCV::VRM4_with_sub_vrm1_0_in_VMV0RegClassID:
  case RISCV::VRM8RegClassID:
  case RISCV::VRM8NoV0RegClassID:
  case RISCV::VRM8_with_sub_vrm1_0_in_VMV0RegClassID:
    return getRegBank(RISCV::VRBRegBankID);
  }
}

static const RegisterBankInfo::ValueMapping *getFPValueMapping(unsigned Size) {
  unsigned Idx;
  switch (Size) {
  default:
    llvm_unreachable("Unexpected size");
  case 16:
    Idx = RISCV::FPRB16Idx;
    break;
  case 32:
    Idx = RISCV::FPRB32Idx;
    break;
  case 64:
    Idx = RISCV::FPRB64Idx;
    break;
  }
  return &RISCV::ValueMappings[Idx];
}

// TODO: Make this more like AArch64?
bool RISCVRegisterBankInfo::hasFPConstraints(
    const MachineInstr &MI, const MachineRegisterInfo &MRI,
    const TargetRegisterInfo &TRI) const {
  if (isPreISelGenericFloatingPointOpcode(MI.getOpcode()))
    return true;

  // If we have a copy instruction, we could be feeding floating point
  // instructions.
  if (MI.getOpcode() != TargetOpcode::COPY)
    return false;

  return getRegBank(MI.getOperand(0).getReg(), MRI, TRI) == &RISCV::FPRBRegBank;
}

bool RISCVRegisterBankInfo::onlyUsesFP(const MachineInstr &MI,
                                       const MachineRegisterInfo &MRI,
                                       const TargetRegisterInfo &TRI) const {
  switch (MI.getOpcode()) {
  case TargetOpcode::G_FPTOSI:
  case TargetOpcode::G_FPTOUI:
  case TargetOpcode::G_FCMP:
    return true;
  default:
    break;
  }

  return hasFPConstraints(MI, MRI, TRI);
}

bool RISCVRegisterBankInfo::onlyDefinesFP(const MachineInstr &MI,
                                          const MachineRegisterInfo &MRI,
                                          const TargetRegisterInfo &TRI) const {
  switch (MI.getOpcode()) {
  case TargetOpcode::G_SITOFP:
  case TargetOpcode::G_UITOFP:
    return true;
  default:
    break;
  }

  return hasFPConstraints(MI, MRI, TRI);
}

bool RISCVRegisterBankInfo::anyUseOnlyUseFP(
    Register Def, const MachineRegisterInfo &MRI,
    const TargetRegisterInfo &TRI) const {
  return any_of(
      MRI.use_nodbg_instructions(Def),
      [&](const MachineInstr &UseMI) { return onlyUsesFP(UseMI, MRI, TRI); });
}

static const RegisterBankInfo::ValueMapping *getVRBValueMapping(unsigned Size) {
  unsigned Idx;

  if (Size <= 64)
    Idx = RISCV::VRB64Idx;
  else if (Size == 128)
    Idx = RISCV::VRB128Idx;
  else if (Size == 256)
    Idx = RISCV::VRB256Idx;
  else if (Size == 512)
    Idx = RISCV::VRB512Idx;
  else
    llvm::report_fatal_error("Invalid Size");

  return &RISCV::ValueMappings[Idx];
}

const RegisterBankInfo::InstructionMapping &
RISCVRegisterBankInfo::getInstrMapping(const MachineInstr &MI) const {
  const unsigned Opc = MI.getOpcode();

  // Try the default logic for non-generic instructions that are either copies
  // or already have some operands assigned to banks.
  if (!isPreISelGenericOpcode(Opc) || Opc == TargetOpcode::G_PHI) {
    const InstructionMapping &Mapping = getInstrMappingImpl(MI);
    if (Mapping.isValid())
      return Mapping;
  }

  const MachineFunction &MF = *MI.getParent()->getParent();
  const MachineRegisterInfo &MRI = MF.getRegInfo();
  const TargetSubtargetInfo &STI = MF.getSubtarget();
  const TargetRegisterInfo &TRI = *STI.getRegisterInfo();

  unsigned GPRSize = getMaximumSize(RISCV::GPRBRegBankID);
  assert((GPRSize == 32 || GPRSize == 64) && "Unexpected GPR size");

  unsigned NumOperands = MI.getNumOperands();
  const ValueMapping *GPRValueMapping =
      &RISCV::ValueMappings[GPRSize == 64 ? RISCV::GPRB64Idx
                                          : RISCV::GPRB32Idx];

  switch (Opc) {
  case TargetOpcode::G_ADD:
  case TargetOpcode::G_SUB:
  case TargetOpcode::G_SHL:
  case TargetOpcode::G_ASHR:
  case TargetOpcode::G_LSHR:
  case TargetOpcode::G_AND:
  case TargetOpcode::G_OR:
  case TargetOpcode::G_XOR:
  case TargetOpcode::G_MUL:
  case TargetOpcode::G_SDIV:
  case TargetOpcode::G_SREM:
  case TargetOpcode::G_SMULH:
  case TargetOpcode::G_SMAX:
  case TargetOpcode::G_SMIN:
  case TargetOpcode::G_UDIV:
  case TargetOpcode::G_UREM:
  case TargetOpcode::G_UMULH:
  case TargetOpcode::G_UMAX:
  case TargetOpcode::G_UMIN:
  case TargetOpcode::G_PTR_ADD:
  case TargetOpcode::G_PTRTOINT:
  case TargetOpcode::G_INTTOPTR:
  case TargetOpcode::G_FADD:
  case TargetOpcode::G_FSUB:
  case TargetOpcode::G_FMUL:
  case TargetOpcode::G_FDIV:
  case TargetOpcode::G_FABS:
  case TargetOpcode::G_FNEG:
  case TargetOpcode::G_FSQRT:
  case TargetOpcode::G_FMAXNUM:
  case TargetOpcode::G_FMINNUM: {
    LLT Ty = MRI.getType(MI.getOperand(0).getReg());
    TypeSize Size = Ty.getSizeInBits();

    const ValueMapping *Mapping;
    if (Ty.isVector())
      Mapping = getVRBValueMapping(Size.getKnownMinValue());
    else if (isPreISelGenericFloatingPointOpcode(Opc))
      Mapping = getFPValueMapping(Size.getFixedValue());
    else
      Mapping = GPRValueMapping;

#ifndef NDEBUG
    // Make sure all the operands are using similar size and type.
    for (unsigned Idx = 1; Idx != NumOperands; ++Idx) {
      LLT OpTy = MRI.getType(MI.getOperand(Idx).getReg());
      assert(Ty.isVector() == OpTy.isVector() &&
             "Operand has incompatible type");
      // Don't check size for GPR.
      if (OpTy.isVector() || isPreISelGenericFloatingPointOpcode(Opc))
        assert(Size == OpTy.getSizeInBits() && "Operand has incompatible size");
    }
#endif // End NDEBUG

    return getInstructionMapping(DefaultMappingID, 1, Mapping, NumOperands);
  }
  case TargetOpcode::G_SEXTLOAD:
  case TargetOpcode::G_ZEXTLOAD:
    return getInstructionMapping(DefaultMappingID, /*Cost=*/1, GPRValueMapping,
                                 NumOperands);
  case TargetOpcode::G_IMPLICIT_DEF: {
    Register Dst = MI.getOperand(0).getReg();
    LLT DstTy = MRI.getType(Dst);
    unsigned DstMinSize = DstTy.getSizeInBits().getKnownMinValue();
    auto Mapping = GPRValueMapping;
    // FIXME: May need to do a better job determining when to use FPRB.
    // For example, the look through COPY case:
    // %0:_(s32) = G_IMPLICIT_DEF
    // %1:_(s32) = COPY %0
    // $f10_d = COPY %1(s32)
    if (DstTy.isVector())
      Mapping = getVRBValueMapping(DstMinSize);
    else if (anyUseOnlyUseFP(Dst, MRI, TRI))
      Mapping = getFPValueMapping(DstMinSize);

    return getInstructionMapping(DefaultMappingID, /*Cost=*/1, Mapping,
                                 NumOperands);
  }
  }

  SmallVector<const ValueMapping *, 4> OpdsMapping(NumOperands);

  switch (Opc) {
  case TargetOpcode::G_LOAD: {
    LLT Ty = MRI.getType(MI.getOperand(0).getReg());
    OpdsMapping[0] = GPRValueMapping;
    OpdsMapping[1] = GPRValueMapping;
    // Use FPR64 for s64 loads on rv32.
    if (GPRSize == 32 && Ty.getSizeInBits() == 64) {
      assert(MF.getSubtarget<RISCVSubtarget>().hasStdExtD());
      OpdsMapping[0] = getFPValueMapping(Ty.getSizeInBits());
      break;
    }

    // Check if that load feeds fp instructions.
    // In that case, we want the default mapping to be on FPR
    // instead of blind map every scalar to GPR.
    if (anyUseOnlyUseFP(MI.getOperand(0).getReg(), MRI, TRI))
      // If we have at least one direct use in a FP instruction,
      // assume this was a floating point load in the IR. If it was
      // not, we would have had a bitcast before reaching that
      // instruction.
      OpdsMapping[0] = getFPValueMapping(Ty.getSizeInBits());

    break;
  }
  case TargetOpcode::G_STORE: {
    LLT Ty = MRI.getType(MI.getOperand(0).getReg());
    OpdsMapping[0] = GPRValueMapping;
    OpdsMapping[1] = GPRValueMapping;
    // Use FPR64 for s64 stores on rv32.
    if (GPRSize == 32 && Ty.getSizeInBits() == 64) {
      assert(MF.getSubtarget<RISCVSubtarget>().hasStdExtD());
      OpdsMapping[0] = getFPValueMapping(Ty.getSizeInBits());
      break;
    }

    MachineInstr *DefMI = MRI.getVRegDef(MI.getOperand(0).getReg());
    if (onlyDefinesFP(*DefMI, MRI, TRI))
      OpdsMapping[0] = getFPValueMapping(Ty.getSizeInBits());
    break;
  }
  case TargetOpcode::G_SELECT: {
    LLT Ty = MRI.getType(MI.getOperand(0).getReg());

    if (Ty.isVector()) {
      auto &Sel = cast<GSelect>(MI);
      LLT TestTy = MRI.getType(Sel.getCondReg());
      assert(TestTy.isVector() && "Unexpected condition argument type");
      OpdsMapping[0] = OpdsMapping[2] = OpdsMapping[3] =
          getVRBValueMapping(Ty.getSizeInBits().getKnownMinValue());
      OpdsMapping[1] =
          getVRBValueMapping(TestTy.getSizeInBits().getKnownMinValue());
      break;
    }

    // Try to minimize the number of copies. If we have more floating point
    // constrained values than not, then we'll put everything on FPR. Otherwise,
    // everything has to be on GPR.
    unsigned NumFP = 0;

    // Use FPR64 for s64 select on rv32.
    if (GPRSize == 32 && Ty.getSizeInBits() == 64) {
      NumFP = 3;
    } else {
      // Check if the uses of the result always produce floating point values.
      //
      // For example:
      //
      // %z = G_SELECT %cond %x %y
      // fpr = G_FOO %z ...
      if (any_of(MRI.use_nodbg_instructions(MI.getOperand(0).getReg()),
                 [&](const MachineInstr &UseMI) {
                   return onlyUsesFP(UseMI, MRI, TRI);
                 }))
        ++NumFP;

      // Check if the defs of the source values always produce floating point
      // values.
      //
      // For example:
      //
      // %x = G_SOMETHING_ALWAYS_FLOAT %a ...
      // %z = G_SELECT %cond %x %y
      //
      // Also check whether or not the sources have already been decided to be
      // FPR. Keep track of this.
      //
      // This doesn't check the condition, since the condition is always an
      // integer.
      for (unsigned Idx = 2; Idx < 4; ++Idx) {
        Register VReg = MI.getOperand(Idx).getReg();
        MachineInstr *DefMI = MRI.getVRegDef(VReg);
        if (getRegBank(VReg, MRI, TRI) == &RISCV::FPRBRegBank ||
            onlyDefinesFP(*DefMI, MRI, TRI))
          ++NumFP;
      }
    }

    // Condition operand is always GPR.
    OpdsMapping[1] = GPRValueMapping;

    const ValueMapping *Mapping = GPRValueMapping;
    if (NumFP >= 2)
      Mapping = getFPValueMapping(Ty.getSizeInBits());

    OpdsMapping[0] = OpdsMapping[2] = OpdsMapping[3] = Mapping;
    break;
  }
  case TargetOpcode::G_FPTOSI:
  case TargetOpcode::G_FPTOUI:
  case RISCV::G_FCLASS: {
    LLT Ty = MRI.getType(MI.getOperand(1).getReg());
    OpdsMapping[0] = GPRValueMapping;
    OpdsMapping[1] = getFPValueMapping(Ty.getSizeInBits());
    break;
  }
  case TargetOpcode::G_SITOFP:
  case TargetOpcode::G_UITOFP: {
    LLT Ty = MRI.getType(MI.getOperand(0).getReg());
    OpdsMapping[0] = getFPValueMapping(Ty.getSizeInBits());
    OpdsMapping[1] = GPRValueMapping;
    break;
  }
  case TargetOpcode::G_FCMP: {
    LLT Ty = MRI.getType(MI.getOperand(2).getReg());

    unsigned Size = Ty.getSizeInBits();

    OpdsMapping[0] = GPRValueMapping;
    OpdsMapping[2] = OpdsMapping[3] = getFPValueMapping(Size);
    break;
  }
  case TargetOpcode::G_MERGE_VALUES: {
    // Use FPR64 for s64 merge on rv32.
    LLT Ty = MRI.getType(MI.getOperand(0).getReg());
    if (GPRSize == 32 && Ty.getSizeInBits() == 64) {
      assert(MF.getSubtarget<RISCVSubtarget>().hasStdExtD());
      OpdsMapping[0] = getFPValueMapping(Ty.getSizeInBits());
      OpdsMapping[1] = GPRValueMapping;
      OpdsMapping[2] = GPRValueMapping;
    }
    break;
  }
  case TargetOpcode::G_UNMERGE_VALUES: {
    // Use FPR64 for s64 unmerge on rv32.
    LLT Ty = MRI.getType(MI.getOperand(2).getReg());
    if (GPRSize == 32 && Ty.getSizeInBits() == 64) {
      assert(MF.getSubtarget<RISCVSubtarget>().hasStdExtD());
      OpdsMapping[0] = GPRValueMapping;
      OpdsMapping[1] = GPRValueMapping;
      OpdsMapping[2] = getFPValueMapping(Ty.getSizeInBits());
    }
    break;
  }
  default:
    // By default map all scalars to GPR.
    for (unsigned Idx = 0; Idx < NumOperands; ++Idx) {
       auto &MO = MI.getOperand(Idx);
       if (!MO.isReg() || !MO.getReg())
         continue;
       LLT Ty = MRI.getType(MO.getReg());
       if (!Ty.isValid())
         continue;

       if (Ty.isVector())
         OpdsMapping[Idx] =
             getVRBValueMapping(Ty.getSizeInBits().getKnownMinValue());
       else if (isPreISelGenericFloatingPointOpcode(Opc))
         OpdsMapping[Idx] = getFPValueMapping(Ty.getSizeInBits());
       else
         OpdsMapping[Idx] = GPRValueMapping;
    }
    break;
  }

  return getInstructionMapping(DefaultMappingID, /*Cost=*/1,
                               getOperandsMapping(OpdsMapping), NumOperands);
}
