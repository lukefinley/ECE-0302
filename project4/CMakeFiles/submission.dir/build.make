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
CMAKE_SOURCE_DIR = /home/luke/github-test/ECE-0302/project4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luke/github-test/ECE-0302/project4

# Utility rule file for submission.

# Include the progress variables for this target.
include CMakeFiles/submission.dir/progress.make

CMakeFiles/submission:
	/usr/bin/cmake -E tar cfv /home/luke/github-test/ECE-0302/project4/p4_pathfinder.zip --format=zip linked_list.hpp linked_list.tpp deque.hpp deque.tpp test_deque.cpp pathfinder.cpp

submission: CMakeFiles/submission
submission: CMakeFiles/submission.dir/build.make

.PHONY : submission

# Rule to build all files generated by this target.
CMakeFiles/submission.dir/build: submission

.PHONY : CMakeFiles/submission.dir/build

CMakeFiles/submission.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/submission.dir/cmake_clean.cmake
.PHONY : CMakeFiles/submission.dir/clean

CMakeFiles/submission.dir/depend:
	cd /home/luke/github-test/ECE-0302/project4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luke/github-test/ECE-0302/project4 /home/luke/github-test/ECE-0302/project4 /home/luke/github-test/ECE-0302/project4 /home/luke/github-test/ECE-0302/project4 /home/luke/github-test/ECE-0302/project4/CMakeFiles/submission.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/submission.dir/depend

