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
CMAKE_SOURCE_DIR = /home/hadi/TDP004_labbar/lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hadi/TDP004_labbar/lab5

# Include any dependencies generated for this target.
include CMakeFiles/sorted_array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sorted_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sorted_array.dir/flags.make

CMakeFiles/sorted_array.dir/sorted_array_test.cc.o: CMakeFiles/sorted_array.dir/flags.make
CMakeFiles/sorted_array.dir/sorted_array_test.cc.o: sorted_array_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadi/TDP004_labbar/lab5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sorted_array.dir/sorted_array_test.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sorted_array.dir/sorted_array_test.cc.o -c /home/hadi/TDP004_labbar/lab5/sorted_array_test.cc

CMakeFiles/sorted_array.dir/sorted_array_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sorted_array.dir/sorted_array_test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadi/TDP004_labbar/lab5/sorted_array_test.cc > CMakeFiles/sorted_array.dir/sorted_array_test.cc.i

CMakeFiles/sorted_array.dir/sorted_array_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sorted_array.dir/sorted_array_test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadi/TDP004_labbar/lab5/sorted_array_test.cc -o CMakeFiles/sorted_array.dir/sorted_array_test.cc.s

CMakeFiles/sorted_array.dir/test_main.cc.o: CMakeFiles/sorted_array.dir/flags.make
CMakeFiles/sorted_array.dir/test_main.cc.o: test_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadi/TDP004_labbar/lab5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sorted_array.dir/test_main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sorted_array.dir/test_main.cc.o -c /home/hadi/TDP004_labbar/lab5/test_main.cc

CMakeFiles/sorted_array.dir/test_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sorted_array.dir/test_main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadi/TDP004_labbar/lab5/test_main.cc > CMakeFiles/sorted_array.dir/test_main.cc.i

CMakeFiles/sorted_array.dir/test_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sorted_array.dir/test_main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadi/TDP004_labbar/lab5/test_main.cc -o CMakeFiles/sorted_array.dir/test_main.cc.s

# Object files for target sorted_array
sorted_array_OBJECTS = \
"CMakeFiles/sorted_array.dir/sorted_array_test.cc.o" \
"CMakeFiles/sorted_array.dir/test_main.cc.o"

# External object files for target sorted_array
sorted_array_EXTERNAL_OBJECTS =

sorted_array: CMakeFiles/sorted_array.dir/sorted_array_test.cc.o
sorted_array: CMakeFiles/sorted_array.dir/test_main.cc.o
sorted_array: CMakeFiles/sorted_array.dir/build.make
sorted_array: CMakeFiles/sorted_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hadi/TDP004_labbar/lab5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sorted_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sorted_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sorted_array.dir/build: sorted_array

.PHONY : CMakeFiles/sorted_array.dir/build

CMakeFiles/sorted_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sorted_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sorted_array.dir/clean

CMakeFiles/sorted_array.dir/depend:
	cd /home/hadi/TDP004_labbar/lab5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hadi/TDP004_labbar/lab5 /home/hadi/TDP004_labbar/lab5 /home/hadi/TDP004_labbar/lab5 /home/hadi/TDP004_labbar/lab5 /home/hadi/TDP004_labbar/lab5/CMakeFiles/sorted_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sorted_array.dir/depend

