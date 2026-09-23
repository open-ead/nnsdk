cmake_minimum_required(VERSION 3.15)

# note that nn_gfx includes the C impl
set(NVN_API "C" CACHE STRING "Set NVN platform type")
set_property(CACHE NVN_API PROPERTY STRINGS "C" "CPP")

target_sources(nvn PUBLIC
  FILE_SET HEADERS
  BASE_DIRS ${NINTENDOSDK_PATH}/include/ src/nvn/
  FILES

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

set_target_properties(nvn PROPERTIES
    LINKER_LANGUAGE CXX
    VERIFY_INTERFACE_HEADER_SETS ON
)
if (NVN_API)
  target_compile_definitions(nvn PUBLIC NVN_API_${NVN_API})
endif()

target_include_directories(nvn PUBLIC include)
target_include_directories(nvn PUBLIC src)
