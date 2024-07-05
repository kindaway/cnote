cmake_minimum_required(VERSION 3.28)
project(cnote)

set(CMAKE_CXX_STANDARD 23)

add_executable(cnote main.cpp
        notes/note.h
        notes/note.cpp)
