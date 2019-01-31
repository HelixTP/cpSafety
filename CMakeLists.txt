cmake_minimum_required(VERSION 3.13)
project(cpSafety)

set(CMAKE_C_STANDARD 11)
include_directories(.)

add_executable(cpSafety
         src/main.c)
