cmake_minimum_required(VERSION 3.3)
project(config)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0")

set(SOURCE_FILES1 config.cpp utils/Timer.cpp utils/Timer.h io/TablePrinter.cpp io/TablePrinter.h)
add_executable(config ${SOURCE_FILES1})
project(lab_1)

set(SOURCE_FILES main.cpp settings.h utils/Timer.cpp utils/Timer.h io/TablePrinter.cpp io/TablePrinter.h io/Postprocessor.cpp io/Postprocessor.h Benchmark.cpp Benchmark.h ops/Op.h ops/Cpp.h ops/Asm.cpp ops/Asm.h)
add_executable(lab_1 ${SOURCE_FILES})