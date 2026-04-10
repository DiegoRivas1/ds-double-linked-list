cmake_minimum_required(VERSION 4.1)
project(ds_double_linked_list)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

#Nuestero ejecutalke principal
add_executable(ds_double_linked_list main.cpp)


# TEST
find_package(GTest REQUIRED)
enable_testing()

#Test Nodo
add_executable(test_node
        test/Node/NodeTest.cpp)

#target_include_directories(ds_linked_list_test PRIVATE include)
target_link_libraries(test_node GTest::gtest GTest::gtest_main)
add_test(NAME NodeTest COMMAND test_node)

