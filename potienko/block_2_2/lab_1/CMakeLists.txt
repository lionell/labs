cmake_minimum_required(VERSION 3.1)
project(lab_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(lab_1 ${SOURCE_FILES} Wagon.cpp Wagon.h Train.cpp Train.h Station.cpp Station.h testlib.h testlib.cpp testutils.h testutils.cpp)