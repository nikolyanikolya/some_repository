cmake_minimum_required(VERSION 3.17)
project(5E)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Werror -DLOCAL")
add_executable(5E main.cpp)