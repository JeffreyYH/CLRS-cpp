cmake_minimum_required(VERSION 3.2)
project(graphAlgo)

set(CMAKE_CXX_STANDARD 17)

include_directories("../utils/")
include_directories("../Advanced_Data_Structures/Disjoint_Sets/include/")
add_subdirectory(src)
