# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/colin/Documents/IcSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/colin/Documents/IcSim/build

# Include any dependencies generated for this target.
include CMakeFiles/IcSim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IcSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IcSim.dir/flags.make

CMakeFiles/IcSim.dir/src/main.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IcSim.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/main.cpp.o -c /home/colin/Documents/IcSim/src/main.cpp

CMakeFiles/IcSim.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/main.cpp > CMakeFiles/IcSim.dir/src/main.cpp.i

CMakeFiles/IcSim.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/main.cpp -o CMakeFiles/IcSim.dir/src/main.cpp.s

CMakeFiles/IcSim.dir/src/chip_base.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/chip_base.cpp.o: ../src/chip_base.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/IcSim.dir/src/chip_base.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/chip_base.cpp.o -c /home/colin/Documents/IcSim/src/chip_base.cpp

CMakeFiles/IcSim.dir/src/chip_base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/chip_base.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/chip_base.cpp > CMakeFiles/IcSim.dir/src/chip_base.cpp.i

CMakeFiles/IcSim.dir/src/chip_base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/chip_base.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/chip_base.cpp -o CMakeFiles/IcSim.dir/src/chip_base.cpp.s

CMakeFiles/IcSim.dir/src/chips/clock.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/chips/clock.cpp.o: ../src/chips/clock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/IcSim.dir/src/chips/clock.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/chips/clock.cpp.o -c /home/colin/Documents/IcSim/src/chips/clock.cpp

CMakeFiles/IcSim.dir/src/chips/clock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/chips/clock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/chips/clock.cpp > CMakeFiles/IcSim.dir/src/chips/clock.cpp.i

CMakeFiles/IcSim.dir/src/chips/clock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/chips/clock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/chips/clock.cpp -o CMakeFiles/IcSim.dir/src/chips/clock.cpp.s

CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.o: ../src/chips/constant_value.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.o -c /home/colin/Documents/IcSim/src/chips/constant_value.cpp

CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/chips/constant_value.cpp > CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.i

CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/chips/constant_value.cpp -o CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.s

CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.o: ../src/chips/SN74LS00.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.o -c /home/colin/Documents/IcSim/src/chips/SN74LS00.cpp

CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/chips/SN74LS00.cpp > CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.i

CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/chips/SN74LS00.cpp -o CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.s

CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.o: ../src/chips/SN74LS04.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.o -c /home/colin/Documents/IcSim/src/chips/SN74LS04.cpp

CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/chips/SN74LS04.cpp > CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.i

CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/chips/SN74LS04.cpp -o CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.s

CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.o: ../src/chips/SN74LS20.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.o -c /home/colin/Documents/IcSim/src/chips/SN74LS20.cpp

CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/chips/SN74LS20.cpp > CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.i

CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/chips/SN74LS20.cpp -o CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.s

CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.o: ../src/chips/SN74LS30.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.o -c /home/colin/Documents/IcSim/src/chips/SN74LS30.cpp

CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/chips/SN74LS30.cpp > CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.i

CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/chips/SN74LS30.cpp -o CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.s

CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.o: CMakeFiles/IcSim.dir/flags.make
CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.o: ../src/chips/SN74LS161A.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.o -c /home/colin/Documents/IcSim/src/chips/SN74LS161A.cpp

CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/IcSim/src/chips/SN74LS161A.cpp > CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.i

CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/IcSim/src/chips/SN74LS161A.cpp -o CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.s

# Object files for target IcSim
IcSim_OBJECTS = \
"CMakeFiles/IcSim.dir/src/main.cpp.o" \
"CMakeFiles/IcSim.dir/src/chip_base.cpp.o" \
"CMakeFiles/IcSim.dir/src/chips/clock.cpp.o" \
"CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.o" \
"CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.o" \
"CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.o" \
"CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.o" \
"CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.o" \
"CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.o"

# External object files for target IcSim
IcSim_EXTERNAL_OBJECTS =

IcSim: CMakeFiles/IcSim.dir/src/main.cpp.o
IcSim: CMakeFiles/IcSim.dir/src/chip_base.cpp.o
IcSim: CMakeFiles/IcSim.dir/src/chips/clock.cpp.o
IcSim: CMakeFiles/IcSim.dir/src/chips/constant_value.cpp.o
IcSim: CMakeFiles/IcSim.dir/src/chips/SN74LS00.cpp.o
IcSim: CMakeFiles/IcSim.dir/src/chips/SN74LS04.cpp.o
IcSim: CMakeFiles/IcSim.dir/src/chips/SN74LS20.cpp.o
IcSim: CMakeFiles/IcSim.dir/src/chips/SN74LS30.cpp.o
IcSim: CMakeFiles/IcSim.dir/src/chips/SN74LS161A.cpp.o
IcSim: CMakeFiles/IcSim.dir/build.make
IcSim: CMakeFiles/IcSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/colin/Documents/IcSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable IcSim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IcSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IcSim.dir/build: IcSim

.PHONY : CMakeFiles/IcSim.dir/build

CMakeFiles/IcSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IcSim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IcSim.dir/clean

CMakeFiles/IcSim.dir/depend:
	cd /home/colin/Documents/IcSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/colin/Documents/IcSim /home/colin/Documents/IcSim /home/colin/Documents/IcSim/build /home/colin/Documents/IcSim/build /home/colin/Documents/IcSim/build/CMakeFiles/IcSim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IcSim.dir/depend

