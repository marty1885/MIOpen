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

# Utility rule file for change_section_title_install.

# Include the progress variables for this target.
include doc/CMakeFiles/change_section_title_install.dir/progress.make

doc/CMakeFiles/change_section_title_install:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/marty/Documents/MIOpen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Replacing section title."
	cd /home/marty/Documents/MIOpen/build/doc && sed -e '0,/MIOpen/ s/MIOpen/Build and Install Instructions/' -i /home/marty/Documents/MIOpen/doc/src/install.md

change_section_title_install: doc/CMakeFiles/change_section_title_install
change_section_title_install: doc/CMakeFiles/change_section_title_install.dir/build.make

.PHONY : change_section_title_install

# Rule to build all files generated by this target.
doc/CMakeFiles/change_section_title_install.dir/build: change_section_title_install

.PHONY : doc/CMakeFiles/change_section_title_install.dir/build

doc/CMakeFiles/change_section_title_install.dir/clean:
	cd /home/marty/Documents/MIOpen/build/doc && $(CMAKE_COMMAND) -P CMakeFiles/change_section_title_install.dir/cmake_clean.cmake
.PHONY : doc/CMakeFiles/change_section_title_install.dir/clean

doc/CMakeFiles/change_section_title_install.dir/depend:
	cd /home/marty/Documents/MIOpen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marty/Documents/MIOpen /home/marty/Documents/MIOpen/doc /home/marty/Documents/MIOpen/build /home/marty/Documents/MIOpen/build/doc /home/marty/Documents/MIOpen/build/doc/CMakeFiles/change_section_title_install.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc/CMakeFiles/change_section_title_install.dir/depend
