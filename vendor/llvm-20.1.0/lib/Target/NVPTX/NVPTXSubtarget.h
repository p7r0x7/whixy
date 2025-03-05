//=====-- NVPTXSubtarget.h - Define Subtarget for the NVPTX ---*- C++ -*--====//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the NVPTX specific subclass of TargetSubtarget.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_NVPTX_NVPTXSUBTARGET_H
#define LLVM_LIB_TARGET_NVPTX_NVPTXSUBTARGET_H

#include "NVPTX.h"
#include "NVPTXFrameLowering.h"
#include "NVPTXISelLowering.h"
#include "NVPTXInstrInfo.h"
#include "NVPTXRegisterInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include <string>

#define GET_SUBTARGETINFO_HEADER
#include "NVPTXGenSubtargetInfo.inc"

namespace llvm {

class NVPTXSubtarget : public NVPTXGenSubtargetInfo {
  virtual void anchor();
  std::string TargetName;

  // PTX version x.y is represented as 10*x+y, e.g. 3.1 == 31
  unsigned PTXVersion;

  // Full SM version x.y is represented as 100*x+10*y+feature, e.g. 3.1 == 310
  // sm_90a == 901
  unsigned int FullSmVersion;

  // SM version x.y is represented as 10*x+y, e.g. 3.1 == 31. Derived from
  // FullSmVersion.
  unsigned int SmVersion;

  NVPTXInstrInfo InstrInfo;
  NVPTXTargetLowering TLInfo;
  std::unique_ptr<const SelectionDAGTargetInfo> TSInfo;

  // NVPTX does not have any call stack frame, but need a NVPTX specific
  // FrameLowering class because TargetFrameLowering is abstract.
  NVPTXFrameLowering FrameLowering;

public:
  /// This constructor initializes the data members to match that
  /// of the specified module.
  ///
  NVPTXSubtarget(const Triple &TT, const std::string &CPU,
                 const std::string &FS, const NVPTXTargetMachine &TM);

  ~NVPTXSubtarget() override;

  const TargetFrameLowering *getFrameLowering() const override {
    return &FrameLowering;
  }
  const NVPTXInstrInfo *getInstrInfo() const override { return &InstrInfo; }
  const NVPTXRegisterInfo *getRegisterInfo() const override {
    return &InstrInfo.getRegisterInfo();
  }
  const NVPTXTargetLowering *getTargetLowering() const override {
    return &TLInfo;
  }

  const SelectionDAGTargetInfo *getSelectionDAGInfo() const override;

  bool hasAtomAddF64() const { return SmVersion >= 60; }
  bool hasAtomScope() const { return SmVersion >= 60; }
  bool hasAtomBitwise64() const { return SmVersion >= 32; }
  bool hasAtomMinMax64() const { return SmVersion >= 32; }
  bool hasAtomCas16() const { return SmVersion >= 70 && PTXVersion >= 63; }
  bool hasClusters() const { return SmVersion >= 90 && PTXVersion >= 78; }
  bool hasLDG() const { return SmVersion >= 32; }
  bool hasHWROT32() const { return SmVersion >= 32; }
  bool hasFP16Math() const { return SmVersion >= 53; }
  bool hasBF16Math() const { return SmVersion >= 80; }
  bool allowFP16Math() const;
  bool hasMaskOperator() const { return PTXVersion >= 71; }
  bool hasNoReturn() const { return SmVersion >= 30 && PTXVersion >= 64; }
  // Does SM & PTX support memory orderings (weak and atomic: relaxed, acquire,
  // release, acq_rel, sc) ?
  bool hasMemoryOrdering() const { return SmVersion >= 70 && PTXVersion >= 60; }
  // Does SM & PTX support atomic relaxed MMIO operations ?
  bool hasRelaxedMMIO() const { return SmVersion >= 70 && PTXVersion >= 82; }
  bool hasDotInstructions() const {
    return SmVersion >= 61 && PTXVersion >= 50;
  }
  // Prior to CUDA 12.3 ptxas did not recognize that the trap instruction
  // terminates a basic block. Instead, it would assume that control flow
  // continued to the next instruction. The next instruction could be in the
  // block that's lexically below it. This would lead to a phantom CFG edges
  // being created within ptxas. This issue was fixed in CUDA 12.3. Thus, when
  // PTX ISA versions 8.3+ we can confidently say that the bug will not be
  // present.
  bool hasPTXASUnreachableBug() const { return PTXVersion < 83; }
  bool hasCvtaParam() const { return SmVersion >= 70 && PTXVersion >= 77; }
  unsigned int getFullSmVersion() const { return FullSmVersion; }
  unsigned int getSmVersion() const { return getFullSmVersion() / 10; }
  // GPUs with "a" suffix have include architecture-accelerated features that
  // are supported on the specified architecture only, hence such targets do not
  // follow the onion layer model. hasAAFeatures() allows distinguishing such
  // GPU variants from the base GPU architecture.
  // - 0 represents base GPU model,
  // - non-zero value identifies particular architecture-accelerated variant.
  bool hasAAFeatures() const { return getFullSmVersion() % 10; }

  // If the user did not provide a target we default to the `sm_30` target.
  std::string getTargetName() const {
    return TargetName.empty() ? "sm_30" : TargetName;
  }
  bool hasTargetName() const { return !TargetName.empty(); }

  bool hasNativeBF16Support(int Opcode) const;

  // Get maximum value of required alignments among the supported data types.
  // From the PTX ISA doc, section 8.2.3:
  //  The memory consistency model relates operations executed on memory
  //  locations with scalar data-types, which have a maximum size and alignment
  //  of 64 bits. Memory operations with a vector data-type are modelled as a
  //  set of equivalent memory operations with a scalar data-type, executed in
  //  an unspecified order on the elements in the vector.
  unsigned getMaxRequiredAlignment() const { return 8; }
  // Emulated loops with 32-bit/64-bit CAS generate better SASS than 16-bit CAS
  unsigned getMinCmpXchgSizeInBits() const { return 32; }

  unsigned getPTXVersion() const { return PTXVersion; }

  NVPTXSubtarget &initializeSubtargetDependencies(StringRef CPU, StringRef FS);
  void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef FS);

  void failIfClustersUnsupported(std::string const &FailureMessage) const;
};

} // End llvm namespace

#endif
