cmake_minimum_required(VERSION 3.27)

project(QuantityTypes)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Build tests" ON)

include(FetchContent)

FetchContent_Declare(
  NamedType
  GIT_REPOSITORY https://github.com/joboccara/NamedType.git
  GIT_TAG 76668abe09807f92a695ee5e868f9719e888e65f
)
FetchContent_MakeAvailable(NamedType)

if (BUILD_TESTS)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 # v1.14.0
)
set(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)
endif()


add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE 
                                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                           $<INSTALL_INTERFACE:include> )
target_link_libraries(${PROJECT_NAME} INTERFACE NamedType)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

include(GNUInstallDirs)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

if (BUILD_TESTS)
  add_subdirectory(tests)
endif()