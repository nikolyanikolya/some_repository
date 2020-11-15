cmake_minimum_required(VERSION 3.17)
project(3A)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
add_executable(3A main.cpp optimization.h)