# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marty/Documents/MIOpen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marty/Documents/MIOpen/build

# Utility rule file for NightlyMemoryCheck.

# Include the progress variables for this target.
include test/CMakeFiles/NightlyMemoryCheck.dir/progress.make

test/CMakeFiles/NightlyMemoryCheck:
	cd /home/marty/Documents/MIOpen/build/test && /usr/bin/ctest -D NightlyMemoryCheck

NightlyMemoryCheck: test/CMakeFiles/NightlyMemoryCheck
NightlyMemoryCheck: test/CMakeFiles/NightlyMemoryCheck.dir/build.make

.PHONY : NightlyMemoryCheck

# Rule to build all files generated by this target.
test/CMakeFiles/NightlyMemoryCheck.dir/build: NightlyMemoryCheck

.PHONY : test/CMakeFiles/NightlyMemoryCheck.dir/build

test/CMakeFiles/NightlyMemoryCheck.dir/clean:
	cd /home/marty/Documents/MIOpen/build/test && $(CMAKE_COMMAND) -P CMakeFiles/NightlyMemoryCheck.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/NightlyMemoryCheck.dir/clean

test/CMakeFiles/NightlyMemoryCheck.dir/depend:
	cd /home/marty/Documents/MIOpen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marty/Documents/MIOpen /home/marty/Documents/MIOpen/test /home/marty/Documents/MIOpen/build /home/marty/Documents/MIOpen/build/test /home/marty/Documents/MIOpen/build/test/CMakeFiles/NightlyMemoryCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/NightlyMemoryCheck.dir/depend

