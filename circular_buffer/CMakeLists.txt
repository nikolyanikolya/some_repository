cmake_minimum_required(VERSION 3.17)
project(circular_buffer)

set(CMAKE_CXX_STANDARD 17)

add_executable(circular_buffer main.cpp doctest.h)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow  -DLOCAL")