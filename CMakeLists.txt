cmake_minimum_required(VERSION 3.13)
project(cpSafety)

set(CMAKE_C_STANDARD 11)
include_directories(.)

add_library(xxHash
              STATIC
                src/xxHash.c
                src/xxHash.h 
                src/xxhsum.c
                src/xxhsum.h 
              )

add_executable(cpSafety
         src/main.c)

target_link_libraries(cpSafety xxHash)
