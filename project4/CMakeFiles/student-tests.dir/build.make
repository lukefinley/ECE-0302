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

# Include any dependencies generated for this target.
include CMakeFiles/student-tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/student-tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/student-tests.dir/flags.make

CMakeFiles/student-tests.dir/test_deque.cpp.o: CMakeFiles/student-tests.dir/flags.make
CMakeFiles/student-tests.dir/test_deque.cpp.o: test_deque.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luke/github-test/ECE-0302/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/student-tests.dir/test_deque.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/student-tests.dir/test_deque.cpp.o -c /home/luke/github-test/ECE-0302/project4/test_deque.cpp

CMakeFiles/student-tests.dir/test_deque.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/student-tests.dir/test_deque.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luke/github-test/ECE-0302/project4/test_deque.cpp > CMakeFiles/student-tests.dir/test_deque.cpp.i

CMakeFiles/student-tests.dir/test_deque.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/student-tests.dir/test_deque.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luke/github-test/ECE-0302/project4/test_deque.cpp -o CMakeFiles/student-tests.dir/test_deque.cpp.s

# Object files for target student-tests
student__tests_OBJECTS = \
"CMakeFiles/student-tests.dir/test_deque.cpp.o"

# External object files for target student-tests
student__tests_EXTERNAL_OBJECTS =

student-tests: CMakeFiles/student-tests.dir/test_deque.cpp.o
student-tests: CMakeFiles/student-tests.dir/build.make
student-tests: CMakeFiles/student-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luke/github-test/ECE-0302/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable student-tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/student-tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/student-tests.dir/build: student-tests

.PHONY : CMakeFiles/student-tests.dir/build

CMakeFiles/student-tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/student-tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/student-tests.dir/clean

CMakeFiles/student-tests.dir/depend:
	cd /home/luke/github-test/ECE-0302/project4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luke/github-test/ECE-0302/project4 /home/luke/github-test/ECE-0302/project4 /home/luke/github-test/ECE-0302/project4 /home/luke/github-test/ECE-0302/project4 /home/luke/github-test/ECE-0302/project4/CMakeFiles/student-tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/student-tests.dir/depend

