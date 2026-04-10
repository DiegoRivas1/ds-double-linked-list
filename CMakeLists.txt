cmake_minimum_required(VERSION 4.1)
project(ds_double_linked_list)

set(CMAKE_CXX_STANDARD 20)

#include_directories(include)
include_directories(source)
#Nuestero ejecutalke principal
add_executable(ds_double_linked_list main.cpp)
target_include_directories(ds_double_linked_list PRIVATE include)

# TEST
find_package(GTest REQUIRED)
enable_testing()

###
#Test Nodo
add_executable(test_node
        test/Node/NodeTest.cpp)

target_include_directories(test_node PRIVATE include)
target_link_libraries(test_node GTest::gtest GTest::gtest_main)
add_test(NAME NodeTest COMMAND test_node)

