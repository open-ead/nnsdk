set(NVN_HEADERS
  include/nv.h

  include/nvn/nvn.h
  include/nvn/nvn_Cpp.h
  include/nvn/nvn_CppFuncPtrBase.h
  include/nvn/nvn_CppMethods.h
  include/nvn/nvn_DeviceConstantsNX.h
  include/nvn/nvn_FuncPtrBase.h
  include/nvn/nvn_FuncPtrInline.h
  include/nvnTool/nvnTool_GlslcInterface.h

  src/nvn/nvn_CppFuncPtrImpl.h
  src/nvn/nvn_FuncPtrImpl.h
)

add_library(nvn OBJECT
  src/nvn/nvn_Impl.cpp
)

target_sources(nvn PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include/ src/
  FILES ${NVN_HEADERS}
)

set_target_properties(nvn PROPERTIES
  VERIFY_INTERFACE_HEADER_SETS ON
)
if(NVN_API)
  target_compile_definitions(nvn PRIVATE NVN_API_${NVN_API})
endif()

target_compile_options(nvn PRIVATE ${NNSDK_COMPILE_FLAGS})
nnsdk_header_verification_compile_options(nvn)
