# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1

# Include any dependencies generated for this target.
include CMakeFiles/soa.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/soa.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/soa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/soa.dir/flags.make

CMakeFiles/soa.dir/soa/imagesoa.cpp.o: CMakeFiles/soa.dir/flags.make
CMakeFiles/soa.dir/soa/imagesoa.cpp.o: soa/imagesoa.cpp
CMakeFiles/soa.dir/soa/imagesoa.cpp.o: CMakeFiles/soa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/soa.dir/soa/imagesoa.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/soa.dir/soa/imagesoa.cpp.o -MF CMakeFiles/soa.dir/soa/imagesoa.cpp.o.d -o CMakeFiles/soa.dir/soa/imagesoa.cpp.o -c /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1/soa/imagesoa.cpp

CMakeFiles/soa.dir/soa/imagesoa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/soa.dir/soa/imagesoa.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1/soa/imagesoa.cpp > CMakeFiles/soa.dir/soa/imagesoa.cpp.i

CMakeFiles/soa.dir/soa/imagesoa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/soa.dir/soa/imagesoa.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1/soa/imagesoa.cpp -o CMakeFiles/soa.dir/soa/imagesoa.cpp.s

# Object files for target soa
soa_OBJECTS = \
"CMakeFiles/soa.dir/soa/imagesoa.cpp.o"

# External object files for target soa
soa_EXTERNAL_OBJECTS =

libsoa.a: CMakeFiles/soa.dir/soa/imagesoa.cpp.o
libsoa.a: CMakeFiles/soa.dir/build.make
libsoa.a: CMakeFiles/soa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsoa.a"
	$(CMAKE_COMMAND) -P CMakeFiles/soa.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/soa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/soa.dir/build: libsoa.a
.PHONY : CMakeFiles/soa.dir/build

CMakeFiles/soa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/soa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/soa.dir/clean

CMakeFiles/soa.dir/depend:
	cd /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1 /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1 /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1 /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1 /mnt/h/almoh/Documents/GitHub/Arquitectura-de-Computadores/p1/CMakeFiles/soa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/soa.dir/depend

