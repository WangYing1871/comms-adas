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
CMAKE_COMMAND = /home/wangying/software/CMake-build/bin/cmake

# The command to remove a file.
RM = /home/wangying/software/CMake-build/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wangying/work/mis/others/comms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wangying/work/mis/others/comms/adas

# Utility rule file for adas_dsl.

# Include any custom commands dependencies for this target.
include comms/adas/CMakeFiles/adas_dsl.dir/compiler_depend.make

# Include the progress variables for this target.
include comms/adas/CMakeFiles/adas_dsl.dir/progress.make

comms/adas/CMakeFiles/adas_dsl: comms/adas/adas/output
comms/adas/CMakeFiles/adas_dsl: /home/wangying/work/mis/others/comms/CopyGenerated.cmake
comms/adas/CMakeFiles/adas_dsl: /home/wangying/work/mis/others/comms/comms/adas/dsl/main.xml
comms/adas/CMakeFiles/adas_dsl: /home/wangying/work/mis/others/comms/comms/adas/dsl/msg1.xml
	cd /home/wangying/work/mis/others/comms/adas/comms/adas && /home/wangying/software/CMake-build/bin/cmake -DGENERATED="/home/wangying/work/mis/others/comms/adas/comms/adas/adas/output/include" -DOUTPUT="/home/wangying/work/mis/others/comms/adas/adas/include" -P /home/wangying/work/mis/others/comms/CopyGenerated.cmake

comms/adas/adas/output: /home/wangying/work/mis/others/comms/comms/adas/dsl/main.xml
comms/adas/adas/output: /home/wangying/work/mis/others/comms/comms/adas/dsl/msg1.xml
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/wangying/work/mis/others/comms/adas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating adas/output"
	cd /home/wangying/work/mis/others/comms/adas/comms/adas && /home/wangying/software/CMake-build/bin/cmake -E remove_directory /home/wangying/work/mis/others/comms/adas/comms/adas/adas/output
	cd /home/wangying/work/mis/others/comms/adas/comms/adas && /home/wangying/.local/bin/commsdsl2comms --warn-as-err --comms-tag= -o /home/wangying/work/mis/others/comms/adas/comms/adas/adas/output -i /home/wangying/work/mis/others/comms/adas/comms/adas/adas/schema_files.txt

adas_dsl: comms/adas/CMakeFiles/adas_dsl
adas_dsl: comms/adas/adas/output
adas_dsl: comms/adas/CMakeFiles/adas_dsl.dir/build.make
.PHONY : adas_dsl

# Rule to build all files generated by this target.
comms/adas/CMakeFiles/adas_dsl.dir/build: adas_dsl
.PHONY : comms/adas/CMakeFiles/adas_dsl.dir/build

comms/adas/CMakeFiles/adas_dsl.dir/clean:
	cd /home/wangying/work/mis/others/comms/adas/comms/adas && $(CMAKE_COMMAND) -P CMakeFiles/adas_dsl.dir/cmake_clean.cmake
.PHONY : comms/adas/CMakeFiles/adas_dsl.dir/clean

comms/adas/CMakeFiles/adas_dsl.dir/depend:
	cd /home/wangying/work/mis/others/comms/adas && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wangying/work/mis/others/comms /home/wangying/work/mis/others/comms/comms/adas /home/wangying/work/mis/others/comms/adas /home/wangying/work/mis/others/comms/adas/comms/adas /home/wangying/work/mis/others/comms/adas/comms/adas/CMakeFiles/adas_dsl.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : comms/adas/CMakeFiles/adas_dsl.dir/depend
