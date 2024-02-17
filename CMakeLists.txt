cmake_minimum_required(VERSION 3.27)

project(QuantityTypes)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  NamedType
  GIT_REPOSITORY https://github.com/joboccara/NamedType.git
  GIT_TAG 76668abe09807f92a695ee5e868f9719e888e65f
)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 # v1.14.0
)

FetchContent_MakeAvailable(NamedType googletest)

add_library(quantity_types INTERFACE)
target_include_directories(quantity_types INTERFACE include/ )
target_link_libraries(quantity_types INTERFACE NamedType)

add_subdirectory(tests)