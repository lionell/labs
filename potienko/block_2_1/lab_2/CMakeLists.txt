cmake_minimum_required(VERSION 3.1)
project(lab_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(lab_2 ${SOURCE_FILES} Contour.cpp Contour.h Point.cpp Point.h Segment.cpp Segment.h iolib.h iolib.cpp share.h exceptions.h debug.h debug.cpp Contour.cpp Contour.h Segment.cpp Segment.h debug.h debug.cpp exceptions.h iolib.h iolib.cpp share.h ContourFabric.h)