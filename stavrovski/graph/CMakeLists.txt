cmake_minimum_required(VERSION 3.2)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp graph.cpp graph.h)
add_executable(graph ${SOURCE_FILES})