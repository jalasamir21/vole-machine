# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ahmedatef/CLionProjects/vole-machine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/A1_Task4_S19_20230104.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/A1_Task4_S19_20230104.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A1_Task4_S19_20230104.dir/flags.make

CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/flags.make
CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o: /Users/ahmedatef/CLionProjects/vole-machine/main.cpp
CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o -MF CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o.d -o CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o -c /Users/ahmedatef/CLionProjects/vole-machine/main.cpp

CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahmedatef/CLionProjects/vole-machine/main.cpp > CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.i

CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahmedatef/CLionProjects/vole-machine/main.cpp -o CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.s

CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/flags.make
CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o: /Users/ahmedatef/CLionProjects/vole-machine/machine.cpp
CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o -MF CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o.d -o CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o -c /Users/ahmedatef/CLionProjects/vole-machine/machine.cpp

CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahmedatef/CLionProjects/vole-machine/machine.cpp > CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.i

CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahmedatef/CLionProjects/vole-machine/machine.cpp -o CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.s

CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/flags.make
CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o: /Users/ahmedatef/CLionProjects/vole-machine/cpu.cpp
CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o -MF CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o.d -o CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o -c /Users/ahmedatef/CLionProjects/vole-machine/cpu.cpp

CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahmedatef/CLionProjects/vole-machine/cpu.cpp > CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.i

CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahmedatef/CLionProjects/vole-machine/cpu.cpp -o CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.s

CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/flags.make
CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o: /Users/ahmedatef/CLionProjects/vole-machine/ControlUnit.cpp
CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o -MF CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o.d -o CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o -c /Users/ahmedatef/CLionProjects/vole-machine/ControlUnit.cpp

CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahmedatef/CLionProjects/vole-machine/ControlUnit.cpp > CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.i

CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahmedatef/CLionProjects/vole-machine/ControlUnit.cpp -o CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.s

CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/flags.make
CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o: /Users/ahmedatef/CLionProjects/vole-machine/register.cpp
CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o -MF CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o.d -o CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o -c /Users/ahmedatef/CLionProjects/vole-machine/register.cpp

CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahmedatef/CLionProjects/vole-machine/register.cpp > CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.i

CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahmedatef/CLionProjects/vole-machine/register.cpp -o CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.s

CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/flags.make
CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o: /Users/ahmedatef/CLionProjects/vole-machine/memory.cpp
CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o -MF CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o.d -o CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o -c /Users/ahmedatef/CLionProjects/vole-machine/memory.cpp

CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahmedatef/CLionProjects/vole-machine/memory.cpp > CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.i

CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahmedatef/CLionProjects/vole-machine/memory.cpp -o CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.s

CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/flags.make
CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o: /Users/ahmedatef/CLionProjects/vole-machine/mainUi.cpp
CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o -MF CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o.d -o CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o -c /Users/ahmedatef/CLionProjects/vole-machine/mainUi.cpp

CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahmedatef/CLionProjects/vole-machine/mainUi.cpp > CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.i

CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahmedatef/CLionProjects/vole-machine/mainUi.cpp -o CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.s

CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/flags.make
CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o: /Users/ahmedatef/CLionProjects/vole-machine/Alu.cpp
CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o: CMakeFiles/A1_Task4_S19_20230104.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o -MF CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o.d -o CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o -c /Users/ahmedatef/CLionProjects/vole-machine/Alu.cpp

CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahmedatef/CLionProjects/vole-machine/Alu.cpp > CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.i

CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahmedatef/CLionProjects/vole-machine/Alu.cpp -o CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.s

# Object files for target A1_Task4_S19_20230104
A1_Task4_S19_20230104_OBJECTS = \
"CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o" \
"CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o" \
"CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o" \
"CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o" \
"CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o" \
"CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o" \
"CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o" \
"CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o"

# External object files for target A1_Task4_S19_20230104
A1_Task4_S19_20230104_EXTERNAL_OBJECTS =

A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/main.cpp.o
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/machine.cpp.o
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/cpu.cpp.o
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/ControlUnit.cpp.o
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/register.cpp.o
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/memory.cpp.o
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/mainUi.cpp.o
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/Alu.cpp.o
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/build.make
A1_Task4_S19_20230104: CMakeFiles/A1_Task4_S19_20230104.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable A1_Task4_S19_20230104"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A1_Task4_S19_20230104.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A1_Task4_S19_20230104.dir/build: A1_Task4_S19_20230104
.PHONY : CMakeFiles/A1_Task4_S19_20230104.dir/build

CMakeFiles/A1_Task4_S19_20230104.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A1_Task4_S19_20230104.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A1_Task4_S19_20230104.dir/clean

CMakeFiles/A1_Task4_S19_20230104.dir/depend:
	cd /Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ahmedatef/CLionProjects/vole-machine /Users/ahmedatef/CLionProjects/vole-machine /Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug /Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug /Users/ahmedatef/CLionProjects/vole-machine/cmake-build-debug/CMakeFiles/A1_Task4_S19_20230104.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/A1_Task4_S19_20230104.dir/depend

