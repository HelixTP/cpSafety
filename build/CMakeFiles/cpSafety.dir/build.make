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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lad/workspaces/cpSafety

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lad/workspaces/cpSafety/build

# Include any dependencies generated for this target.
include CMakeFiles/cpSafety.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpSafety.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpSafety.dir/flags.make

CMakeFiles/cpSafety.dir/src/main.c.o: CMakeFiles/cpSafety.dir/flags.make
CMakeFiles/cpSafety.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lad/workspaces/cpSafety/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cpSafety.dir/src/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpSafety.dir/src/main.c.o   -c /Users/lad/workspaces/cpSafety/src/main.c

CMakeFiles/cpSafety.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpSafety.dir/src/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lad/workspaces/cpSafety/src/main.c > CMakeFiles/cpSafety.dir/src/main.c.i

CMakeFiles/cpSafety.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpSafety.dir/src/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lad/workspaces/cpSafety/src/main.c -o CMakeFiles/cpSafety.dir/src/main.c.s

# Object files for target cpSafety
cpSafety_OBJECTS = \
"CMakeFiles/cpSafety.dir/src/main.c.o"

# External object files for target cpSafety
cpSafety_EXTERNAL_OBJECTS =

cpSafety: CMakeFiles/cpSafety.dir/src/main.c.o
cpSafety: CMakeFiles/cpSafety.dir/build.make
cpSafety: libxxHash.a
cpSafety: CMakeFiles/cpSafety.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lad/workspaces/cpSafety/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cpSafety"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpSafety.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpSafety.dir/build: cpSafety

.PHONY : CMakeFiles/cpSafety.dir/build

CMakeFiles/cpSafety.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpSafety.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpSafety.dir/clean

CMakeFiles/cpSafety.dir/depend:
	cd /Users/lad/workspaces/cpSafety/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lad/workspaces/cpSafety /Users/lad/workspaces/cpSafety /Users/lad/workspaces/cpSafety/build /Users/lad/workspaces/cpSafety/build /Users/lad/workspaces/cpSafety/build/CMakeFiles/cpSafety.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpSafety.dir/depend

