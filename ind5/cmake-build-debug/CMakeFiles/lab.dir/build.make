# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\miha1\CLionProjects\Algorithms_2021\ind5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab.dir/flags.make

CMakeFiles/lab.dir/z2.cpp.obj: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/z2.cpp.obj: ../z2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab.dir/z2.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab.dir\z2.cpp.obj -c C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\z2.cpp

CMakeFiles/lab.dir/z2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/z2.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\z2.cpp > CMakeFiles\lab.dir\z2.cpp.i

CMakeFiles/lab.dir/z2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/z2.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\z2.cpp -o CMakeFiles\lab.dir\z2.cpp.s

# Object files for target lab
lab_OBJECTS = \
"CMakeFiles/lab.dir/z2.cpp.obj"

# External object files for target lab
lab_EXTERNAL_OBJECTS =

lab.exe: CMakeFiles/lab.dir/z2.cpp.obj
lab.exe: CMakeFiles/lab.dir/build.make
lab.exe: CMakeFiles/lab.dir/linklibs.rsp
lab.exe: CMakeFiles/lab.dir/objects1.rsp
lab.exe: CMakeFiles/lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab.dir/build: lab.exe
.PHONY : CMakeFiles/lab.dir/build

CMakeFiles/lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab.dir/clean

CMakeFiles/lab.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\miha1\CLionProjects\Algorithms_2021\ind5 C:\Users\miha1\CLionProjects\Algorithms_2021\ind5 C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\cmake-build-debug C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\cmake-build-debug C:\Users\miha1\CLionProjects\Algorithms_2021\ind5\cmake-build-debug\CMakeFiles\lab.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab.dir/depend

