#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/Support/Compiler.h"
#include "llvm/TargetParser/Triple.h"
#include <clang/Basic/LLVM.h>
#include <clang/Basic/LangOptions.h>
#include <optional>

namespace clang {
namespace targets {

// Hexagon abstract base class
class LLVM_LIBRARY_VISIBILITY H2BLBTargetInfo : public TargetInfo {
  public:
    H2BLBTargetInfo(const llvm::Triple &Triple, const TargetOptions &)
      : TargetInfo(Triple) {
        resetDataLayout("e-p:16:16:16-n16:32-i32:32:32-i16:16:16-i1:8:8-f32:32:32-v32:32:32");
      }

    void getTargetDefines(const LangOptions &Opts,
                          MacroBuilder &Builder) const override;

    llvm::SmallVector<Builtin::InfosShard> getTargetBuiltins() const override;

   TargetInfo::BuiltinVaListKind getBuiltinVaListKind() const override;
   bool validateAsmConstraint(const char*&, ConstraintInfo&) const override;
   std::string_view getClobbers() const override;
   llvm::ArrayRef<const char*> getGCCRegNames() const override;
   llvm::ArrayRef<clang::TargetInfo::GCCRegAlias> getGCCRegAliases() const override;

};

}
}

