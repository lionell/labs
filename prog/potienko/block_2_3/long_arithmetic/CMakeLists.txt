cmake_minimum_required(VERSION 3.2)
project(long_arithmetic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(long_arithmetic ${SOURCE_FILES} BigInteger.cpp BigInteger.h BigFloat.cpp BigFloat.h exceptions.h)