# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build"

# Include any dependencies generated for this target.
include bin/CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/hello.dir/flags.make

bin/CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.o: bin/CMakeFiles/hello.dir/flags.make
bin/CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.o: ../src/hello_proto/hello_rpc_client.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.o"
	cd "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/bin" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.o -c "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/src/hello_proto/hello_rpc_client.cc"

bin/CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.i"
	cd "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/bin" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/src/hello_proto/hello_rpc_client.cc" > CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.i

bin/CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.s"
	cd "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/bin" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/src/hello_proto/hello_rpc_client.cc" -o CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

bin/hello: bin/CMakeFiles/hello.dir/hello_proto/hello_rpc_client.cc.o
bin/hello: bin/CMakeFiles/hello.dir/build.make
bin/hello: bin/libraft_proj.a
bin/hello: /usr/local/lib/libboost_thread-mt.dylib
bin/hello: /usr/local/lib/libboost_log-mt.dylib
bin/hello: /usr/local/lib/libboost_unit_test_framework-mt.dylib
bin/hello: /usr/local/lib/libboost_serialization-mt.dylib
bin/hello: /usr/local/lib/libboost_chrono-mt.dylib
bin/hello: /usr/local/lib/libboost_system-mt.dylib
bin/hello: /usr/local/lib/libboost_date_time-mt.dylib
bin/hello: /usr/local/lib/libboost_atomic-mt.dylib
bin/hello: /usr/local/lib/libboost_log_setup-mt.dylib
bin/hello: /usr/local/lib/libboost_filesystem-mt.dylib
bin/hello: /usr/local/lib/libboost_regex-mt.dylib
bin/hello: /usr/local/lib/libprotobuf.dylib
bin/hello: /usr/local/lib/libgrpc++.dylib
bin/hello: /usr/local/lib/libgrpc.dylib
bin/hello: /usr/local/lib/libgpr.dylib
bin/hello: bin/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello"
	cd "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/bin" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/hello.dir/build: bin/hello

.PHONY : bin/CMakeFiles/hello.dir/build

bin/CMakeFiles/hello.dir/clean:
	cd "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/bin" && $(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/hello.dir/clean

bin/CMakeFiles/hello.dir/depend:
	cd "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft" "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/src" "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build" "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/bin" "/Users/qiansucheng/Desktop/ACM班/2018夏/ppca/Distributed System/Raft Proj/Raft/build/bin/CMakeFiles/hello.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : bin/CMakeFiles/hello.dir/depend

