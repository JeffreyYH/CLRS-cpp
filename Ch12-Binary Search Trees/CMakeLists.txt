cmake_minimum_required(VERSION 3.2)
set(CMAKE_BUILD_TYPE "debug")
project(BST)

set(CMAKE_CXX_STANDARD 17)

include_directories("../Ch10-Elementary Data Structures/include/")
add_executable(run_bst main_bst.cpp)