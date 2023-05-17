set(LIBRARY_NAME CFXS_Base)

set(CMAKE_UNITY_BUILD true)
set(CMAKE_UNITY_BUILD_BATCH_SIZE 16)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

set_source_files_properties(${sources} PROPERTIES LANGUAGE CXX)

add_library(${LIBRARY_NAME} ${sources})
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_precompile_headers(
  ${LIBRARY_NAME}
  PUBLIC
  <stddef.h>
  <stdint.h>
  <stdbool.h>
  <string.h>
)

target_link_libraries(${LIBRARY_NAME} PRIVATE CFXS_Toolchain)