cmake_minimum_required(VERSION 3.10)
project(cpSafety C)

set(CMAKE_C_STANDARD 11)
find_package(Curses REQUIRED)

include_directories(src)

include_directories(${CURSES_INCLUDE_DIR})


ADD_LIBRARY( xxHash STATIC
		src/xxhash.c
		src/xxhash.h )

add_executable(cpSafety
		src/main.c

##		src/xxhsum.c
		src/fileHash.h
        src/main.h)

target_link_libraries(cpSafety ${CURSES_LIBRARIES} xxHash)