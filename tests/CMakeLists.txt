cmake_minimum_required(VERSION 3.27)

enable_testing()

add_executable(quantity_types_tests length_tests.cpp 
                                    duration_tests.cpp 
                                    angle_tests.cpp
                                    speed_tests.cpp
                                    acceleration_tests.cpp)

target_link_libraries(quantity_types_tests PUBLIC GTest::gtest_main ${PROJECT_NAME})

target_compile_options(quantity_types_tests INTERFACE
  "$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-Wpedantic;-Wc++17-compat>")

include(GoogleTest)
gtest_discover_tests(quantity_types_tests)

install(TARGETS quantity_types_tests DESTINATION ${CMAKE_INSTALL_PREFIX}/tests)