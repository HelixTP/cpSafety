# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/denislallemand/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-1/191.6183.6/CLion 2019.1 EAP.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/denislallemand/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-1/191.6183.6/CLion 2019.1 EAP.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/data/workspaces/cpSafety

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/data/workspaces/cpSafety/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/xxHash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xxHash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xxHash.dir/flags.make

CMakeFiles/xxHash.dir/src/xxhash.c.o: CMakeFiles/xxHash.dir/flags.make
CMakeFiles/xxHash.dir/src/xxhash.c.o: ../src/xxhash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/data/workspaces/cpSafety/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/xxHash.dir/src/xxhash.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xxHash.dir/src/xxhash.c.o   -c /Volumes/data/workspaces/cpSafety/src/xxhash.c

CMakeFiles/xxHash.dir/src/xxhash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xxHash.dir/src/xxhash.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Volumes/data/workspaces/cpSafety/src/xxhash.c > CMakeFiles/xxHash.dir/src/xxhash.c.i

CMakeFiles/xxHash.dir/src/xxhash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xxHash.dir/src/xxhash.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Volumes/data/workspaces/cpSafety/src/xxhash.c -o CMakeFiles/xxHash.dir/src/xxhash.c.s

# Object files for target xxHash
xxHash_OBJECTS = \
"CMakeFiles/xxHash.dir/src/xxhash.c.o"

# External object files for target xxHash
xxHash_EXTERNAL_OBJECTS =

libxxHash.a: CMakeFiles/xxHash.dir/src/xxhash.c.o
libxxHash.a: CMakeFiles/xxHash.dir/build.make
libxxHash.a: CMakeFiles/xxHash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/data/workspaces/cpSafety/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libxxHash.a"
	$(CMAKE_COMMAND) -P CMakeFiles/xxHash.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xxHash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xxHash.dir/build: libxxHash.a

.PHONY : CMakeFiles/xxHash.dir/build

CMakeFiles/xxHash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xxHash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xxHash.dir/clean

CMakeFiles/xxHash.dir/depend:
	cd /Volumes/data/workspaces/cpSafety/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/data/workspaces/cpSafety /Volumes/data/workspaces/cpSafety /Volumes/data/workspaces/cpSafety/cmake-build-debug /Volumes/data/workspaces/cpSafety/cmake-build-debug /Volumes/data/workspaces/cpSafety/cmake-build-debug/CMakeFiles/xxHash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xxHash.dir/depend

