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
include driver/CMakeFiles/MIOpenDriver.dir/depend.make

# Include the progress variables for this target.
include driver/CMakeFiles/MIOpenDriver.dir/progress.make

# Include the compile flags for this target's objects.
include driver/CMakeFiles/MIOpenDriver.dir/flags.make

driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o: driver/CMakeFiles/MIOpenDriver.dir/flags.make
driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o: ../driver/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marty/Documents/MIOpen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o"
	cd /home/marty/Documents/MIOpen/build/driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIOpenDriver.dir/main.cpp.o -c /home/marty/Documents/MIOpen/driver/main.cpp

driver/CMakeFiles/MIOpenDriver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIOpenDriver.dir/main.cpp.i"
	cd /home/marty/Documents/MIOpen/build/driver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marty/Documents/MIOpen/driver/main.cpp > CMakeFiles/MIOpenDriver.dir/main.cpp.i

driver/CMakeFiles/MIOpenDriver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIOpenDriver.dir/main.cpp.s"
	cd /home/marty/Documents/MIOpen/build/driver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marty/Documents/MIOpen/driver/main.cpp -o CMakeFiles/MIOpenDriver.dir/main.cpp.s

driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o.requires:

.PHONY : driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o.requires

driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o.provides: driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o.requires
	$(MAKE) -f driver/CMakeFiles/MIOpenDriver.dir/build.make driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o.provides.build
.PHONY : driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o.provides

driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o.provides.build: driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o


driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o: driver/CMakeFiles/MIOpenDriver.dir/flags.make
driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o: ../driver/InputFlags.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marty/Documents/MIOpen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o"
	cd /home/marty/Documents/MIOpen/build/driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o -c /home/marty/Documents/MIOpen/driver/InputFlags.cpp

driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.i"
	cd /home/marty/Documents/MIOpen/build/driver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marty/Documents/MIOpen/driver/InputFlags.cpp > CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.i

driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.s"
	cd /home/marty/Documents/MIOpen/build/driver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marty/Documents/MIOpen/driver/InputFlags.cpp -o CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.s

driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o.requires:

.PHONY : driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o.requires

driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o.provides: driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o.requires
	$(MAKE) -f driver/CMakeFiles/MIOpenDriver.dir/build.make driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o.provides.build
.PHONY : driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o.provides

driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o.provides.build: driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o


# Object files for target MIOpenDriver
MIOpenDriver_OBJECTS = \
"CMakeFiles/MIOpenDriver.dir/main.cpp.o" \
"CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o"

# External object files for target MIOpenDriver
MIOpenDriver_EXTERNAL_OBJECTS =

bin/MIOpenDriver: driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o
bin/MIOpenDriver: driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o
bin/MIOpenDriver: driver/CMakeFiles/MIOpenDriver.dir/build.make
bin/MIOpenDriver: lib/libMIOpen.so.1
bin/MIOpenDriver: /lib/libOpenCL.so
bin/MIOpenDriver: driver/CMakeFiles/MIOpenDriver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marty/Documents/MIOpen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/MIOpenDriver"
	cd /home/marty/Documents/MIOpen/build/driver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MIOpenDriver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
driver/CMakeFiles/MIOpenDriver.dir/build: bin/MIOpenDriver

.PHONY : driver/CMakeFiles/MIOpenDriver.dir/build

driver/CMakeFiles/MIOpenDriver.dir/requires: driver/CMakeFiles/MIOpenDriver.dir/main.cpp.o.requires
driver/CMakeFiles/MIOpenDriver.dir/requires: driver/CMakeFiles/MIOpenDriver.dir/InputFlags.cpp.o.requires

.PHONY : driver/CMakeFiles/MIOpenDriver.dir/requires

driver/CMakeFiles/MIOpenDriver.dir/clean:
	cd /home/marty/Documents/MIOpen/build/driver && $(CMAKE_COMMAND) -P CMakeFiles/MIOpenDriver.dir/cmake_clean.cmake
.PHONY : driver/CMakeFiles/MIOpenDriver.dir/clean

driver/CMakeFiles/MIOpenDriver.dir/depend:
	cd /home/marty/Documents/MIOpen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marty/Documents/MIOpen /home/marty/Documents/MIOpen/driver /home/marty/Documents/MIOpen/build /home/marty/Documents/MIOpen/build/driver /home/marty/Documents/MIOpen/build/driver/CMakeFiles/MIOpenDriver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : driver/CMakeFiles/MIOpenDriver.dir/depend

