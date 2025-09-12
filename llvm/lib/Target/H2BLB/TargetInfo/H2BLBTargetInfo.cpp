#include "H2BLBTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"
#include "llvm/TargetParser/Triple.h"

using namespace llvm;
Target &llvm::getTheH2BLBTarget() {
  static Target TheH2BLBTarget;
  return TheH2BLBTarget;
}

/* Uses the TargetRegistry mechanism from MC library to register
 * our instance of the Target class under the Triple::h2blb enumeration
 */
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeH2BLBTargetInfo() {
  RegisterTarget<Triple::h2blb, false> X(
      getTheH2BLBTarget(), /*Name: */ "h2blb",
      "How to build an LLVM backend by example", "H2BLB");
}
