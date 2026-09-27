# create a project that includes all headers in nnsdk, nvn and gfx
# and try to compile that
cmake_minimum_required(VERSION 3.24)

project(NintendoSDKHeaderCheck C CXX)

set(NNSDK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)
add_subdirectory(${NNSDK_DIR} nnsdk)
get_directory_property(NNSDK_COMPILE_FLAGS DIRECTORY ${NNSDK_DIR} DEFINITION NNSDK_COMPILE_FLAGS)

set(HEADER_CHECK_TARGETS nnSdk nvn nn_gfx)
set(HEADER_CHECK_HEADERS "")
foreach(TARGET ${HEADER_CHECK_TARGETS})
  list(APPEND HEADER_CHECK_HEADERS "$<TARGET_PROPERTY:${TARGET},HEADER_SET>")
endforeach()

# header sets are evaluated at generate time, so this stays in sync with the globs
file(GENERATE
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/header_check.cpp
  CONTENT "#include \"$<JOIN:${HEADER_CHECK_HEADERS},\"\n#include \">\"\n"
)

add_library(header_check OBJECT ${CMAKE_CURRENT_BINARY_DIR}/header_check.cpp)
target_link_libraries(header_check PRIVATE ${HEADER_CHECK_TARGETS})
target_compile_options(header_check PRIVATE ${NNSDK_COMPILE_FLAGS})

# the nnc headers are C bindings, so they should also compile as C
set(HEADER_CHECK_NNC_HEADERS "$<FILTER:$<TARGET_PROPERTY:nnSdk,HEADER_SET>,INCLUDE,/include/nnc/>")
file(GENERATE
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/header_check_nnc.c
  CONTENT "#include \"$<JOIN:${HEADER_CHECK_NNC_HEADERS},\"\n#include \">\"\n"
)

add_library(header_check_nnc OBJECT ${CMAKE_CURRENT_BINARY_DIR}/header_check_nnc.c)
target_link_libraries(header_check_nnc PRIVATE nnSdk)
target_compile_options(header_check_nnc PRIVATE ${NNSDK_COMPILE_FLAGS})
