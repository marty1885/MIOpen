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

# Include any dependencies generated for this target.
include test/CMakeFiles/test_main.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_main.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_main.dir/flags.make

test/CMakeFiles/test_main.dir/main.cpp.o: test/CMakeFiles/test_main.dir/flags.make
test/CMakeFiles/test_main.dir/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marty/Documents/MIOpen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_main.dir/main.cpp.o"
	cd /home/marty/Documents/MIOpen/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_main.dir/main.cpp.o -c /home/marty/Documents/MIOpen/test/main.cpp

test/CMakeFiles/test_main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_main.dir/main.cpp.i"
	cd /home/marty/Documents/MIOpen/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marty/Documents/MIOpen/test/main.cpp > CMakeFiles/test_main.dir/main.cpp.i

test/CMakeFiles/test_main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_main.dir/main.cpp.s"
	cd /home/marty/Documents/MIOpen/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marty/Documents/MIOpen/test/main.cpp -o CMakeFiles/test_main.dir/main.cpp.s

test/CMakeFiles/test_main.dir/main.cpp.o.requires:

.PHONY : test/CMakeFiles/test_main.dir/main.cpp.o.requires

test/CMakeFiles/test_main.dir/main.cpp.o.provides: test/CMakeFiles/test_main.dir/main.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/test_main.dir/build.make test/CMakeFiles/test_main.dir/main.cpp.o.provides.build
.PHONY : test/CMakeFiles/test_main.dir/main.cpp.o.provides

test/CMakeFiles/test_main.dir/main.cpp.o.provides.build: test/CMakeFiles/test_main.dir/main.cpp.o


# Object files for target test_main
test_main_OBJECTS = \
"CMakeFiles/test_main.dir/main.cpp.o"

# External object files for target test_main
test_main_EXTERNAL_OBJECTS =

bin/test_main: test/CMakeFiles/test_main.dir/main.cpp.o
bin/test_main: test/CMakeFiles/test_main.dir/build.make
bin/test_main: lib/libMIOpen.so.1
bin/test_main: /lib/libOpenCL.so
bin/test_main: test/CMakeFiles/test_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marty/Documents/MIOpen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test_main"
	cd /home/marty/Documents/MIOpen/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_main.dir/build: bin/test_main

.PHONY : test/CMakeFiles/test_main.dir/build

test/CMakeFiles/test_main.dir/requires: test/CMakeFiles/test_main.dir/main.cpp.o.requires

.PHONY : test/CMakeFiles/test_main.dir/requires

test/CMakeFiles/test_main.dir/clean:
	cd /home/marty/Documents/MIOpen/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_main.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_main.dir/clean

test/CMakeFiles/test_main.dir/depend:
	cd /home/marty/Documents/MIOpen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marty/Documents/MIOpen /home/marty/Documents/MIOpen/test /home/marty/Documents/MIOpen/build /home/marty/Documents/MIOpen/build/test /home/marty/Documents/MIOpen/build/test/CMakeFiles/test_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_main.dir/depend
