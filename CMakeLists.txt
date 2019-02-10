cmake_minimum_required(VERSION 3.10)
project(cpSafety C)

set(CMAKE_C_STANDARD 11)
find_package(Curses REQUIRED)

include_directories(src)

include_directories(${CURSES_INCLUDE_DIR})

add_executable(cpSafety
		src/main.c
		src/xxhash.c
		src/xxhash.h
		src/xxhsum.c
		src/xxhsum.h
		src/fileHash.h
		)

target_link_libraries(cpSafety ${CURSES_LIBRARIES})