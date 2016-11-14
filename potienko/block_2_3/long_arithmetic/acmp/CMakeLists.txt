cmake_minimum_required(VERSION 3.2)
project(acmp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES a_multiply_b.cpp)
add_executable(acmp ${SOURCE_FILES})