cmake_minimum_required(VERSION 3.1)
project(RadioTest_Sender)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(RadioTest_Sender ${SOURCE_FILES})