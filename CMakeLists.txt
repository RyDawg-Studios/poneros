cmake_minimum_required(VERSION 3.14)
project(poneros)

# Executable
add_executable(poneros src/main.cpp)

# Library
include_directories(include)
link_directories(lib)


