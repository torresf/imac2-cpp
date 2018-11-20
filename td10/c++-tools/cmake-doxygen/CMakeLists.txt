cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(vectorD)

# compilation flags (but should be avoided)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

# files to compile
set(src_files src/main.cpp src/VectorD.cpp)
set(header_files src/VectorD.hpp)

# compile
add_executable(vectorD ${src_files} ${header_files})

# call the CMakeLists.txt to make the documentation (Doxygen)
# > 'make html' to generate the documentation
# > the documentation is located in : [CMAKE ROOT]/build/doc/doc-doxygen/html
add_subdirectory(doc)

