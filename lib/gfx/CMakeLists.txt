file(GLOB_RECURSE NN_GFX_HEADERS CONFIGURE_DEPENDS
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  include/*.h
)
file(GLOB_RECURSE NN_GFX_SOURCES CONFIGURE_DEPENDS
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  src/*.cpp
  src/*.h
)

# NVN-specific files that don't have .nvn in the name
set(NN_GFX_NVN_EXTRA_SOURCES
  src/gfx/detail/gfx_GlslcFunction.cpp
  src/gfx/detail/gfx_NvnHelper-os.horizon.cpp
  src/gfx/detail/gfx_NvnHelper.cpp
  src/gfx/detail/gfx_NvnHelper.h
)
list(REMOVE_ITEM NN_GFX_SOURCES ${NN_GFX_NVN_EXTRA_SOURCES})

set(NN_GFX_NVN_HEADERS ${NN_GFX_HEADERS})
list(FILTER NN_GFX_NVN_HEADERS INCLUDE REGEX "\\.nvn")
list(FILTER NN_GFX_HEADERS EXCLUDE REGEX "\\.nvn")
set(NN_GFX_NVN_SOURCES ${NN_GFX_SOURCES})
list(FILTER NN_GFX_NVN_SOURCES INCLUDE REGEX "\\.nvn")
list(FILTER NN_GFX_SOURCES EXCLUDE REGEX "\\.nvn")
list(APPEND NN_GFX_NVN_SOURCES ${NN_GFX_NVN_EXTRA_SOURCES})

if(NN_GFX_TARGET STREQUAL "NVN")
  list(APPEND NN_GFX_HEADERS ${NN_GFX_NVN_HEADERS})
  list(APPEND NN_GFX_SOURCES ${NN_GFX_NVN_SOURCES})
endif()

add_library(nn_gfx STATIC ${NN_GFX_SOURCES})

target_sources(nn_gfx PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include/
  FILES ${NN_GFX_HEADERS}
)

set_target_properties(nn_gfx PROPERTIES
  VERIFY_INTERFACE_HEADER_SETS ON
)

target_compile_options(nn_gfx PRIVATE ${NNSDK_COMPILE_FLAGS})
nnsdk_header_verification_compile_options(nn_gfx)

if(NN_GFX_TARGET STREQUAL "NVN")
  target_link_libraries(nn_gfx PUBLIC nvn)
endif()

target_link_libraries(nn_gfx PUBLIC nnSdk)
