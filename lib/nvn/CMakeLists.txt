file(GLOB_RECURSE NVN_HEADERS CONFIGURE_DEPENDS
  include/*.h
  src/*.h
)
file(GLOB_RECURSE NVN_SOURCES CONFIGURE_DEPENDS
  src/*.cpp
)

add_library(nvn OBJECT ${NVN_SOURCES})

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
