cmake_minimum_required(VERSION 3.15)
project(InterviewBit)

set(CMAKE_CXX_STANDARD 11)

#test main
add_executable(InterviewBit main.cpp)

#array/example
add_executable(SpiralMatrix 2.Arrays/Example/SpiralMatrix.cpp)
#array/primers
add_executable(Array2D 2.Arrays/Primers/ARRAY_2D.cpp)
add_executable(ArrayBug 2.Arrays/Primers/ARRAY_BUG.cpp)
add_executable(ArrayImpl 2.Arrays/Primers/ARRAY_IMPL.cpp)
#array/math
