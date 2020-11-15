cmake_minimum_required(VERSION 3.17)
project(6D)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Werror -DLOCAL")
add_executable(6D main.cpp)