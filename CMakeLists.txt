cmake_minimum_required(VERSION 3.27)
project(INF2132_P16_UAS C)

set(CMAKE_C_STANDARD 11)

add_executable(INF2132_P16_UAS main.c
        Student.h
        Course.h)
