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

# Include any dependencies generated for this target.
include examples/CMakeFiles/synthetic_sdmle_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/synthetic_sdmle_test.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/synthetic_sdmle_test.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/synthetic_sdmle_test.dir/flags.make

examples/CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o: examples/CMakeFiles/synthetic_sdmle_test.dir/flags.make
examples/CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o: ../examples/synthetic_sdmle_test.c
examples/CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o: examples/CMakeFiles/synthetic_sdmle_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gengz/gpu-v2/exageostat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o"
	cd /home/gengz/gpu-v2/exageostat/build/examples && /opt/ecrc/gcc/10.2.0/ub18/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o -MF CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o.d -o CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o -c /home/gengz/gpu-v2/exageostat/examples/synthetic_sdmle_test.c

examples/CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.i"
	cd /home/gengz/gpu-v2/exageostat/build/examples && /opt/ecrc/gcc/10.2.0/ub18/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gengz/gpu-v2/exageostat/examples/synthetic_sdmle_test.c > CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.i

examples/CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.s"
	cd /home/gengz/gpu-v2/exageostat/build/examples && /opt/ecrc/gcc/10.2.0/ub18/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gengz/gpu-v2/exageostat/examples/synthetic_sdmle_test.c -o CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.s

examples/CMakeFiles/synthetic_sdmle_test.dir/examples.c.o: examples/CMakeFiles/synthetic_sdmle_test.dir/flags.make
examples/CMakeFiles/synthetic_sdmle_test.dir/examples.c.o: ../examples/examples.c
examples/CMakeFiles/synthetic_sdmle_test.dir/examples.c.o: examples/CMakeFiles/synthetic_sdmle_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gengz/gpu-v2/exageostat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/synthetic_sdmle_test.dir/examples.c.o"
	cd /home/gengz/gpu-v2/exageostat/build/examples && /opt/ecrc/gcc/10.2.0/ub18/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/synthetic_sdmle_test.dir/examples.c.o -MF CMakeFiles/synthetic_sdmle_test.dir/examples.c.o.d -o CMakeFiles/synthetic_sdmle_test.dir/examples.c.o -c /home/gengz/gpu-v2/exageostat/examples/examples.c

examples/CMakeFiles/synthetic_sdmle_test.dir/examples.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/synthetic_sdmle_test.dir/examples.c.i"
	cd /home/gengz/gpu-v2/exageostat/build/examples && /opt/ecrc/gcc/10.2.0/ub18/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gengz/gpu-v2/exageostat/examples/examples.c > CMakeFiles/synthetic_sdmle_test.dir/examples.c.i

examples/CMakeFiles/synthetic_sdmle_test.dir/examples.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/synthetic_sdmle_test.dir/examples.c.s"
	cd /home/gengz/gpu-v2/exageostat/build/examples && /opt/ecrc/gcc/10.2.0/ub18/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gengz/gpu-v2/exageostat/examples/examples.c -o CMakeFiles/synthetic_sdmle_test.dir/examples.c.s

# Object files for target synthetic_sdmle_test
synthetic_sdmle_test_OBJECTS = \
"CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o" \
"CMakeFiles/synthetic_sdmle_test.dir/examples.c.o"

# External object files for target synthetic_sdmle_test
synthetic_sdmle_test_EXTERNAL_OBJECTS =

examples/synthetic_sdmle_test: examples/CMakeFiles/synthetic_sdmle_test.dir/synthetic_sdmle_test.c.o
examples/synthetic_sdmle_test: examples/CMakeFiles/synthetic_sdmle_test.dir/examples.c.o
examples/synthetic_sdmle_test: examples/CMakeFiles/synthetic_sdmle_test.dir/build.make
examples/synthetic_sdmle_test: /opt/ecrc/cuda/11.4/lib64/libcudart_static.a
examples/synthetic_sdmle_test: /usr/lib/x86_64-linux-gnu/librt.so
examples/synthetic_sdmle_test: libexageostat.a
examples/synthetic_sdmle_test: /opt/ecrc/cuda/11.4/lib64/libcudart_static.a
examples/synthetic_sdmle_test: /opt/ecrc/mkl/2020.0.166/mkl/lib/intel64/libmkl_intel_lp64.so
examples/synthetic_sdmle_test: /opt/ecrc/mkl/2020.0.166/mkl/lib/intel64/libmkl_sequential.so
examples/synthetic_sdmle_test: /opt/ecrc/mkl/2020.0.166/mkl/lib/intel64/libmkl_core.so
examples/synthetic_sdmle_test: ../installdir/lib/libgsl.so
examples/synthetic_sdmle_test: ../installdir/lib/libgslcblas.so
examples/synthetic_sdmle_test: /usr/lib/x86_64-linux-gnu/libm.so
examples/synthetic_sdmle_test: /usr/lib/x86_64-linux-gnu/librt.so
examples/synthetic_sdmle_test: examples/CMakeFiles/synthetic_sdmle_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gengz/gpu-v2/exageostat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable synthetic_sdmle_test"
	cd /home/gengz/gpu-v2/exageostat/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/synthetic_sdmle_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/synthetic_sdmle_test.dir/build: examples/synthetic_sdmle_test
.PHONY : examples/CMakeFiles/synthetic_sdmle_test.dir/build

examples/CMakeFiles/synthetic_sdmle_test.dir/clean:
	cd /home/gengz/gpu-v2/exageostat/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/synthetic_sdmle_test.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/synthetic_sdmle_test.dir/clean

examples/CMakeFiles/synthetic_sdmle_test.dir/depend:
	cd /home/gengz/gpu-v2/exageostat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gengz/gpu-v2/exageostat /home/gengz/gpu-v2/exageostat/examples /home/gengz/gpu-v2/exageostat/build /home/gengz/gpu-v2/exageostat/build/examples /home/gengz/gpu-v2/exageostat/build/examples/CMakeFiles/synthetic_sdmle_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/synthetic_sdmle_test.dir/depend

