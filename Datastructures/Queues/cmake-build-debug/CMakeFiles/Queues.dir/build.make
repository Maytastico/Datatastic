# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /home/maylis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/231.8109.222/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/maylis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/231.8109.222/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maylis/Documents/Datatastic/Datastructures/Queues

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maylis/Documents/Datatastic/Datastructures/Queues/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Queues.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Queues.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Queues.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Queues.dir/flags.make

CMakeFiles/Queues.dir/main.c.o: CMakeFiles/Queues.dir/flags.make
CMakeFiles/Queues.dir/main.c.o: /home/maylis/Documents/Datatastic/Datastructures/Queues/main.c
CMakeFiles/Queues.dir/main.c.o: CMakeFiles/Queues.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maylis/Documents/Datatastic/Datastructures/Queues/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Queues.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Queues.dir/main.c.o -MF CMakeFiles/Queues.dir/main.c.o.d -o CMakeFiles/Queues.dir/main.c.o -c /home/maylis/Documents/Datatastic/Datastructures/Queues/main.c

CMakeFiles/Queues.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Queues.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maylis/Documents/Datatastic/Datastructures/Queues/main.c > CMakeFiles/Queues.dir/main.c.i

CMakeFiles/Queues.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Queues.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maylis/Documents/Datatastic/Datastructures/Queues/main.c -o CMakeFiles/Queues.dir/main.c.s

# Object files for target Queues
Queues_OBJECTS = \
"CMakeFiles/Queues.dir/main.c.o"

# External object files for target Queues
Queues_EXTERNAL_OBJECTS =

Queues: CMakeFiles/Queues.dir/main.c.o
Queues: CMakeFiles/Queues.dir/build.make
Queues: CMakeFiles/Queues.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maylis/Documents/Datatastic/Datastructures/Queues/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Queues"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Queues.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Queues.dir/build: Queues
.PHONY : CMakeFiles/Queues.dir/build

CMakeFiles/Queues.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Queues.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Queues.dir/clean

CMakeFiles/Queues.dir/depend:
	cd /home/maylis/Documents/Datatastic/Datastructures/Queues/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maylis/Documents/Datatastic/Datastructures/Queues /home/maylis/Documents/Datatastic/Datastructures/Queues /home/maylis/Documents/Datatastic/Datastructures/Queues/cmake-build-debug /home/maylis/Documents/Datatastic/Datastructures/Queues/cmake-build-debug /home/maylis/Documents/Datatastic/Datastructures/Queues/cmake-build-debug/CMakeFiles/Queues.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Queues.dir/depend
