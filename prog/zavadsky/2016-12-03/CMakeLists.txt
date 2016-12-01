cmake_minimum_required(VERSION 3.3)
project(2016_12_03)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES fourth.cpp)
add_executable(2016_12_03 ${SOURCE_FILES})