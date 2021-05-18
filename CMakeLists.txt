cmake_minimum_required(VERSION 3.19)
project(rubiks_cube C)

set(CMAKE_C_STANDARD 99)

add_executable(rubiks_cube conio.c main.c rubiks.h rubiks.c)