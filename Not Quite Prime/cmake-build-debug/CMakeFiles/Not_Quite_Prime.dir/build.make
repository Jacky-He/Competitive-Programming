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
CMAKE_SOURCE_DIR = "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Not_Quite_Prime.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Not_Quite_Prime.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Not_Quite_Prime.dir/flags.make

CMakeFiles/Not_Quite_Prime.dir/main.cpp.o: CMakeFiles/Not_Quite_Prime.dir/flags.make
CMakeFiles/Not_Quite_Prime.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Not_Quite_Prime.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Not_Quite_Prime.dir/main.cpp.o -c "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/main.cpp"

CMakeFiles/Not_Quite_Prime.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Not_Quite_Prime.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/main.cpp" > CMakeFiles/Not_Quite_Prime.dir/main.cpp.i

CMakeFiles/Not_Quite_Prime.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Not_Quite_Prime.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/main.cpp" -o CMakeFiles/Not_Quite_Prime.dir/main.cpp.s

# Object files for target Not_Quite_Prime
Not_Quite_Prime_OBJECTS = \
"CMakeFiles/Not_Quite_Prime.dir/main.cpp.o"

# External object files for target Not_Quite_Prime
Not_Quite_Prime_EXTERNAL_OBJECTS =

Not_Quite_Prime: CMakeFiles/Not_Quite_Prime.dir/main.cpp.o
Not_Quite_Prime: CMakeFiles/Not_Quite_Prime.dir/build.make
Not_Quite_Prime: CMakeFiles/Not_Quite_Prime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Not_Quite_Prime"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Not_Quite_Prime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Not_Quite_Prime.dir/build: Not_Quite_Prime

.PHONY : CMakeFiles/Not_Quite_Prime.dir/build

CMakeFiles/Not_Quite_Prime.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Not_Quite_Prime.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Not_Quite_Prime.dir/clean

CMakeFiles/Not_Quite_Prime.dir/depend:
	cd "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime" "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime" "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/cmake-build-debug" "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/cmake-build-debug" "/Users/jackyhe/Desktop/C++/DMOJ/Not Quite Prime/cmake-build-debug/CMakeFiles/Not_Quite_Prime.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Not_Quite_Prime.dir/depend

