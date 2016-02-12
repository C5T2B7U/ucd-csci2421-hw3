cmake_minimum_required(VERSION 3.3)
project(6936HW3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    mystring.cpp
    mystring.h main.cpp)

add_executable(6936HW3 ${SOURCE_FILES})