# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/arya/project/simp-calc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arya/project/simp-calc

# Utility rule file for helloworld_autogen.

# Include the progress variables for this target.
include CMakeFiles/helloworld_autogen.dir/progress.make

CMakeFiles/helloworld_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arya/project/simp-calc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target helloworld"
	/usr/bin/cmake -E cmake_autogen /home/arya/project/simp-calc/CMakeFiles/helloworld_autogen.dir/AutogenInfo.json ""

helloworld_autogen: CMakeFiles/helloworld_autogen
helloworld_autogen: CMakeFiles/helloworld_autogen.dir/build.make

.PHONY : helloworld_autogen

# Rule to build all files generated by this target.
CMakeFiles/helloworld_autogen.dir/build: helloworld_autogen

.PHONY : CMakeFiles/helloworld_autogen.dir/build

CMakeFiles/helloworld_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/helloworld_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/helloworld_autogen.dir/clean

CMakeFiles/helloworld_autogen.dir/depend:
	cd /home/arya/project/simp-calc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arya/project/simp-calc /home/arya/project/simp-calc /home/arya/project/simp-calc /home/arya/project/simp-calc /home/arya/project/simp-calc/CMakeFiles/helloworld_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helloworld_autogen.dir/depend

