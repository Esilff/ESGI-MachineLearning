# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Esilff\Documents\Git\ESGI-MachineLearning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build

# Include any dependencies generated for this target.
include src/CMakeFiles/neural.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/neural.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/neural.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/neural.dir/flags.make

src/CMakeFiles/neural.dir/neural/neuron.cpp.obj: src/CMakeFiles/neural.dir/flags.make
src/CMakeFiles/neural.dir/neural/neuron.cpp.obj: src/CMakeFiles/neural.dir/includes_CXX.rsp
src/CMakeFiles/neural.dir/neural/neuron.cpp.obj: C:/Users/Esilff/Documents/Git/ESGI-MachineLearning/src/neural/neuron.cpp
src/CMakeFiles/neural.dir/neural/neuron.cpp.obj: src/CMakeFiles/neural.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/neural.dir/neural/neuron.cpp.obj"
	cd /d C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\src && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/neural.dir/neural/neuron.cpp.obj -MF CMakeFiles\neural.dir\neural\neuron.cpp.obj.d -o CMakeFiles\neural.dir\neural\neuron.cpp.obj -c C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\src\neural\neuron.cpp

src/CMakeFiles/neural.dir/neural/neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/neural.dir/neural/neuron.cpp.i"
	cd /d C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\src && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\src\neural\neuron.cpp > CMakeFiles\neural.dir\neural\neuron.cpp.i

src/CMakeFiles/neural.dir/neural/neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/neural.dir/neural/neuron.cpp.s"
	cd /d C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\src && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\src\neural\neuron.cpp -o CMakeFiles\neural.dir\neural\neuron.cpp.s

# Object files for target neural
neural_OBJECTS = \
"CMakeFiles/neural.dir/neural/neuron.cpp.obj"

# External object files for target neural
neural_EXTERNAL_OBJECTS =

src/libneural.a: src/CMakeFiles/neural.dir/neural/neuron.cpp.obj
src/libneural.a: src/CMakeFiles/neural.dir/build.make
src/libneural.a: src/CMakeFiles/neural.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libneural.a"
	cd /d C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\src && $(CMAKE_COMMAND) -P CMakeFiles\neural.dir\cmake_clean_target.cmake
	cd /d C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\neural.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/neural.dir/build: src/libneural.a
.PHONY : src/CMakeFiles/neural.dir/build

src/CMakeFiles/neural.dir/clean:
	cd /d C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\src && $(CMAKE_COMMAND) -P CMakeFiles\neural.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/neural.dir/clean

src/CMakeFiles/neural.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Esilff\Documents\Git\ESGI-MachineLearning C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\src C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\src C:\Users\Esilff\Documents\Git\ESGI-MachineLearning\build\src\CMakeFiles\neural.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/neural.dir/depend
