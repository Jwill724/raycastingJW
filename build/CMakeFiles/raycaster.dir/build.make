# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/Justi/raycaster

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/Justi/raycaster/build

# Include any dependencies generated for this target.
include CMakeFiles/raycaster.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/raycaster.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raycaster.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raycaster.dir/flags.make

CMakeFiles/raycaster.dir/src/main.c.obj: CMakeFiles/raycaster.dir/flags.make
CMakeFiles/raycaster.dir/src/main.c.obj: CMakeFiles/raycaster.dir/includes_C.rsp
CMakeFiles/raycaster.dir/src/main.c.obj: C:/Users/Justi/raycaster/src/main.c
CMakeFiles/raycaster.dir/src/main.c.obj: CMakeFiles/raycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/Justi/raycaster/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/raycaster.dir/src/main.c.obj"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/raycaster.dir/src/main.c.obj -MF CMakeFiles/raycaster.dir/src/main.c.obj.d -o CMakeFiles/raycaster.dir/src/main.c.obj -c C:/Users/Justi/raycaster/src/main.c

CMakeFiles/raycaster.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/raycaster.dir/src/main.c.i"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/Justi/raycaster/src/main.c > CMakeFiles/raycaster.dir/src/main.c.i

CMakeFiles/raycaster.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/raycaster.dir/src/main.c.s"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/Justi/raycaster/src/main.c -o CMakeFiles/raycaster.dir/src/main.c.s

CMakeFiles/raycaster.dir/src/raycaster.c.obj: CMakeFiles/raycaster.dir/flags.make
CMakeFiles/raycaster.dir/src/raycaster.c.obj: CMakeFiles/raycaster.dir/includes_C.rsp
CMakeFiles/raycaster.dir/src/raycaster.c.obj: C:/Users/Justi/raycaster/src/raycaster.c
CMakeFiles/raycaster.dir/src/raycaster.c.obj: CMakeFiles/raycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/Justi/raycaster/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/raycaster.dir/src/raycaster.c.obj"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/raycaster.dir/src/raycaster.c.obj -MF CMakeFiles/raycaster.dir/src/raycaster.c.obj.d -o CMakeFiles/raycaster.dir/src/raycaster.c.obj -c C:/Users/Justi/raycaster/src/raycaster.c

CMakeFiles/raycaster.dir/src/raycaster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/raycaster.dir/src/raycaster.c.i"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/Justi/raycaster/src/raycaster.c > CMakeFiles/raycaster.dir/src/raycaster.c.i

CMakeFiles/raycaster.dir/src/raycaster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/raycaster.dir/src/raycaster.c.s"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/Justi/raycaster/src/raycaster.c -o CMakeFiles/raycaster.dir/src/raycaster.c.s

CMakeFiles/raycaster.dir/src/map.c.obj: CMakeFiles/raycaster.dir/flags.make
CMakeFiles/raycaster.dir/src/map.c.obj: CMakeFiles/raycaster.dir/includes_C.rsp
CMakeFiles/raycaster.dir/src/map.c.obj: C:/Users/Justi/raycaster/src/map.c
CMakeFiles/raycaster.dir/src/map.c.obj: CMakeFiles/raycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/Justi/raycaster/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/raycaster.dir/src/map.c.obj"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/raycaster.dir/src/map.c.obj -MF CMakeFiles/raycaster.dir/src/map.c.obj.d -o CMakeFiles/raycaster.dir/src/map.c.obj -c C:/Users/Justi/raycaster/src/map.c

CMakeFiles/raycaster.dir/src/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/raycaster.dir/src/map.c.i"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/Justi/raycaster/src/map.c > CMakeFiles/raycaster.dir/src/map.c.i

CMakeFiles/raycaster.dir/src/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/raycaster.dir/src/map.c.s"
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/Justi/raycaster/src/map.c -o CMakeFiles/raycaster.dir/src/map.c.s

# Object files for target raycaster
raycaster_OBJECTS = \
"CMakeFiles/raycaster.dir/src/main.c.obj" \
"CMakeFiles/raycaster.dir/src/raycaster.c.obj" \
"CMakeFiles/raycaster.dir/src/map.c.obj"

# External object files for target raycaster
raycaster_EXTERNAL_OBJECTS =

raycaster.exe: CMakeFiles/raycaster.dir/src/main.c.obj
raycaster.exe: CMakeFiles/raycaster.dir/src/raycaster.c.obj
raycaster.exe: CMakeFiles/raycaster.dir/src/map.c.obj
raycaster.exe: CMakeFiles/raycaster.dir/build.make
raycaster.exe: C:/Users/Justi/raycaster/src/lib/libSDL2.dll.a
raycaster.exe: C:/Users/Justi/raycaster/src/lib/libSDL2main.a
raycaster.exe: CMakeFiles/raycaster.dir/linkLibs.rsp
raycaster.exe: CMakeFiles/raycaster.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/Justi/raycaster/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable raycaster.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/raycaster.dir/objects.a
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/llvm-ar.exe qc CMakeFiles/raycaster.dir/objects.a @CMakeFiles/raycaster.dir/objects1.rsp
	C:/llvm-mingw-20240619-msvcrt-x86_64/bin/cc.exe -g -Wl,--whole-archive CMakeFiles/raycaster.dir/objects.a -Wl,--no-whole-archive -o raycaster.exe -Wl,--out-implib,libraycaster.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/raycaster.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/raycaster.dir/build: raycaster.exe
.PHONY : CMakeFiles/raycaster.dir/build

CMakeFiles/raycaster.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raycaster.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raycaster.dir/clean

CMakeFiles/raycaster.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/Justi/raycaster C:/Users/Justi/raycaster C:/Users/Justi/raycaster/build C:/Users/Justi/raycaster/build C:/Users/Justi/raycaster/build/CMakeFiles/raycaster.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/raycaster.dir/depend

