cmake_minimum_required(VERSION 3.10)
project(cpSafety C)

set(CMAKE_C_STANDARD 11)
#find_package(Curses REQUIRED)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	message(STATUS "Configure for windows")
	include_directories(src src/include)
endif()

## test Endian

include (TestBigEndian)
TEST_BIG_ENDIAN(IS_BIG_ENDIAN)
if(IS_BIG_ENDIAN)
	message(STATUS "BIG_ENDIAN")
else()
	message(STATUS "LITTLE_ENDIAN")
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

        src/main.h src/tools.c src/tools.h)

#target_link_libraries(cpSafety ${CURSES_LIBRARIES} xxHash fileHash)
target_link_libraries(cpSafety xxHash fileHash)