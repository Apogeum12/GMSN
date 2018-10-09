cmake_minimum_required (VERSION 3.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(maxout)

set(CMAKE_BINARY_DIR "bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


add_executable (
maxout
"main.cpp"
"ReadGet/ReadData.cpp"
"Matrix.cpp"
"MaxOutUnit.cpp"
"utils/MultiplyMatrix.cpp"
"MaxMinVec.cpp"
"MaxOutNet.cpp"
)

