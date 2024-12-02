cmake_minimum_required(VERSION 3.22)
project(lab10_stack C)

set(CMAKE_C_STANDARD 99)

file(COPY_FILE lib_item/item.h item.h)
file(COPY_FILE lib_item/item-int.c item.c)
add_subdirectory(lib_stack)

add_executable(lab10_stack client.c item.c)
target_link_libraries(lab10_stack stack)
target_link_libraries(lab10_stack m)
