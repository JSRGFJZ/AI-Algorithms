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
CMAKE_SOURCE_DIR = /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/build

# Include any dependencies generated for this target.
include CMakeFiles/svm_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/svm_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/svm_test.dir/flags.make

CMakeFiles/svm_test.dir/svm_test.cpp.o: CMakeFiles/svm_test.dir/flags.make
CMakeFiles/svm_test.dir/svm_test.cpp.o: ../svm_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/svm_test.dir/svm_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/svm_test.dir/svm_test.cpp.o -c /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/svm_test.cpp

CMakeFiles/svm_test.dir/svm_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/svm_test.dir/svm_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/svm_test.cpp > CMakeFiles/svm_test.dir/svm_test.cpp.i

CMakeFiles/svm_test.dir/svm_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/svm_test.dir/svm_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/svm_test.cpp -o CMakeFiles/svm_test.dir/svm_test.cpp.s

CMakeFiles/svm_test.dir/svm_test.cpp.o.requires:

.PHONY : CMakeFiles/svm_test.dir/svm_test.cpp.o.requires

CMakeFiles/svm_test.dir/svm_test.cpp.o.provides: CMakeFiles/svm_test.dir/svm_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/svm_test.dir/build.make CMakeFiles/svm_test.dir/svm_test.cpp.o.provides.build
.PHONY : CMakeFiles/svm_test.dir/svm_test.cpp.o.provides

CMakeFiles/svm_test.dir/svm_test.cpp.o.provides.build: CMakeFiles/svm_test.dir/svm_test.cpp.o


# Object files for target svm_test
svm_test_OBJECTS = \
"CMakeFiles/svm_test.dir/svm_test.cpp.o"

# External object files for target svm_test
svm_test_EXTERNAL_OBJECTS =

svm_test: CMakeFiles/svm_test.dir/svm_test.cpp.o
svm_test: CMakeFiles/svm_test.dir/build.make
svm_test: lib_svm_test_svm_lib.a
svm_test: CMakeFiles/svm_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable svm_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/svm_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/svm_test.dir/build: svm_test

.PHONY : CMakeFiles/svm_test.dir/build

CMakeFiles/svm_test.dir/requires: CMakeFiles/svm_test.dir/svm_test.cpp.o.requires

.PHONY : CMakeFiles/svm_test.dir/requires

CMakeFiles/svm_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/svm_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/svm_test.dir/clean

CMakeFiles/svm_test.dir/depend:
	cd /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/build /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/build /home/jean/Documents/AI-Algorithms/pattern_recognization/svm/SVM_example/build/CMakeFiles/svm_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/svm_test.dir/depend

