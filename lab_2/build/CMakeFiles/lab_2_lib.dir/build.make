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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/OOP_labs_Andrew/lab_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/OOP_labs_Andrew/lab_2/build

# Include any dependencies generated for this target.
include CMakeFiles/lab_2_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab_2_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_2_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_2_lib.dir/flags.make

CMakeFiles/lab_2_lib.dir/src/Six.cpp.o: CMakeFiles/lab_2_lib.dir/flags.make
CMakeFiles/lab_2_lib.dir/src/Six.cpp.o: /workspaces/OOP_labs_Andrew/lab_2/src/Six.cpp
CMakeFiles/lab_2_lib.dir/src/Six.cpp.o: CMakeFiles/lab_2_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OOP_labs_Andrew/lab_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_2_lib.dir/src/Six.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_2_lib.dir/src/Six.cpp.o -MF CMakeFiles/lab_2_lib.dir/src/Six.cpp.o.d -o CMakeFiles/lab_2_lib.dir/src/Six.cpp.o -c /workspaces/OOP_labs_Andrew/lab_2/src/Six.cpp

CMakeFiles/lab_2_lib.dir/src/Six.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_2_lib.dir/src/Six.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OOP_labs_Andrew/lab_2/src/Six.cpp > CMakeFiles/lab_2_lib.dir/src/Six.cpp.i

CMakeFiles/lab_2_lib.dir/src/Six.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_2_lib.dir/src/Six.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OOP_labs_Andrew/lab_2/src/Six.cpp -o CMakeFiles/lab_2_lib.dir/src/Six.cpp.s

# Object files for target lab_2_lib
lab_2_lib_OBJECTS = \
"CMakeFiles/lab_2_lib.dir/src/Six.cpp.o"

# External object files for target lab_2_lib
lab_2_lib_EXTERNAL_OBJECTS =

liblab_2_lib.a: CMakeFiles/lab_2_lib.dir/src/Six.cpp.o
liblab_2_lib.a: CMakeFiles/lab_2_lib.dir/build.make
liblab_2_lib.a: CMakeFiles/lab_2_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/OOP_labs_Andrew/lab_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblab_2_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lab_2_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_2_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_2_lib.dir/build: liblab_2_lib.a
.PHONY : CMakeFiles/lab_2_lib.dir/build

CMakeFiles/lab_2_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_2_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_2_lib.dir/clean

CMakeFiles/lab_2_lib.dir/depend:
	cd /workspaces/OOP_labs_Andrew/lab_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/OOP_labs_Andrew/lab_2 /workspaces/OOP_labs_Andrew/lab_2 /workspaces/OOP_labs_Andrew/lab_2/build /workspaces/OOP_labs_Andrew/lab_2/build /workspaces/OOP_labs_Andrew/lab_2/build/CMakeFiles/lab_2_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_2_lib.dir/depend

