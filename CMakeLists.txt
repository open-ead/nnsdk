cmake_minimum_required(VERSION 3.24)

project(NintendoSDK C CXX)

set(NVN_API "C" CACHE STRING "Set NVN platform type")
set_property(CACHE NVN_API PROPERTY STRINGS "C" "CPP")
set(NN_GFX_TARGET "NVN" CACHE STRING "Set nn::gfx build target")
set_property(CACHE NN_GFX_TARGET PROPERTY STRINGS "" "NVN")
if(NN_GFX_TARGET STREQUAL "NVN" AND NVN_API STREQUAL "C")
  set(NVN_API "")
endif()

file(GLOB_RECURSE NNSDK_HEADERS CONFIGURE_DEPENDS
  include/*.h
  include/*.hpp # vapours has some hpp headers
)
add_library(nnSdk INTERFACE)
target_sources(nnSdk INTERFACE
  FILE_SET HEADERS
  BASE_DIRS include/
  FILES ${NNSDK_HEADERS}
)

set_target_properties(nnSdk PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON)

# Downstream projects should set something like:
# set(NN_SDK 4.4.0)
# set(NN_SDK_TYPE "Release")
function(nnsdk_ver ID)
  set(VER ${${ID}})
  string(REPLACE "." ";" VER "${VER}")

  list(LENGTH VER SEGS)
  if(SEGS LESS 3)
    set(DEF_VER 1 0 0)
    list(SUBLIST DEF_VER ${SEGS} -1 DEF_VER)
    list(APPEND VER ${DEF_VER})

    message(AUTHOR_WARNING "${ID} semver is malformed (should be %d.%d.%d): ${${ID}}")
  endif()

  list(POP_FRONT VER MAJOR MINOR PATCH)
  
  foreach(VAR IN ITEMS MAJOR MINOR PATCH)
      target_compile_definitions(nnSdk INTERFACE ${ID}_${VAR}=${${VAR}})
  endforeach()
endfunction()
nnsdk_ver(NN_SDK)
target_compile_definitions(nnSdk INTERFACE NN_SDK_TYPE="${NN_SDK_TYPE}")

# these flags are shared with modules (e.g. gfx, nvn)
set(NNSDK_COMPILE_FLAGS
  -fno-strict-aliasing
  -fno-exceptions
  -Wall
  -Wextra
  -Wno-invalid-offsetof
)
function(nnsdk_header_verification_compile_options TARGET)
  target_compile_options(${TARGET} INTERFACE
    "$<$<STREQUAL:$<TARGET_PROPERTY:NAME>,${TARGET}_verify_interface_header_sets>:${NNSDK_COMPILE_FLAGS}>"
  )
endfunction()
# note we do not define flags directly on nnSdk target,
# since as an INTERFACE target we cannot define PRIVATE flags
nnsdk_header_verification_compile_options(nnSdk)

add_subdirectory(lib/gfx)
add_subdirectory(lib/nvn)
