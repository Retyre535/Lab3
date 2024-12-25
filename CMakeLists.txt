cmake_minimum_required(VERSION 3.16)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c deque.c deque.h sorting.h sorting.c io.c io.h timer.c timer.h)