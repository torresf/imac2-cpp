cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(plop)

# compilation flags (but should be avoided)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O2")


# compile
add_executable(plop src/main.cpp)


