cmake_minimum_required(VERSION 2.8.4)
project(Lab_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Lab_1/lab_1.cpp)
add_executable(AOS Lab_1 ${SOURCE_FILES})