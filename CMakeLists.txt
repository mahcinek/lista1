cmake_minimum_required(VERSION 3.6)
project(lista1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp  CTable.cpp Osoba.cpp Osoba.h)
add_executable(lista1 ${SOURCE_FILES})
