cmake_minimum_required(VERSION 3.2)
set(CMAKE_BUILD_TYPE "debug")
project(dsalgo)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
#add_subdirectory(testApp)

add_executable(run_bintTree testApp/binTree_main.cpp)
add_executable(run_linkedList testApp/linkedList_main.cpp)
add_executable(run_sorting testApp/sorting_main.cpp)
add_executable(run_binSearch testApp/search_main.cpp)
add_executable(run_heap testApp/heap_main.cpp)


