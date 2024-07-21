# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProg)

# Set the C compiler to gcc
set(CMAKE_C_COMPILER gcc)

# Set the output executable name
set(TARGET myprog)

# Add source files
set(SOURCES main.c foo.c bar.c)

# Add an executable target
add_executable(${TARGET} ${SOURCES})

