# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/user/Desktop/Programming/Personal/TaskManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TaskManager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TaskManager.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TaskManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TaskManager.dir/flags.make

CMakeFiles/TaskManager.dir/main.c.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/main.c.o: /Users/user/Desktop/Programming/Personal/TaskManager/main.c
CMakeFiles/TaskManager.dir/main.c.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TaskManager.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/main.c.o -MF CMakeFiles/TaskManager.dir/main.c.o.d -o CMakeFiles/TaskManager.dir/main.c.o -c /Users/user/Desktop/Programming/Personal/TaskManager/main.c

CMakeFiles/TaskManager.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TaskManager.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Desktop/Programming/Personal/TaskManager/main.c > CMakeFiles/TaskManager.dir/main.c.i

CMakeFiles/TaskManager.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TaskManager.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Desktop/Programming/Personal/TaskManager/main.c -o CMakeFiles/TaskManager.dir/main.c.s

CMakeFiles/TaskManager.dir/task_manager_interface.c.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/task_manager_interface.c.o: /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_interface.c
CMakeFiles/TaskManager.dir/task_manager_interface.c.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TaskManager.dir/task_manager_interface.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/task_manager_interface.c.o -MF CMakeFiles/TaskManager.dir/task_manager_interface.c.o.d -o CMakeFiles/TaskManager.dir/task_manager_interface.c.o -c /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_interface.c

CMakeFiles/TaskManager.dir/task_manager_interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TaskManager.dir/task_manager_interface.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_interface.c > CMakeFiles/TaskManager.dir/task_manager_interface.c.i

CMakeFiles/TaskManager.dir/task_manager_interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TaskManager.dir/task_manager_interface.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_interface.c -o CMakeFiles/TaskManager.dir/task_manager_interface.c.s

CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o: /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_interface_ge.c
CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o -MF CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o.d -o CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o -c /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_interface_ge.c

CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_interface_ge.c > CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.i

CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_interface_ge.c -o CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.s

CMakeFiles/TaskManager.dir/task_manager_save_file.c.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/task_manager_save_file.c.o: /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_save_file.c
CMakeFiles/TaskManager.dir/task_manager_save_file.c.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/TaskManager.dir/task_manager_save_file.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/task_manager_save_file.c.o -MF CMakeFiles/TaskManager.dir/task_manager_save_file.c.o.d -o CMakeFiles/TaskManager.dir/task_manager_save_file.c.o -c /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_save_file.c

CMakeFiles/TaskManager.dir/task_manager_save_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TaskManager.dir/task_manager_save_file.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_save_file.c > CMakeFiles/TaskManager.dir/task_manager_save_file.c.i

CMakeFiles/TaskManager.dir/task_manager_save_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TaskManager.dir/task_manager_save_file.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Desktop/Programming/Personal/TaskManager/task_manager_save_file.c -o CMakeFiles/TaskManager.dir/task_manager_save_file.c.s

# Object files for target TaskManager
TaskManager_OBJECTS = \
"CMakeFiles/TaskManager.dir/main.c.o" \
"CMakeFiles/TaskManager.dir/task_manager_interface.c.o" \
"CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o" \
"CMakeFiles/TaskManager.dir/task_manager_save_file.c.o"

# External object files for target TaskManager
TaskManager_EXTERNAL_OBJECTS =

TaskManager: CMakeFiles/TaskManager.dir/main.c.o
TaskManager: CMakeFiles/TaskManager.dir/task_manager_interface.c.o
TaskManager: CMakeFiles/TaskManager.dir/task_manager_interface_ge.c.o
TaskManager: CMakeFiles/TaskManager.dir/task_manager_save_file.c.o
TaskManager: CMakeFiles/TaskManager.dir/build.make
TaskManager: CMakeFiles/TaskManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable TaskManager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TaskManager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TaskManager.dir/build: TaskManager
.PHONY : CMakeFiles/TaskManager.dir/build

CMakeFiles/TaskManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TaskManager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TaskManager.dir/clean

CMakeFiles/TaskManager.dir/depend:
	cd /Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/user/Desktop/Programming/Personal/TaskManager /Users/user/Desktop/Programming/Personal/TaskManager /Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug /Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug /Users/user/Desktop/Programming/Personal/TaskManager/cmake-build-debug/CMakeFiles/TaskManager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TaskManager.dir/depend
