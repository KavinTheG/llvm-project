#include "H2BLB.h"

#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"
#include "llvm/ADT/StringSwitch.h"

using namespace clang;
using namespace clang::targets;

void H2BLBTargetInfo::getTargetDefines(const LangOptions &Opts,
                                         MacroBuilder &Builder) const {
    Builder.defineMacro("__H2BLB__");
}

TargetInfo::BuiltinVaListKind H2BLBTargetInfo::getBuiltinVaListKind() const {
  return TargetInfo::VoidPtrBuiltinVaList;
}

bool H2BLBTargetInfo::validateAsmConstraint(const char*&, ConstraintInfo&) const {
  return false;
}

std::string_view H2BLBTargetInfo::getClobbers() const {
  return "";
}

llvm::ArrayRef<const char*> H2BLBTargetInfo::getGCCRegNames() const {
  return {};
}

llvm::ArrayRef<clang::TargetInfo::GCCRegAlias>
H2BLBTargetInfo::getGCCRegAliases() const {
  return {};
}



llvm::SmallVector<Builtin::InfosShard> 
H2BLBTargetInfo::getTargetBuiltins() const {
  return {};
}



