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
CMAKE_SOURCE_DIR = /home/johnathon/Documents/cplusplus_projects/data_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johnathon/Documents/cplusplus_projects/data_test/build

# Include any dependencies generated for this target.
include test/CMakeFiles/pointer_string_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/pointer_string_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/pointer_string_test.dir/flags.make

test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o: test/CMakeFiles/pointer_string_test.dir/flags.make
test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o: ../test/pointer_string_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnathon/Documents/cplusplus_projects/data_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o"
	cd /home/johnathon/Documents/cplusplus_projects/data_test/build/test && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o -c /home/johnathon/Documents/cplusplus_projects/data_test/test/pointer_string_test.cpp

test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.i"
	cd /home/johnathon/Documents/cplusplus_projects/data_test/build/test && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnathon/Documents/cplusplus_projects/data_test/test/pointer_string_test.cpp > CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.i

test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.s"
	cd /home/johnathon/Documents/cplusplus_projects/data_test/build/test && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnathon/Documents/cplusplus_projects/data_test/test/pointer_string_test.cpp -o CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.s

test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o.requires:

.PHONY : test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o.requires

test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o.provides: test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/pointer_string_test.dir/build.make test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o.provides

test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o.provides.build: test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o


# Object files for target pointer_string_test
pointer_string_test_OBJECTS = \
"CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o"

# External object files for target pointer_string_test
pointer_string_test_EXTERNAL_OBJECTS =

../bin/pointer_string_test: test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o
../bin/pointer_string_test: test/CMakeFiles/pointer_string_test.dir/build.make
../bin/pointer_string_test: test/CMakeFiles/pointer_string_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johnathon/Documents/cplusplus_projects/data_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/pointer_string_test"
	cd /home/johnathon/Documents/cplusplus_projects/data_test/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pointer_string_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/pointer_string_test.dir/build: ../bin/pointer_string_test

.PHONY : test/CMakeFiles/pointer_string_test.dir/build

test/CMakeFiles/pointer_string_test.dir/requires: test/CMakeFiles/pointer_string_test.dir/pointer_string_test.cpp.o.requires

.PHONY : test/CMakeFiles/pointer_string_test.dir/requires

test/CMakeFiles/pointer_string_test.dir/clean:
	cd /home/johnathon/Documents/cplusplus_projects/data_test/build/test && $(CMAKE_COMMAND) -P CMakeFiles/pointer_string_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/pointer_string_test.dir/clean

test/CMakeFiles/pointer_string_test.dir/depend:
	cd /home/johnathon/Documents/cplusplus_projects/data_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johnathon/Documents/cplusplus_projects/data_test /home/johnathon/Documents/cplusplus_projects/data_test/test /home/johnathon/Documents/cplusplus_projects/data_test/build /home/johnathon/Documents/cplusplus_projects/data_test/build/test /home/johnathon/Documents/cplusplus_projects/data_test/build/test/CMakeFiles/pointer_string_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/pointer_string_test.dir/depend

