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
CMAKE_SOURCE_DIR = /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build

# Include any dependencies generated for this target.
include test/CMakeFiles/t_tutorial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/t_tutorial.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/t_tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/t_tutorial.dir/flags.make

test/CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o: test/CMakeFiles/t_tutorial.dir/flags.make
test/CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o: ../test/t_tutorial.cxx
test/CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o: test/CMakeFiles/t_tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o"
	cd /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/test && /opt/ecrc/gcc/10.2.0/ub18/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o -MF CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o.d -o CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o -c /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/test/t_tutorial.cxx

test/CMakeFiles/t_tutorial.dir/t_tutorial.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/t_tutorial.dir/t_tutorial.cxx.i"
	cd /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/test && /opt/ecrc/gcc/10.2.0/ub18/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/test/t_tutorial.cxx > CMakeFiles/t_tutorial.dir/t_tutorial.cxx.i

test/CMakeFiles/t_tutorial.dir/t_tutorial.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/t_tutorial.dir/t_tutorial.cxx.s"
	cd /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/test && /opt/ecrc/gcc/10.2.0/ub18/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/test/t_tutorial.cxx -o CMakeFiles/t_tutorial.dir/t_tutorial.cxx.s

# Object files for target t_tutorial
t_tutorial_OBJECTS = \
"CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o"

# External object files for target t_tutorial
t_tutorial_EXTERNAL_OBJECTS =

test/t_tutorial: test/CMakeFiles/t_tutorial.dir/t_tutorial.cxx.o
test/t_tutorial: test/CMakeFiles/t_tutorial.dir/build.make
test/t_tutorial: libnlopt.so.0.11.0
test/t_tutorial: test/CMakeFiles/t_tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable t_tutorial"
	cd /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/t_tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/t_tutorial.dir/build: test/t_tutorial
.PHONY : test/CMakeFiles/t_tutorial.dir/build

test/CMakeFiles/t_tutorial.dir/clean:
	cd /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/test && $(CMAKE_COMMAND) -P CMakeFiles/t_tutorial.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/t_tutorial.dir/clean

test/CMakeFiles/t_tutorial.dir/depend:
	cd /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0 /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/test /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/test /home/gengz/gpu-v2/exageostat/installdir/dependencies/nlopt-2.7.0/build/test/CMakeFiles/t_tutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/t_tutorial.dir/depend

