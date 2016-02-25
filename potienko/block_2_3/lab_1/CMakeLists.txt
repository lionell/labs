cmake_minimum_required(VERSION 3.2)
project(lab_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(lab_1 ${SOURCE_FILES} lexeme.h parser.h token.h BigInteger.cpp BigInteger.h token.cpp calculator.h calculator.cpp parser.cpp lexer.h lexer.cpp BigInteger.cpp BigInteger.h BigFloat.cpp BigFloat.h exceptions.h testlib.h testlib.cpp)