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

# Utility rule file for copyover_driverreadme.

# Include the progress variables for this target.
include doc/CMakeFiles/copyover_driverreadme.dir/progress.make

doc/CMakeFiles/copyover_driverreadme:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/marty/Documents/MIOpen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying over MIOpenDriver README.md to docs folder as driver.md."
	cd /home/marty/Documents/MIOpen/build/doc && cp /home/marty/Documents/MIOpen/doc/../driver/README.md /home/marty/Documents/MIOpen/doc/src/driver.md

copyover_driverreadme: doc/CMakeFiles/copyover_driverreadme
copyover_driverreadme: doc/CMakeFiles/copyover_driverreadme.dir/build.make

.PHONY : copyover_driverreadme

# Rule to build all files generated by this target.
doc/CMakeFiles/copyover_driverreadme.dir/build: copyover_driverreadme

.PHONY : doc/CMakeFiles/copyover_driverreadme.dir/build

doc/CMakeFiles/copyover_driverreadme.dir/clean:
	cd /home/marty/Documents/MIOpen/build/doc && $(CMAKE_COMMAND) -P CMakeFiles/copyover_driverreadme.dir/cmake_clean.cmake
.PHONY : doc/CMakeFiles/copyover_driverreadme.dir/clean

doc/CMakeFiles/copyover_driverreadme.dir/depend:
	cd /home/marty/Documents/MIOpen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marty/Documents/MIOpen /home/marty/Documents/MIOpen/doc /home/marty/Documents/MIOpen/build /home/marty/Documents/MIOpen/build/doc /home/marty/Documents/MIOpen/build/doc/CMakeFiles/copyover_driverreadme.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc/CMakeFiles/copyover_driverreadme.dir/depend
