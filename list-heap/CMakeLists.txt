cmake_minimum_required(VERSION 3.17)
project(list_heap)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow ")
add_executable(list_heap main.cpp doctest.h)