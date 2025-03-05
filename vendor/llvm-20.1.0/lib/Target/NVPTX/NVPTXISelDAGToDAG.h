//===-- NVPTXISelDAGToDAG.h - A dag to dag inst selector for NVPTX --------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the NVPTX target.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_NVPTX_NVPTXISELDAGTODAG_H
#define LLVM_LIB_TARGET_NVPTX_NVPTXISELDAGTODAG_H

#include "MCTargetDesc/NVPTXBaseInfo.h"
#include "NVPTX.h"
#include "NVPTXISelLowering.h"
#include "NVPTXRegisterInfo.h"
#include "NVPTXTargetMachine.h"
#include "llvm/ADT/MapVector.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/Compiler.h"

namespace llvm {

struct NVPTXScopes {
  NVPTXScopes() = default;
  NVPTXScopes(LLVMContext &C);
  NVPTX::Scope operator[](SyncScope::ID ID) const;
  bool empty() const;

private:
  SmallMapVector<SyncScope::ID, NVPTX::Scope, 8> Scopes{};
};

class LLVM_LIBRARY_VISIBILITY NVPTXDAGToDAGISel : public SelectionDAGISel {
  const NVPTXTargetMachine &TM;

  // If true, generate mul.wide from sext and mul
  bool doMulWide;

  int getDivF32Level() const;
  bool usePrecSqrtF32() const;
  bool useF32FTZ() const;
  bool allowFMA() const;
  bool allowUnsafeFPMath() const;
  bool doRsqrtOpt() const;

  NVPTXScopes Scopes{};

public:
  NVPTXDAGToDAGISel() = delete;

  explicit NVPTXDAGToDAGISel(NVPTXTargetMachine &tm, CodeGenOptLevel OptLevel);

  bool runOnMachineFunction(MachineFunction &MF) override;
  const NVPTXSubtarget *Subtarget = nullptr;

  bool SelectInlineAsmMemoryOperand(const SDValue &Op,
                                    InlineAsm::ConstraintCode ConstraintID,
                                    std::vector<SDValue> &OutOps) override;

private:
// Include the pieces autogenerated from the target description.
#include "NVPTXGenDAGISel.inc"

  void Select(SDNode *N) override;
  bool tryIntrinsicNoChain(SDNode *N);
  bool tryIntrinsicChain(SDNode *N);
  bool tryIntrinsicVoid(SDNode *N);
  void SelectTexSurfHandle(SDNode *N);
  bool tryLoad(SDNode *N);
  bool tryLoadVector(SDNode *N);
  bool tryLDGLDU(SDNode *N);
  bool tryStore(SDNode *N);
  bool tryStoreVector(SDNode *N);
  bool tryLoadParam(SDNode *N);
  bool tryStoreRetval(SDNode *N);
  bool tryStoreParam(SDNode *N);
  bool tryFence(SDNode *N);
  void SelectAddrSpaceCast(SDNode *N);
  bool tryBFE(SDNode *N);
  bool tryBF16ArithToFMA(SDNode *N);
  bool tryConstantFP(SDNode *N);
  bool SelectSETP_F16X2(SDNode *N);
  bool SelectSETP_BF16X2(SDNode *N);
  bool tryEXTRACT_VECTOR_ELEMENT(SDNode *N);
  void SelectV2I64toI128(SDNode *N);
  void SelectI128toV2I64(SDNode *N);
  void SelectCpAsyncBulkG2S(SDNode *N);
  void SelectCpAsyncBulkS2G(SDNode *N);
  void SelectCpAsyncBulkPrefetchL2(SDNode *N);
  void SelectCpAsyncBulkTensorG2SCommon(SDNode *N, bool IsIm2Col = false);
  void SelectCpAsyncBulkTensorS2GCommon(SDNode *N, bool IsIm2Col = false);
  void SelectCpAsyncBulkTensorPrefetchCommon(SDNode *N, bool IsIm2Col = false);
  void SelectCpAsyncBulkTensorReduceCommon(SDNode *N, unsigned RedOp,
                                           bool IsIm2Col = false);

  inline SDValue getI32Imm(unsigned Imm, const SDLoc &DL) {
    return CurDAG->getTargetConstant(Imm, DL, MVT::i32);
  }

  // Match direct address complex pattern.
  bool SelectDirectAddr(SDValue N, SDValue &Address);

  bool SelectADDRri_imp(SDNode *OpNode, SDValue Addr, SDValue &Base,
                        SDValue &Offset, MVT VT);
  bool SelectADDRri(SDNode *OpNode, SDValue Addr, SDValue &Base,
                    SDValue &Offset);
  bool SelectADDRri64(SDNode *OpNode, SDValue Addr, SDValue &Base,
                      SDValue &Offset);
  bool SelectADDRsi_imp(SDNode *OpNode, SDValue Addr, SDValue &Base,
                        SDValue &Offset, MVT VT);
  bool SelectADDRsi(SDNode *OpNode, SDValue Addr, SDValue &Base,
                    SDValue &Offset);
  bool SelectADDRsi64(SDNode *OpNode, SDValue Addr, SDValue &Base,
                      SDValue &Offset);

  bool ChkMemSDNodeAddressSpace(SDNode *N, unsigned int spN) const;

  static unsigned GetConvertOpcode(MVT DestTy, MVT SrcTy, LoadSDNode *N);

  // Returns the Memory Order and Scope that the PTX memory instruction should
  // use, and inserts appropriate fence instruction before the memory
  // instruction, if needed to implement the instructions memory order. Required
  // fences after the instruction need to be handled elsewhere.
  std::pair<NVPTX::Ordering, NVPTX::Scope>
  insertMemoryInstructionFence(SDLoc DL, SDValue &Chain, MemSDNode *N);
  NVPTX::Scope getOperationScope(MemSDNode *N, NVPTX::Ordering O) const;
};

class NVPTXDAGToDAGISelLegacy : public SelectionDAGISelLegacy {
public:
  static char ID;
  explicit NVPTXDAGToDAGISelLegacy(NVPTXTargetMachine &tm,
                                   CodeGenOptLevel OptLevel);
};
} // end namespace llvm

#endif
