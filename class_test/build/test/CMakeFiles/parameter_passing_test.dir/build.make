# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/johnathon/Documents/cplusplus_projects/class_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johnathon/Documents/cplusplus_projects/class_test/build

# Include any dependencies generated for this target.
include test/CMakeFiles/parameter_passing_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/parameter_passing_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/parameter_passing_test.dir/flags.make

test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o: test/CMakeFiles/parameter_passing_test.dir/flags.make
test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o: ../test/parameter_passing_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnathon/Documents/cplusplus_projects/class_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o"
	cd /home/johnathon/Documents/cplusplus_projects/class_test/build/test && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o -c /home/johnathon/Documents/cplusplus_projects/class_test/test/parameter_passing_test.cpp

test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.i"
	cd /home/johnathon/Documents/cplusplus_projects/class_test/build/test && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnathon/Documents/cplusplus_projects/class_test/test/parameter_passing_test.cpp > CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.i

test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.s"
	cd /home/johnathon/Documents/cplusplus_projects/class_test/build/test && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnathon/Documents/cplusplus_projects/class_test/test/parameter_passing_test.cpp -o CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.s

test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o.requires:

.PHONY : test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o.requires

test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o.provides: test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/parameter_passing_test.dir/build.make test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o.provides

test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o.provides.build: test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o


# Object files for target parameter_passing_test
parameter_passing_test_OBJECTS = \
"CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o"

# External object files for target parameter_passing_test
parameter_passing_test_EXTERNAL_OBJECTS =

../bin/parameter_passing_test: test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o
../bin/parameter_passing_test: test/CMakeFiles/parameter_passing_test.dir/build.make
../bin/parameter_passing_test: test/CMakeFiles/parameter_passing_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johnathon/Documents/cplusplus_projects/class_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/parameter_passing_test"
	cd /home/johnathon/Documents/cplusplus_projects/class_test/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parameter_passing_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/parameter_passing_test.dir/build: ../bin/parameter_passing_test

.PHONY : test/CMakeFiles/parameter_passing_test.dir/build

test/CMakeFiles/parameter_passing_test.dir/requires: test/CMakeFiles/parameter_passing_test.dir/parameter_passing_test.cpp.o.requires

.PHONY : test/CMakeFiles/parameter_passing_test.dir/requires

test/CMakeFiles/parameter_passing_test.dir/clean:
	cd /home/johnathon/Documents/cplusplus_projects/class_test/build/test && $(CMAKE_COMMAND) -P CMakeFiles/parameter_passing_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/parameter_passing_test.dir/clean

test/CMakeFiles/parameter_passing_test.dir/depend:
	cd /home/johnathon/Documents/cplusplus_projects/class_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johnathon/Documents/cplusplus_projects/class_test /home/johnathon/Documents/cplusplus_projects/class_test/test /home/johnathon/Documents/cplusplus_projects/class_test/build /home/johnathon/Documents/cplusplus_projects/class_test/build/test /home/johnathon/Documents/cplusplus_projects/class_test/build/test/CMakeFiles/parameter_passing_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/parameter_passing_test.dir/depend
