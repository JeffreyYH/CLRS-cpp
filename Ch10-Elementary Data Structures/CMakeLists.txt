cmake_minimum_required(VERSION 3.2)
set(CMAKE_BUILD_TYPE "debug")
project(ElementaryDataStructures)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(run_stack src/stack_main.cpp)
add_executable(run_queue src/queue_main.cpp)
add_executable(run_linkedList_sg src/linkedList_single_main.cpp)
