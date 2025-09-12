#include "llvm/Support/Compiler.h"


/* Uses the TargetRegistry mechanism from MC library to register
 * our instance of the Target class under the Triple::h2blb enumeration
 */
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeH2BLBTargetMC() {
}

