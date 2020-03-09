cmake_minimum_required(VERSION 3.2)
project(binTree)

set(CMAKE_CXX_STANDARD 11)

add_library(binTree_lib binTree.cpp)
add_executable(run main.cpp)
target_link_libraries(run binTree_lib)