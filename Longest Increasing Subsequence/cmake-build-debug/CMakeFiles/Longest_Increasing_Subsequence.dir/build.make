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
CMAKE_SOURCE_DIR = "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Longest_Increasing_Subsequence.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Longest_Increasing_Subsequence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Longest_Increasing_Subsequence.dir/flags.make

CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.o: CMakeFiles/Longest_Increasing_Subsequence.dir/flags.make
CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.o -c "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/main.cpp"

CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/main.cpp" > CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.i

CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/main.cpp" -o CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.s

# Object files for target Longest_Increasing_Subsequence
Longest_Increasing_Subsequence_OBJECTS = \
"CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.o"

# External object files for target Longest_Increasing_Subsequence
Longest_Increasing_Subsequence_EXTERNAL_OBJECTS =

Longest_Increasing_Subsequence: CMakeFiles/Longest_Increasing_Subsequence.dir/main.cpp.o
Longest_Increasing_Subsequence: CMakeFiles/Longest_Increasing_Subsequence.dir/build.make
Longest_Increasing_Subsequence: CMakeFiles/Longest_Increasing_Subsequence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Longest_Increasing_Subsequence"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Longest_Increasing_Subsequence.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Longest_Increasing_Subsequence.dir/build: Longest_Increasing_Subsequence

.PHONY : CMakeFiles/Longest_Increasing_Subsequence.dir/build

CMakeFiles/Longest_Increasing_Subsequence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Longest_Increasing_Subsequence.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Longest_Increasing_Subsequence.dir/clean

CMakeFiles/Longest_Increasing_Subsequence.dir/depend:
	cd "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence" "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence" "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/cmake-build-debug" "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/cmake-build-debug" "/Users/jackyhe/Desktop/C++/DMOJ/Longest Increasing Subsequence/cmake-build-debug/CMakeFiles/Longest_Increasing_Subsequence.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Longest_Increasing_Subsequence.dir/depend

