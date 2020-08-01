cmake_minimum_required(VERSION 3.2)
set(CMAKE_BUILD_TYPE "debug")
project(ElementaryDataStructures)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(run_stack src/stacks_main.cpp)