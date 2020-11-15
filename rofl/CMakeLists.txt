cmake_minimum_required(VERSION 3.17)
project(rofl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Werror -DLOCAL")
add_executable(rofl "main.cpp")
