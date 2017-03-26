cmake_minimum_required(VERSION 3.6)
project(anpi-pol)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/muller.h)


add_executable(anpi-pol ${SOURCE_FILES})