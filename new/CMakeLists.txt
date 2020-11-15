cmake_minimum_required(VERSION 3.17)
project(new)

set(CMAKE_CXX_STANDARD 14)

add_executable(new src/main.cpp include/algo.h src/alg.cpp)
target_include_directories(main PUBLIC /include)