cmake_minimum_required(VERSION 3.15)

project(NintendoSDK C CXX)
set(NINTENDOSDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(nnSdk INTERFACE)
target_sources(nnSdk PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include/
  FILES

# Run 'task configure' to update this list
# SOURCES_START


# SOURCES_END
)

set_target_properties(nnSdk PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON)

# Downstream projects should set something like:
# set(NN_SDK 4.4.0)
# set(NN_SDK_TYPE "Release")
function(nn_ver ID)
  set(VER ${${ID}})
  string(REPLACE "." ";" VER "${VER}")

  list(LENGTH VER SEGS)
  if(SEGS LESS 3)
    set(DEF_VER 1 0 0)
    list(SUBLIST DEF_VER ${SEGS} -1 DEF_VER)
    list(APPEND VER ${DEF_VER})

    message(AUTHOR_WARNING "${ID} semver is not complete (%d.%d.%d): ${${ID}}")
  endif()

  list(POP_FRONT VER MAJOR MINOR PATCH)
  
  foreach(VAR IN ITEMS MAJOR MINOR PATCH)
      target_compile_definitions(nnSdk INTERFACE ${ID}_${VAR}=${${VAR}})
  endforeach()
endfunction()
nn_ver(NN_SDK)
target_compile_definitions(nnSdk INTERFACE NN_SDK_TYPE="${NN_SDK_TYPE}")

target_include_directories(nnSdk INTERFACE include/)
target_compile_options(nnSdk INTERFACE
    -fno-strict-aliasing
    -fno-exceptions
    -Wall
    -Wextra
    -Wno-invalid-offsetof
)

add_subdirectory(lib/nvn)
add_subdirectory(lib/gfx)
