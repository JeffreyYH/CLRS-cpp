cmake_minimum_required(VERSION 3.2)
set(CMAKE_BUILD_TYPE "debug")
project(HashTable)

include_directories("../Ch10-Elementary Data Structures/include/")
set(CMAKE_CXX_STANDARD 17)
add_executable(run_hashTable main_hashtable.cpp)