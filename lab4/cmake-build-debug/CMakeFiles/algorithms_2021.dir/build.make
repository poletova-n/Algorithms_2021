# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\PTcodes\c++\GitPull\Algorithms_2021\lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\algorithms_2021.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\algorithms_2021.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\algorithms_2021.dir\flags.make

CMakeFiles\algorithms_2021.dir\z2.3.cpp.obj: CMakeFiles\algorithms_2021.dir\flags.make
CMakeFiles\algorithms_2021.dir\z2.3.cpp.obj: ..\z2.3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorithms_2021.dir/z2.3.cpp.obj"
	"D:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\algorithms_2021.dir\z2.3.cpp.obj /FdCMakeFiles\algorithms_2021.dir\ /FS -c D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\z2.3.cpp
<<

CMakeFiles\algorithms_2021.dir\z2.3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algorithms_2021.dir/z2.3.cpp.i"
	"D:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\algorithms_2021.dir\z2.3.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\z2.3.cpp
<<

CMakeFiles\algorithms_2021.dir\z2.3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algorithms_2021.dir/z2.3.cpp.s"
	"D:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\algorithms_2021.dir\z2.3.cpp.s /c D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\z2.3.cpp
<<

# Object files for target algorithms_2021
algorithms_2021_OBJECTS = \
"CMakeFiles\algorithms_2021.dir\z2.3.cpp.obj"

# External object files for target algorithms_2021
algorithms_2021_EXTERNAL_OBJECTS =

algorithms_2021.exe: CMakeFiles\algorithms_2021.dir\z2.3.cpp.obj
algorithms_2021.exe: CMakeFiles\algorithms_2021.dir\build.make
algorithms_2021.exe: CMakeFiles\algorithms_2021.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algorithms_2021.exe"
	"D:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\algorithms_2021.dir --rc="D:\Windows Kits\10\bin\10.0.19041.0\x86\rc.exe" --mt="D:\Windows Kits\10\bin\10.0.19041.0\x86\mt.exe" --manifests -- "D:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\link.exe" /nologo @CMakeFiles\algorithms_2021.dir\objects1.rsp @<<
 /out:algorithms_2021.exe /implib:algorithms_2021.lib /pdb:D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\cmake-build-debug\algorithms_2021.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\algorithms_2021.dir\build: algorithms_2021.exe
.PHONY : CMakeFiles\algorithms_2021.dir\build

CMakeFiles\algorithms_2021.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorithms_2021.dir\cmake_clean.cmake
.PHONY : CMakeFiles\algorithms_2021.dir\clean

CMakeFiles\algorithms_2021.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\PTcodes\c++\GitPull\Algorithms_2021\lab4 D:\PTcodes\c++\GitPull\Algorithms_2021\lab4 D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\cmake-build-debug D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\cmake-build-debug D:\PTcodes\c++\GitPull\Algorithms_2021\lab4\cmake-build-debug\CMakeFiles\algorithms_2021.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\algorithms_2021.dir\depend

