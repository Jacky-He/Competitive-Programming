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
CMAKE_SOURCE_DIR = /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/N_puzzle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/N_puzzle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/N_puzzle.dir/flags.make

CMakeFiles/N_puzzle.dir/main.cpp.o: CMakeFiles/N_puzzle.dir/flags.make
CMakeFiles/N_puzzle.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/N_puzzle.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/N_puzzle.dir/main.cpp.o -c /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/main.cpp

CMakeFiles/N_puzzle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/N_puzzle.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/main.cpp > CMakeFiles/N_puzzle.dir/main.cpp.i

CMakeFiles/N_puzzle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/N_puzzle.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/main.cpp -o CMakeFiles/N_puzzle.dir/main.cpp.s

# Object files for target N_puzzle
N_puzzle_OBJECTS = \
"CMakeFiles/N_puzzle.dir/main.cpp.o"

# External object files for target N_puzzle
N_puzzle_EXTERNAL_OBJECTS =

N_puzzle: CMakeFiles/N_puzzle.dir/main.cpp.o
N_puzzle: CMakeFiles/N_puzzle.dir/build.make
N_puzzle: CMakeFiles/N_puzzle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable N_puzzle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/N_puzzle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/N_puzzle.dir/build: N_puzzle

.PHONY : CMakeFiles/N_puzzle.dir/build

CMakeFiles/N_puzzle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/N_puzzle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/N_puzzle.dir/clean

CMakeFiles/N_puzzle.dir/depend:
	cd /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/cmake-build-debug /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/cmake-build-debug /Users/jackyhe/Desktop/C++/DMOJ/N-puzzle/cmake-build-debug/CMakeFiles/N_puzzle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/N_puzzle.dir/depend
