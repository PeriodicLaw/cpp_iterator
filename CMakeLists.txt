cmake_minimum_required(VERSION 3.19)
project(cpp_iterator)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(cpp_iterator INTERFACE)
target_include_directories(cpp_iterator INTERFACE include)

add_executable(vector examples/vector.cpp)
add_executable(functional examples/functional.cpp)