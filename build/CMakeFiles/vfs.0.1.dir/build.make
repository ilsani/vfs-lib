# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/home/msani/wrk/dev/vfs-lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/home/msani/wrk/dev/vfs-lib/build

# Include any dependencies generated for this target.
include CMakeFiles/vfs.0.1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vfs.0.1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vfs.0.1.dir/flags.make

CMakeFiles/vfs.0.1.dir/lib/vfs.c.o: CMakeFiles/vfs.0.1.dir/flags.make
CMakeFiles/vfs.0.1.dir/lib/vfs.c.o: ../lib/vfs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/home/msani/wrk/dev/vfs-lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/vfs.0.1.dir/lib/vfs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vfs.0.1.dir/lib/vfs.c.o   -c /usr/home/msani/wrk/dev/vfs-lib/lib/vfs.c

CMakeFiles/vfs.0.1.dir/lib/vfs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vfs.0.1.dir/lib/vfs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/home/msani/wrk/dev/vfs-lib/lib/vfs.c > CMakeFiles/vfs.0.1.dir/lib/vfs.c.i

CMakeFiles/vfs.0.1.dir/lib/vfs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vfs.0.1.dir/lib/vfs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/home/msani/wrk/dev/vfs-lib/lib/vfs.c -o CMakeFiles/vfs.0.1.dir/lib/vfs.c.s

CMakeFiles/vfs.0.1.dir/lib/vfs.c.o.requires:

.PHONY : CMakeFiles/vfs.0.1.dir/lib/vfs.c.o.requires

CMakeFiles/vfs.0.1.dir/lib/vfs.c.o.provides: CMakeFiles/vfs.0.1.dir/lib/vfs.c.o.requires
	$(MAKE) -f CMakeFiles/vfs.0.1.dir/build.make CMakeFiles/vfs.0.1.dir/lib/vfs.c.o.provides.build
.PHONY : CMakeFiles/vfs.0.1.dir/lib/vfs.c.o.provides

CMakeFiles/vfs.0.1.dir/lib/vfs.c.o.provides.build: CMakeFiles/vfs.0.1.dir/lib/vfs.c.o


# Object files for target vfs.0.1
vfs_0_1_OBJECTS = \
"CMakeFiles/vfs.0.1.dir/lib/vfs.c.o"

# External object files for target vfs.0.1
vfs_0_1_EXTERNAL_OBJECTS =

libvfs.0.1.a: CMakeFiles/vfs.0.1.dir/lib/vfs.c.o
libvfs.0.1.a: CMakeFiles/vfs.0.1.dir/build.make
libvfs.0.1.a: CMakeFiles/vfs.0.1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/home/msani/wrk/dev/vfs-lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libvfs.0.1.a"
	$(CMAKE_COMMAND) -P CMakeFiles/vfs.0.1.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vfs.0.1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vfs.0.1.dir/build: libvfs.0.1.a

.PHONY : CMakeFiles/vfs.0.1.dir/build

CMakeFiles/vfs.0.1.dir/requires: CMakeFiles/vfs.0.1.dir/lib/vfs.c.o.requires

.PHONY : CMakeFiles/vfs.0.1.dir/requires

CMakeFiles/vfs.0.1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vfs.0.1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vfs.0.1.dir/clean

CMakeFiles/vfs.0.1.dir/depend:
	cd /usr/home/msani/wrk/dev/vfs-lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/home/msani/wrk/dev/vfs-lib /usr/home/msani/wrk/dev/vfs-lib /usr/home/msani/wrk/dev/vfs-lib/build /usr/home/msani/wrk/dev/vfs-lib/build /usr/home/msani/wrk/dev/vfs-lib/build/CMakeFiles/vfs.0.1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vfs.0.1.dir/depend
