# Creates new components name
# Used to aggregate dependencies
# Create an LLVM Component named H2BLB
add_llvm_component_group(H2BLB)

# Creates a new CMake build target 
# 
add_llvm_target(H2BLBCodeGen
  H2BLBTargetMachine.cpp

  LINK_COMPONENTS
  H2BLBDesc
  H2BLBInfo
  Support

  ADD_TO_COMPONENT
  H2BLB
)

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
