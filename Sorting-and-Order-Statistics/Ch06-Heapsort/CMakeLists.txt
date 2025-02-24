cmake_minimum_required(VERSION 3.2)
set(CMAKE_BUILD_TYPE "debug")
project(heapsort)

set(CMAKE_CXX_STANDARD 17)

include_directories(../utils)
add_executable(run_heap heap_main.cpp)


