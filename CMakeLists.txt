cmake_minimum_required(VERSION 3.10)
project(cpSafety C)

set(CMAKE_C_STANDARD 11)
#find_package(Curses REQUIRED)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	message(STATUS "Configure for windows")
	include_directories(src src/include)
endif()


#include_directories(${CURSES_INCLUDE_DIR})


ADD_LIBRARY( xxHash STATIC
		src/xxhash.c
		src/xxhash.h )

ADD_LIBRARY( fileHash STATIC
		src/fileHash.c
		src/fileHash.h )

add_executable(cpSafety
		src/main.c

        src/main.h )

#target_link_libraries(cpSafety ${CURSES_LIBRARIES} xxHash fileHash)
target_link_libraries(cpSafety xxHash fileHash)