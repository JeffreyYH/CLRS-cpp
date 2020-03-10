cmake_minimum_required(VERSION 3.2)
project(binTree)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)
#add_subdirectory(src)
#add_subdirectory(testApp)

add_library(binTree_lib src/binTree.cpp)
add_library(linkedList_lib src/linkedList.cpp)
add_library(sorting_lib src/sorting.cpp)
#add_library(binSearch_lib src/binSearch.cpp)

add_executable(run_bintTree testApp/binTree_main.cpp)
add_executable(run_linkedList testApp/linkedList_main.cpp)
add_executable(run_sorting testApp/sorting_main.cpp)
add_executable(run_binSearch testApp/binSearch_main.cpp)

target_link_libraries(run_bintTree binTree_lib)
target_link_libraries(run_linkedList linkedList_lib)
target_link_libraries(run_sorting sorting_lib)
#target_link_libraries(run_binSearch binSearch_lib)