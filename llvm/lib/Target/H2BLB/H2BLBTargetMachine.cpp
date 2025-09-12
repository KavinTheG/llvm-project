/*
 * Holds implementation of target-specific TargetMachine instance
 */

#include "H2BLBTargetMachine.h"
#include "TargetInfo/H2BLBTargetInfo.h" // For getTheH2BLBTarget.
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

static const char *H2BLBDataLayoutStr =
"e-p:16:16:16-n16:32-i32:32:32-i16:16:16-i1:8:8-f32:32:32-v32:32:32";

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeH2BLBTarget() {
  // Register the target so that external tools can instantiate it.
  RegisterTargetMachine<H2BLBTargetMachine> X(getTheH2BLBTarget());
}

/*
 * T: Target singleton of the backend 
 * 
 * TT: Represents the Triple object, may do something diff based on target OS etc. 
 * 
 * CPU: Represents name of CPU, may instantiate X86 backend for diff gen. of cpu's 
 *      (Diff cpu's may have different features, AVX 512 for example)
 * 
 * FS: feature string, list off diff. features constructor may want to enable/disable 
 *      (-Xclang -target-feature -Xclang +sse2,-sse) -sse would disable SSE and +sse2 enables SSE2 isntr.
 * 
 * Options: Sets default behavior for target, such as how math instructions interpreted 
 *
 * RM: relocation model for the binary, how symbols are accessed
 *  - to call foo, we may have address of foo avail directly (static mode)
 *  - otherwise, foo may be placed in memory @ runtime, 
 *      - need to rely on a dynamically populated relocation table
 *
 * CM: code model that codegen targets, tell compiler how big final binary should be
 *
 * OL: optimization level. (-O0, -O1 etc.)
 */

H2BLBTargetMachine::H2BLBTargetMachine(const Target &T, const Triple &TT,
                                       StringRef CPU, StringRef FS,
                                       const TargetOptions &Options,
                                       std::optional<Reloc::Model> RM,
                                       std::optional<CodeModel::Model> CM,
                                       CodeGenOptLevel OL,
                                       bool JIT)
    : CodeGenTargetMachineImpl(T, H2BLBDataLayoutStr, TT, CPU, FS, Options,
        // Use the simplest relocation by default
        RM ? *RM : Reloc::Static, CM ? *CM : CodeModel::Small, 
        OL) {}

H2BLBTargetMachine::~H2BLBTargetMachine() = default;

