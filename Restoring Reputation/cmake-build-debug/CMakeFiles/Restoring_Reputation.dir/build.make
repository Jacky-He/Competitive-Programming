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
CMAKE_SOURCE_DIR = "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Restoring_Reputation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Restoring_Reputation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Restoring_Reputation.dir/flags.make

CMakeFiles/Restoring_Reputation.dir/main.cpp.o: CMakeFiles/Restoring_Reputation.dir/flags.make
CMakeFiles/Restoring_Reputation.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Restoring_Reputation.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Restoring_Reputation.dir/main.cpp.o -c "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/main.cpp"

CMakeFiles/Restoring_Reputation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Restoring_Reputation.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/main.cpp" > CMakeFiles/Restoring_Reputation.dir/main.cpp.i

CMakeFiles/Restoring_Reputation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Restoring_Reputation.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/main.cpp" -o CMakeFiles/Restoring_Reputation.dir/main.cpp.s

# Object files for target Restoring_Reputation
Restoring_Reputation_OBJECTS = \
"CMakeFiles/Restoring_Reputation.dir/main.cpp.o"

# External object files for target Restoring_Reputation
Restoring_Reputation_EXTERNAL_OBJECTS =

Restoring_Reputation: CMakeFiles/Restoring_Reputation.dir/main.cpp.o
Restoring_Reputation: CMakeFiles/Restoring_Reputation.dir/build.make
Restoring_Reputation: CMakeFiles/Restoring_Reputation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Restoring_Reputation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Restoring_Reputation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Restoring_Reputation.dir/build: Restoring_Reputation

.PHONY : CMakeFiles/Restoring_Reputation.dir/build

CMakeFiles/Restoring_Reputation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Restoring_Reputation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Restoring_Reputation.dir/clean

CMakeFiles/Restoring_Reputation.dir/depend:
	cd "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation" "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation" "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/cmake-build-debug" "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/cmake-build-debug" "/Users/jackyhe/Desktop/C++/DMOJ/Restoring Reputation/cmake-build-debug/CMakeFiles/Restoring_Reputation.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Restoring_Reputation.dir/depend
