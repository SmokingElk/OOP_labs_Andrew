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
CMAKE_SOURCE_DIR = /workspaces/OOP_labs_Andrew/lab_6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/OOP_labs_Andrew/lab_6/build

# Include any dependencies generated for this target.
include CMakeFiles/lab_2_lib_Pirate.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab_2_lib_Pirate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_2_lib_Pirate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_2_lib_Pirate.dir/flags.make

CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o: CMakeFiles/lab_2_lib_Pirate.dir/flags.make
CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o: /workspaces/OOP_labs_Andrew/lab_6/src/NPCs/Pirate.cpp
CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o: CMakeFiles/lab_2_lib_Pirate.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OOP_labs_Andrew/lab_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o -MF CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o.d -o CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o -c /workspaces/OOP_labs_Andrew/lab_6/src/NPCs/Pirate.cpp

CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OOP_labs_Andrew/lab_6/src/NPCs/Pirate.cpp > CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.i

CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OOP_labs_Andrew/lab_6/src/NPCs/Pirate.cpp -o CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.s

# Object files for target lab_2_lib_Pirate
lab_2_lib_Pirate_OBJECTS = \
"CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o"

# External object files for target lab_2_lib_Pirate
lab_2_lib_Pirate_EXTERNAL_OBJECTS =

liblab_2_lib_Pirate.a: CMakeFiles/lab_2_lib_Pirate.dir/src/NPCs/Pirate.cpp.o
liblab_2_lib_Pirate.a: CMakeFiles/lab_2_lib_Pirate.dir/build.make
liblab_2_lib_Pirate.a: CMakeFiles/lab_2_lib_Pirate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/OOP_labs_Andrew/lab_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblab_2_lib_Pirate.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lab_2_lib_Pirate.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_2_lib_Pirate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_2_lib_Pirate.dir/build: liblab_2_lib_Pirate.a
.PHONY : CMakeFiles/lab_2_lib_Pirate.dir/build

CMakeFiles/lab_2_lib_Pirate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_2_lib_Pirate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_2_lib_Pirate.dir/clean

CMakeFiles/lab_2_lib_Pirate.dir/depend:
	cd /workspaces/OOP_labs_Andrew/lab_6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/OOP_labs_Andrew/lab_6 /workspaces/OOP_labs_Andrew/lab_6 /workspaces/OOP_labs_Andrew/lab_6/build /workspaces/OOP_labs_Andrew/lab_6/build /workspaces/OOP_labs_Andrew/lab_6/build/CMakeFiles/lab_2_lib_Pirate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_2_lib_Pirate.dir/depend

