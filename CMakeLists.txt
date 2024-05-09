cmake_minimum_required(VERSION 3.11)

project(noname)

add_subdirectory(lib)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PUBLIC libdasmenschcommon)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/lib"
)
