//===-- AMDGPUInstPrinter.h - AMDGPU MC Inst -> ASM interface ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
/// \file
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUINSTPRINTER_H
#define LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"

namespace llvm {
class MCInstrDesc;

class AMDGPUInstPrinter : public MCInstPrinter {
public:
  AMDGPUInstPrinter(const MCAsmInfo &MAI,
                    const MCInstrInfo &MII, const MCRegisterInfo &MRI)
    : MCInstPrinter(MAI, MII, MRI) {}

  // Autogenerated by tblgen
  std::pair<const char *, uint64_t> getMnemonic(const MCInst *MI) override;
  void printInstruction(const MCInst *MI, uint64_t Address,
                        const MCSubtargetInfo &STI, raw_ostream &O);
  static const char *getRegisterName(MCRegister Reg);

  void printRegName(raw_ostream &OS, MCRegister Reg) const override;
  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &O) override;
  static void printRegOperand(unsigned RegNo, raw_ostream &O,
                              const MCRegisterInfo &MRI);

private:
  void printU4ImmOperand(const MCInst *MI, unsigned OpNo,
                         const MCSubtargetInfo &STI, raw_ostream &O);
  void printU16ImmOperand(const MCInst *MI, unsigned OpNo,
                          const MCSubtargetInfo &STI, raw_ostream &O);
  void printU4ImmDecOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  void printU8ImmDecOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  void printU16ImmDecOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  void printU32ImmOperand(const MCInst *MI, unsigned OpNo,
                          const MCSubtargetInfo &STI, raw_ostream &O);
  void printNamedBit(const MCInst *MI, unsigned OpNo, raw_ostream &O,
                     StringRef BitName);
  void printOffset(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                   raw_ostream &O);
  void printFlatOffset(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                       raw_ostream &O);

  void printOffset0(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printOffset1(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printSMRDOffset8(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printSMEMOffset(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printSMEMOffsetMod(const MCInst *MI, unsigned OpNo,
                          const MCSubtargetInfo &STI, raw_ostream &O);
  void printSMRDLiteralOffset(const MCInst *MI, unsigned OpNo,
                              const MCSubtargetInfo &STI, raw_ostream &O);
  void printCPol(const MCInst *MI, unsigned OpNo,
                 const MCSubtargetInfo &STI, raw_ostream &O);
  void printTH(const MCInst *MI, int64_t TH, int64_t Scope, raw_ostream &O);
  void printScope(int64_t Scope, raw_ostream &O);
  void printDMask(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                  raw_ostream &O);
  void printDim(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                raw_ostream &O);
  void printR128A16(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                 raw_ostream &O);
  void printFORMAT(const MCInst *MI, unsigned OpNo,
                   const MCSubtargetInfo &STI, raw_ostream &O);
  void printSymbolicFormat(const MCInst *MI,
                           const MCSubtargetInfo &STI, raw_ostream &O);

  void printRegOperand(unsigned RegNo, raw_ostream &O);
  void printVOPDst(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                   raw_ostream &O);
  void printVINTRPDst(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                      raw_ostream &O);
  void printImmediateInt16(uint32_t Imm, const MCSubtargetInfo &STI,
                           raw_ostream &O);
  void printImmediateBF16(uint32_t Imm, const MCSubtargetInfo &STI,
                          raw_ostream &O);
  void printImmediateF16(uint32_t Imm, const MCSubtargetInfo &STI,
                         raw_ostream &O);
  void printImmediateV216(uint32_t Imm, uint8_t OpType,
                          const MCSubtargetInfo &STI, raw_ostream &O);
  bool printImmediateFloat32(uint32_t Imm, const MCSubtargetInfo &STI,
                             raw_ostream &O);
  void printImmediate32(uint32_t Imm, const MCSubtargetInfo &STI,
                        raw_ostream &O);
  void printImmediate64(uint64_t Imm, const MCSubtargetInfo &STI,
                        raw_ostream &O, bool IsFP);
  void printOperand(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printRegularOperand(const MCInst *MI, unsigned OpNo,
                           const MCSubtargetInfo &STI, raw_ostream &O);
  void printOperand(const MCInst *MI, uint64_t /*Address*/, unsigned OpNum,
                    const MCSubtargetInfo &STI, raw_ostream &O) {
    printOperand(MI, OpNum, STI, O);
  }
  void printOperandAndFPInputMods(const MCInst *MI, unsigned OpNo,
                                  const MCSubtargetInfo &STI, raw_ostream &O);
  void printOperandAndIntInputMods(const MCInst *MI, unsigned OpNo,
                                   const MCSubtargetInfo &STI, raw_ostream &O);
  void printDPP8(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                 raw_ostream &O);
  void printDPPCtrl(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printDppRowMask(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printDppBankMask(const MCInst *MI, unsigned OpNo,
                        const MCSubtargetInfo &STI, raw_ostream &O);
  void printDppBoundCtrl(const MCInst *MI, unsigned OpNo,
                         const MCSubtargetInfo &STI, raw_ostream &O);
  void printDppFI(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                  raw_ostream &O);
  void printSDWASel(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  void printSDWADstSel(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printSDWASrc0Sel(const MCInst *MI, unsigned OpNo,
                        const MCSubtargetInfo &STI, raw_ostream &O);
  void printSDWASrc1Sel(const MCInst *MI, unsigned OpNo,
                        const MCSubtargetInfo &STI, raw_ostream &O);
  void printSDWADstUnused(const MCInst *MI, unsigned OpNo,
                          const MCSubtargetInfo &STI, raw_ostream &O);
  void printPackedModifier(const MCInst *MI, StringRef Name, unsigned Mod,
                           raw_ostream &O);
  void printOpSel(const MCInst *MI, unsigned OpNo,
                  const MCSubtargetInfo &STI, raw_ostream &O);
  void printOpSelHi(const MCInst *MI, unsigned OpNo,
                  const MCSubtargetInfo &STI, raw_ostream &O);
  void printNegLo(const MCInst *MI, unsigned OpNo,
                  const MCSubtargetInfo &STI, raw_ostream &O);
  void printNegHi(const MCInst *MI, unsigned OpNo,
                  const MCSubtargetInfo &STI, raw_ostream &O);
  void printIndexKey8bit(const MCInst *MI, unsigned OpNo,
                         const MCSubtargetInfo &STI, raw_ostream &O);
  void printIndexKey16bit(const MCInst *MI, unsigned OpNo,
                          const MCSubtargetInfo &STI, raw_ostream &O);
  void printInterpSlot(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printInterpAttr(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printInterpAttrChan(const MCInst *MI, unsigned OpNo,
                           const MCSubtargetInfo &STI, raw_ostream &O);

  void printGPRIdxMode(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printMemOperand(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printBLGP(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                 raw_ostream &O);
  void printCBSZ(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                 raw_ostream &O);
  void printABID(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                 raw_ostream &O);
  bool needsImpliedVcc(const MCInstrDesc &Desc, unsigned OpNo) const;
  void printDefaultVccOperand(bool FirstOperand, const MCSubtargetInfo &STI,
                              raw_ostream &O);
  void printWaitVDST(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printWaitEXP(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printWaitVAVDst(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printWaitVMVSrc(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);

  void printExpSrcN(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O, unsigned N);
  void printExpSrc0(const MCInst *MI, unsigned OpNo,
                    const MCSubtargetInfo &STI, raw_ostream &O);
  void printExpSrc1(const MCInst *MI, unsigned OpNo,
                    const MCSubtargetInfo &STI, raw_ostream &O);
  void printExpSrc2(const MCInst *MI, unsigned OpNo,
                    const MCSubtargetInfo &STI, raw_ostream &O);
  void printExpSrc3(const MCInst *MI, unsigned OpNo,
                    const MCSubtargetInfo &STI, raw_ostream &O);
  void printExpTgt(const MCInst *MI, unsigned OpNo,
                   const MCSubtargetInfo &STI, raw_ostream &O);
  void printByteSel(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);

public:
  static void printIfSet(const MCInst *MI, unsigned OpNo, raw_ostream &O,
                         StringRef Asm, StringRef Default = "");
  static void printIfSet(const MCInst *MI, unsigned OpNo, raw_ostream &O,
                         char Asm);
protected:
  void printAbs(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                raw_ostream &O);
  void printClamp(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                  raw_ostream &O);
  void printOModSI(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                   raw_ostream &O);
  void printLiteral(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printLast(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                 raw_ostream &O);
  void printNeg(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                raw_ostream &O);
  void printOMOD(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                 raw_ostream &O);
  void printRel(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                raw_ostream &O);
  void printUpdateExecMask(const MCInst *MI, unsigned OpNo,
                           const MCSubtargetInfo &STI, raw_ostream &O);
  void printUpdatePred(const MCInst *MI, unsigned OpNo,
                       const MCSubtargetInfo &STI, raw_ostream &O);
  void printWrite(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                  raw_ostream &O);
  void printBankSwizzle(const MCInst *MI, unsigned OpNo,
                        const MCSubtargetInfo &STI, raw_ostream &O);
  void printRSel(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                 raw_ostream &O);
  void printCT(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
               raw_ostream &O);
  void printKCache(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                   raw_ostream &O);
  void printSendMsg(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printSwizzle(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O);
  void printSWaitCnt(const MCInst *MI, unsigned OpNo,
                     const MCSubtargetInfo &STI, raw_ostream &O);
  void printDepCtr(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                   raw_ostream &O);
  void printSDelayALU(const MCInst *MI, unsigned OpNo,
                      const MCSubtargetInfo &STI, raw_ostream &O);
  void printHwreg(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                  raw_ostream &O);
  void printEndpgm(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                   raw_ostream &O);
};

} // End namespace llvm

#endif
