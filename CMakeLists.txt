cmake_minimum_required(VERSION 3.9)
project(TODO)

set(CMAKE_CXX_STANDARD 11)

add_executable(TODO main.cpp Task.h Task.cpp TaskManager.cpp TaskManager.h)