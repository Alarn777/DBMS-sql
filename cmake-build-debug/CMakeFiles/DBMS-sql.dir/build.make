# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DBMS-sql.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DBMS-sql.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DBMS-sql.dir/flags.make

CMakeFiles/DBMS-sql.dir/main.cpp.o: CMakeFiles/DBMS-sql.dir/flags.make
CMakeFiles/DBMS-sql.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DBMS-sql.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DBMS-sql.dir/main.cpp.o -c "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/main.cpp"

CMakeFiles/DBMS-sql.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DBMS-sql.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/main.cpp" > CMakeFiles/DBMS-sql.dir/main.cpp.i

CMakeFiles/DBMS-sql.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DBMS-sql.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/main.cpp" -o CMakeFiles/DBMS-sql.dir/main.cpp.s

CMakeFiles/DBMS-sql.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DBMS-sql.dir/main.cpp.o.requires

CMakeFiles/DBMS-sql.dir/main.cpp.o.provides: CMakeFiles/DBMS-sql.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DBMS-sql.dir/build.make CMakeFiles/DBMS-sql.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DBMS-sql.dir/main.cpp.o.provides

CMakeFiles/DBMS-sql.dir/main.cpp.o.provides.build: CMakeFiles/DBMS-sql.dir/main.cpp.o


CMakeFiles/DBMS-sql.dir/Database.cpp.o: CMakeFiles/DBMS-sql.dir/flags.make
CMakeFiles/DBMS-sql.dir/Database.cpp.o: ../Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DBMS-sql.dir/Database.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DBMS-sql.dir/Database.cpp.o -c "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/Database.cpp"

CMakeFiles/DBMS-sql.dir/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DBMS-sql.dir/Database.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/Database.cpp" > CMakeFiles/DBMS-sql.dir/Database.cpp.i

CMakeFiles/DBMS-sql.dir/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DBMS-sql.dir/Database.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/Database.cpp" -o CMakeFiles/DBMS-sql.dir/Database.cpp.s

CMakeFiles/DBMS-sql.dir/Database.cpp.o.requires:

.PHONY : CMakeFiles/DBMS-sql.dir/Database.cpp.o.requires

CMakeFiles/DBMS-sql.dir/Database.cpp.o.provides: CMakeFiles/DBMS-sql.dir/Database.cpp.o.requires
	$(MAKE) -f CMakeFiles/DBMS-sql.dir/build.make CMakeFiles/DBMS-sql.dir/Database.cpp.o.provides.build
.PHONY : CMakeFiles/DBMS-sql.dir/Database.cpp.o.provides

CMakeFiles/DBMS-sql.dir/Database.cpp.o.provides.build: CMakeFiles/DBMS-sql.dir/Database.cpp.o


CMakeFiles/DBMS-sql.dir/Book.cpp.o: CMakeFiles/DBMS-sql.dir/flags.make
CMakeFiles/DBMS-sql.dir/Book.cpp.o: ../Book.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DBMS-sql.dir/Book.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DBMS-sql.dir/Book.cpp.o -c "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/Book.cpp"

CMakeFiles/DBMS-sql.dir/Book.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DBMS-sql.dir/Book.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/Book.cpp" > CMakeFiles/DBMS-sql.dir/Book.cpp.i

CMakeFiles/DBMS-sql.dir/Book.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DBMS-sql.dir/Book.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/Book.cpp" -o CMakeFiles/DBMS-sql.dir/Book.cpp.s

CMakeFiles/DBMS-sql.dir/Book.cpp.o.requires:

.PHONY : CMakeFiles/DBMS-sql.dir/Book.cpp.o.requires

CMakeFiles/DBMS-sql.dir/Book.cpp.o.provides: CMakeFiles/DBMS-sql.dir/Book.cpp.o.requires
	$(MAKE) -f CMakeFiles/DBMS-sql.dir/build.make CMakeFiles/DBMS-sql.dir/Book.cpp.o.provides.build
.PHONY : CMakeFiles/DBMS-sql.dir/Book.cpp.o.provides

CMakeFiles/DBMS-sql.dir/Book.cpp.o.provides.build: CMakeFiles/DBMS-sql.dir/Book.cpp.o


# Object files for target DBMS-sql
DBMS__sql_OBJECTS = \
"CMakeFiles/DBMS-sql.dir/main.cpp.o" \
"CMakeFiles/DBMS-sql.dir/Database.cpp.o" \
"CMakeFiles/DBMS-sql.dir/Book.cpp.o"

# External object files for target DBMS-sql
DBMS__sql_EXTERNAL_OBJECTS =

DBMS-sql: CMakeFiles/DBMS-sql.dir/main.cpp.o
DBMS-sql: CMakeFiles/DBMS-sql.dir/Database.cpp.o
DBMS-sql: CMakeFiles/DBMS-sql.dir/Book.cpp.o
DBMS-sql: CMakeFiles/DBMS-sql.dir/build.make
DBMS-sql: CMakeFiles/DBMS-sql.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DBMS-sql"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DBMS-sql.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DBMS-sql.dir/build: DBMS-sql

.PHONY : CMakeFiles/DBMS-sql.dir/build

CMakeFiles/DBMS-sql.dir/requires: CMakeFiles/DBMS-sql.dir/main.cpp.o.requires
CMakeFiles/DBMS-sql.dir/requires: CMakeFiles/DBMS-sql.dir/Database.cpp.o.requires
CMakeFiles/DBMS-sql.dir/requires: CMakeFiles/DBMS-sql.dir/Book.cpp.o.requires

.PHONY : CMakeFiles/DBMS-sql.dir/requires

CMakeFiles/DBMS-sql.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DBMS-sql.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DBMS-sql.dir/clean

CMakeFiles/DBMS-sql.dir/depend:
	cd "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql" "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql" "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug" "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug" "/Users/michaelrokitko/Desktop/לימודים שנקר/nudler/DBMS-sql/cmake-build-debug/CMakeFiles/DBMS-sql.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DBMS-sql.dir/depend

