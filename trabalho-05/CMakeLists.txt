cmake_minimum_required(VERSION 3.26)
project(trabalho_05 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(trabalho_05
        list.c
        list.h
        main.c
        tree.c
        tree.h
        resources.c)
