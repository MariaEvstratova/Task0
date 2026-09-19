cmake_minimum_required(VERSION 4.0)
project(C__)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(../0b)

add_executable(C__
        main.cpp
        sortByFrequency.cpp
        sortByFrequency.h
              )
