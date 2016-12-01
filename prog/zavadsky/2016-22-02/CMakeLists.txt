cmake_minimum_required(VERSION 3.3)
project(2016_22_02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES timetable.cpp mail.cpp merge.cpp two.cpp)
add_executable(2016_22_02 ${SOURCE_FILES})