# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\clion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\clion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\admin\CLionProjects\6B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\admin\CLionProjects\6B\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/6B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/6B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/6B.dir/flags.make

CMakeFiles/6B.dir/main.cpp.obj: CMakeFiles/6B.dir/flags.make
CMakeFiles/6B.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\admin\CLionProjects\6B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/6B.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\6B.dir\main.cpp.obj -c C:\Users\admin\CLionProjects\6B\main.cpp

CMakeFiles/6B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/6B.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\admin\CLionProjects\6B\main.cpp > CMakeFiles\6B.dir\main.cpp.i

CMakeFiles/6B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/6B.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\admin\CLionProjects\6B\main.cpp -o CMakeFiles\6B.dir\main.cpp.s

# Object files for target 6B
6B_OBJECTS = \
"CMakeFiles/6B.dir/main.cpp.obj"

# External object files for target 6B
6B_EXTERNAL_OBJECTS =

6B.exe: CMakeFiles/6B.dir/main.cpp.obj
6B.exe: CMakeFiles/6B.dir/build.make
6B.exe: CMakeFiles/6B.dir/linklibs.rsp
6B.exe: CMakeFiles/6B.dir/objects1.rsp
6B.exe: CMakeFiles/6B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\admin\CLionProjects\6B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 6B.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\6B.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/6B.dir/build: 6B.exe

.PHONY : CMakeFiles/6B.dir/build

CMakeFiles/6B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\6B.dir\cmake_clean.cmake
.PHONY : CMakeFiles/6B.dir/clean

CMakeFiles/6B.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\admin\CLionProjects\6B C:\Users\admin\CLionProjects\6B C:\Users\admin\CLionProjects\6B\cmake-build-debug C:\Users\admin\CLionProjects\6B\cmake-build-debug C:\Users\admin\CLionProjects\6B\cmake-build-debug\CMakeFiles\6B.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/6B.dir/depend

