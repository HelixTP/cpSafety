cmake_minimum_required(VERSION 3.10)
project(cpSafety C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(cpSafety
		src/main.c
		src/xxhash.c
		src/xxhash.h
		src/xxhsum.c
		src/xxhsum.h)
