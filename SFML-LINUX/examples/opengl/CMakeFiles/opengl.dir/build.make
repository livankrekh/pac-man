# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/unit-hacker/pac-man/SFML-LINUX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/unit-hacker/pac-man/SFML-LINUX

# Include any dependencies generated for this target.
include examples/opengl/CMakeFiles/opengl.dir/depend.make

# Include the progress variables for this target.
include examples/opengl/CMakeFiles/opengl.dir/progress.make

# Include the compile flags for this target's objects.
include examples/opengl/CMakeFiles/opengl.dir/flags.make

examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o: examples/opengl/CMakeFiles/opengl.dir/flags.make
examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o: examples/opengl/OpenGL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/unit-hacker/pac-man/SFML-LINUX/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o"
	cd /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/OpenGL.cpp.o -c /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl/OpenGL.cpp

examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/OpenGL.cpp.i"
	cd /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl/OpenGL.cpp > CMakeFiles/opengl.dir/OpenGL.cpp.i

examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/OpenGL.cpp.s"
	cd /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl/OpenGL.cpp -o CMakeFiles/opengl.dir/OpenGL.cpp.s

examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o.requires:

.PHONY : examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o.requires

examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o.provides: examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o.requires
	$(MAKE) -f examples/opengl/CMakeFiles/opengl.dir/build.make examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o.provides.build
.PHONY : examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o.provides

examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o.provides.build: examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o


# Object files for target opengl
opengl_OBJECTS = \
"CMakeFiles/opengl.dir/OpenGL.cpp.o"

# External object files for target opengl
opengl_EXTERNAL_OBJECTS =

examples/opengl/opengl: examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o
examples/opengl/opengl: examples/opengl/CMakeFiles/opengl.dir/build.make
examples/opengl/opengl: lib/libsfml-graphics.so.2.4.2
examples/opengl/opengl: lib/libsfml-window.so.2.4.2
examples/opengl/opengl: lib/libsfml-system.so.2.4.2
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libGLU.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libGL.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libXrandr.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libudev.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libSM.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libICE.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libX11.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libXext.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libfreetype.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libjpeg.so
examples/opengl/opengl: /usr/lib/x86_64-linux-gnu/libGL.so
examples/opengl/opengl: examples/opengl/CMakeFiles/opengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/unit-hacker/pac-man/SFML-LINUX/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opengl"
	cd /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/opengl/CMakeFiles/opengl.dir/build: examples/opengl/opengl

.PHONY : examples/opengl/CMakeFiles/opengl.dir/build

examples/opengl/CMakeFiles/opengl.dir/requires: examples/opengl/CMakeFiles/opengl.dir/OpenGL.cpp.o.requires

.PHONY : examples/opengl/CMakeFiles/opengl.dir/requires

examples/opengl/CMakeFiles/opengl.dir/clean:
	cd /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl && $(CMAKE_COMMAND) -P CMakeFiles/opengl.dir/cmake_clean.cmake
.PHONY : examples/opengl/CMakeFiles/opengl.dir/clean

examples/opengl/CMakeFiles/opengl.dir/depend:
	cd /home/unit-hacker/pac-man/SFML-LINUX && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/unit-hacker/pac-man/SFML-LINUX /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl /home/unit-hacker/pac-man/SFML-LINUX /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl /home/unit-hacker/pac-man/SFML-LINUX/examples/opengl/CMakeFiles/opengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/opengl/CMakeFiles/opengl.dir/depend

