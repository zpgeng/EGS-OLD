# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/ecrc/cmake/3.21.2/ub18/bin/cmake

# The command to remove a file.
RM = /opt/ecrc/cmake/3.21.2/ub18/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gengz/gpu-v2/exageostat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gengz/gpu-v2/exageostat/build

# Utility rule file for extract_tests_data.

# Include any custom commands dependencies for this target.
include examples/CMakeFiles/extract_tests_data.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/extract_tests_data.dir/progress.make

examples/CMakeFiles/extract_tests_data: examples/synthetic_dmle_test
examples/CMakeFiles/extract_tests_data: examples/synthetic_smle_test
examples/CMakeFiles/extract_tests_data: examples/synthetic_sdmle_test
examples/CMakeFiles/extract_tests_data: examples/synthetic_dmle_locs_rwrapper_test
examples/CMakeFiles/extract_tests_data: examples/synthetic_dmle_rwrapper_test
examples/CMakeFiles/extract_tests_data: examples/real_csv_dmle_test
examples/CMakeFiles/extract_tests_data: examples/real_csv_smle_test
examples/CMakeFiles/extract_tests_data: examples/real_csv_sdmle_test
	cd /home/gengz/gpu-v2/exageostat/build/examples && cmake -E tar zxf marc-sample.tar.gz
	cd /home/gengz/gpu-v2/exageostat/build/examples && cmake -E tar zxf wind-sample.tar.gz

extract_tests_data: examples/CMakeFiles/extract_tests_data
extract_tests_data: examples/CMakeFiles/extract_tests_data.dir/build.make
.PHONY : extract_tests_data

# Rule to build all files generated by this target.
examples/CMakeFiles/extract_tests_data.dir/build: extract_tests_data
.PHONY : examples/CMakeFiles/extract_tests_data.dir/build

examples/CMakeFiles/extract_tests_data.dir/clean:
	cd /home/gengz/gpu-v2/exageostat/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/extract_tests_data.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/extract_tests_data.dir/clean

examples/CMakeFiles/extract_tests_data.dir/depend:
	cd /home/gengz/gpu-v2/exageostat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gengz/gpu-v2/exageostat /home/gengz/gpu-v2/exageostat/examples /home/gengz/gpu-v2/exageostat/build /home/gengz/gpu-v2/exageostat/build/examples /home/gengz/gpu-v2/exageostat/build/examples/CMakeFiles/extract_tests_data.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/extract_tests_data.dir/depend

