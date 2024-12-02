cmake_minimum_required(VERSION 3.22)
project(lab11_e1 C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_FILES *.c)
add_library(stack ${SRC_FILES})
