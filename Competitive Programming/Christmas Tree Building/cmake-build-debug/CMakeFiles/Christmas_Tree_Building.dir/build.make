# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Christmas_Tree_Building.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Christmas_Tree_Building.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Christmas_Tree_Building.dir/flags.make

CMakeFiles/Christmas_Tree_Building.dir/main.cpp.o: CMakeFiles/Christmas_Tree_Building.dir/flags.make
CMakeFiles/Christmas_Tree_Building.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Christmas_Tree_Building.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Christmas_Tree_Building.dir/main.cpp.o -c "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/main.cpp"

CMakeFiles/Christmas_Tree_Building.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Christmas_Tree_Building.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/main.cpp" > CMakeFiles/Christmas_Tree_Building.dir/main.cpp.i

CMakeFiles/Christmas_Tree_Building.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Christmas_Tree_Building.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/main.cpp" -o CMakeFiles/Christmas_Tree_Building.dir/main.cpp.s

# Object files for target Christmas_Tree_Building
Christmas_Tree_Building_OBJECTS = \
"CMakeFiles/Christmas_Tree_Building.dir/main.cpp.o"

# External object files for target Christmas_Tree_Building
Christmas_Tree_Building_EXTERNAL_OBJECTS =

Christmas_Tree_Building: CMakeFiles/Christmas_Tree_Building.dir/main.cpp.o
Christmas_Tree_Building: CMakeFiles/Christmas_Tree_Building.dir/build.make
Christmas_Tree_Building: CMakeFiles/Christmas_Tree_Building.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Christmas_Tree_Building"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Christmas_Tree_Building.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Christmas_Tree_Building.dir/build: Christmas_Tree_Building

.PHONY : CMakeFiles/Christmas_Tree_Building.dir/build

CMakeFiles/Christmas_Tree_Building.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Christmas_Tree_Building.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Christmas_Tree_Building.dir/clean

CMakeFiles/Christmas_Tree_Building.dir/depend:
	cd "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building" "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building" "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/cmake-build-debug" "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/cmake-build-debug" "/Users/jackyhe/Desktop/C++/DMOJ/Christmas Tree Building/cmake-build-debug/CMakeFiles/Christmas_Tree_Building.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Christmas_Tree_Building.dir/depend

