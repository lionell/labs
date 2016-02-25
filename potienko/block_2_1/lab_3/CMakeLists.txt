cmake_minimum_required(VERSION 3.1)
project(lab_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(lab_3 ${SOURCE_FILES} Contour.cpp Contour.h ContourFabric.h Point.cpp Point.h Segment.cpp Segment.h debug.h debug.cpp exceptions.h iolib.h iolib.cpp share.h)