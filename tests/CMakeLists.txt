cmake_minimum_required(VERSION 3.27)

enable_testing()

add_executable(quantity_types_tests length_tests.cpp 
                                    duration_tests.cpp 
                                    angle_tests.cpp
                                    speed_tests.cpp)

target_link_libraries(quantity_types_tests PUBLIC GTest::gtest_main quantity_types)

include(GoogleTest)
gtest_discover_tests(quantity_types_tests)