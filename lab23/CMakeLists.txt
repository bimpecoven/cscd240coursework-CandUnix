cmake_minimum_required(VERSION 3.3)
project(lab23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    cscd240lab23.c
    lab23.c
    lab23.h
    myUtils.c
    myUtils.h)

add_executable(lab23 ${SOURCE_FILES})