# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build

# Include any dependencies generated for this target.
include CMakeFiles/opend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/opend.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/opend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opend.dir/flags.make

CMakeFiles/opend.dir/serv_main.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/serv_main.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_main.c
CMakeFiles/opend.dir/serv_main.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/opend.dir/serv_main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/serv_main.c.o -MF CMakeFiles/opend.dir/serv_main.c.o.d -o CMakeFiles/opend.dir/serv_main.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_main.c

CMakeFiles/opend.dir/serv_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/serv_main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_main.c > CMakeFiles/opend.dir/serv_main.c.i

CMakeFiles/opend.dir/serv_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/serv_main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_main.c -o CMakeFiles/opend.dir/serv_main.c.s

CMakeFiles/opend.dir/daemonize.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/daemonize.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/daemonize.c
CMakeFiles/opend.dir/daemonize.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/opend.dir/daemonize.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/daemonize.c.o -MF CMakeFiles/opend.dir/daemonize.c.o.d -o CMakeFiles/opend.dir/daemonize.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/daemonize.c

CMakeFiles/opend.dir/daemonize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/daemonize.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/daemonize.c > CMakeFiles/opend.dir/daemonize.c.i

CMakeFiles/opend.dir/daemonize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/daemonize.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/daemonize.c -o CMakeFiles/opend.dir/daemonize.c.s

CMakeFiles/opend.dir/loop.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/loop.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/loop.c
CMakeFiles/opend.dir/loop.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/opend.dir/loop.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/loop.c.o -MF CMakeFiles/opend.dir/loop.c.o.d -o CMakeFiles/opend.dir/loop.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/loop.c

CMakeFiles/opend.dir/loop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/loop.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/loop.c > CMakeFiles/opend.dir/loop.c.i

CMakeFiles/opend.dir/loop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/loop.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/loop.c -o CMakeFiles/opend.dir/loop.c.s

CMakeFiles/opend.dir/client.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/client.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/client.c
CMakeFiles/opend.dir/client.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/opend.dir/client.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/client.c.o -MF CMakeFiles/opend.dir/client.c.o.d -o CMakeFiles/opend.dir/client.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/client.c

CMakeFiles/opend.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/client.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/client.c > CMakeFiles/opend.dir/client.c.i

CMakeFiles/opend.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/client.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/client.c -o CMakeFiles/opend.dir/client.c.s

CMakeFiles/opend.dir/serv_listen.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/serv_listen.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_listen.c
CMakeFiles/opend.dir/serv_listen.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/opend.dir/serv_listen.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/serv_listen.c.o -MF CMakeFiles/opend.dir/serv_listen.c.o.d -o CMakeFiles/opend.dir/serv_listen.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_listen.c

CMakeFiles/opend.dir/serv_listen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/serv_listen.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_listen.c > CMakeFiles/opend.dir/serv_listen.c.i

CMakeFiles/opend.dir/serv_listen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/serv_listen.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_listen.c -o CMakeFiles/opend.dir/serv_listen.c.s

CMakeFiles/opend.dir/serv_accept.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/serv_accept.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_accept.c
CMakeFiles/opend.dir/serv_accept.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/opend.dir/serv_accept.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/serv_accept.c.o -MF CMakeFiles/opend.dir/serv_accept.c.o.d -o CMakeFiles/opend.dir/serv_accept.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_accept.c

CMakeFiles/opend.dir/serv_accept.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/serv_accept.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_accept.c > CMakeFiles/opend.dir/serv_accept.c.i

CMakeFiles/opend.dir/serv_accept.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/serv_accept.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/serv_accept.c -o CMakeFiles/opend.dir/serv_accept.c.s

CMakeFiles/opend.dir/handle_request.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/handle_request.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/handle_request.c
CMakeFiles/opend.dir/handle_request.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/opend.dir/handle_request.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/handle_request.c.o -MF CMakeFiles/opend.dir/handle_request.c.o.d -o CMakeFiles/opend.dir/handle_request.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/handle_request.c

CMakeFiles/opend.dir/handle_request.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/handle_request.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/handle_request.c > CMakeFiles/opend.dir/handle_request.c.i

CMakeFiles/opend.dir/handle_request.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/handle_request.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/handle_request.c -o CMakeFiles/opend.dir/handle_request.c.s

CMakeFiles/opend.dir/buf_args.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/buf_args.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/buf_args.c
CMakeFiles/opend.dir/buf_args.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/opend.dir/buf_args.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/buf_args.c.o -MF CMakeFiles/opend.dir/buf_args.c.o.d -o CMakeFiles/opend.dir/buf_args.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/buf_args.c

CMakeFiles/opend.dir/buf_args.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/buf_args.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/buf_args.c > CMakeFiles/opend.dir/buf_args.c.i

CMakeFiles/opend.dir/buf_args.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/buf_args.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/buf_args.c -o CMakeFiles/opend.dir/buf_args.c.s

CMakeFiles/opend.dir/cli_args.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/cli_args.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/cli_args.c
CMakeFiles/opend.dir/cli_args.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/opend.dir/cli_args.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/cli_args.c.o -MF CMakeFiles/opend.dir/cli_args.c.o.d -o CMakeFiles/opend.dir/cli_args.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/cli_args.c

CMakeFiles/opend.dir/cli_args.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/cli_args.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/cli_args.c > CMakeFiles/opend.dir/cli_args.c.i

CMakeFiles/opend.dir/cli_args.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/cli_args.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/cli_args.c -o CMakeFiles/opend.dir/cli_args.c.s

CMakeFiles/opend.dir/send_err.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/send_err.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/send_err.c
CMakeFiles/opend.dir/send_err.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/opend.dir/send_err.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/send_err.c.o -MF CMakeFiles/opend.dir/send_err.c.o.d -o CMakeFiles/opend.dir/send_err.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/send_err.c

CMakeFiles/opend.dir/send_err.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/send_err.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/send_err.c > CMakeFiles/opend.dir/send_err.c.i

CMakeFiles/opend.dir/send_err.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/send_err.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/send_err.c -o CMakeFiles/opend.dir/send_err.c.s

CMakeFiles/opend.dir/send_fd.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/send_fd.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/send_fd.c
CMakeFiles/opend.dir/send_fd.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/opend.dir/send_fd.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/send_fd.c.o -MF CMakeFiles/opend.dir/send_fd.c.o.d -o CMakeFiles/opend.dir/send_fd.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/send_fd.c

CMakeFiles/opend.dir/send_fd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/send_fd.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/send_fd.c > CMakeFiles/opend.dir/send_fd.c.i

CMakeFiles/opend.dir/send_fd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/send_fd.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/send_fd.c -o CMakeFiles/opend.dir/send_fd.c.s

CMakeFiles/opend.dir/readn_writen.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/readn_writen.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/readn_writen.c
CMakeFiles/opend.dir/readn_writen.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/opend.dir/readn_writen.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/readn_writen.c.o -MF CMakeFiles/opend.dir/readn_writen.c.o.d -o CMakeFiles/opend.dir/readn_writen.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/readn_writen.c

CMakeFiles/opend.dir/readn_writen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/readn_writen.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/readn_writen.c > CMakeFiles/opend.dir/readn_writen.c.i

CMakeFiles/opend.dir/readn_writen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/readn_writen.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/readn_writen.c -o CMakeFiles/opend.dir/readn_writen.c.s

CMakeFiles/opend.dir/log.c.o: CMakeFiles/opend.dir/flags.make
CMakeFiles/opend.dir/log.c.o: /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/log.c
CMakeFiles/opend.dir/log.c.o: CMakeFiles/opend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/opend.dir/log.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/opend.dir/log.c.o -MF CMakeFiles/opend.dir/log.c.o.d -o CMakeFiles/opend.dir/log.c.o -c /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/log.c

CMakeFiles/opend.dir/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opend.dir/log.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/log.c > CMakeFiles/opend.dir/log.c.i

CMakeFiles/opend.dir/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opend.dir/log.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/log.c -o CMakeFiles/opend.dir/log.c.s

# Object files for target opend
opend_OBJECTS = \
"CMakeFiles/opend.dir/serv_main.c.o" \
"CMakeFiles/opend.dir/daemonize.c.o" \
"CMakeFiles/opend.dir/loop.c.o" \
"CMakeFiles/opend.dir/client.c.o" \
"CMakeFiles/opend.dir/serv_listen.c.o" \
"CMakeFiles/opend.dir/serv_accept.c.o" \
"CMakeFiles/opend.dir/handle_request.c.o" \
"CMakeFiles/opend.dir/buf_args.c.o" \
"CMakeFiles/opend.dir/cli_args.c.o" \
"CMakeFiles/opend.dir/send_err.c.o" \
"CMakeFiles/opend.dir/send_fd.c.o" \
"CMakeFiles/opend.dir/readn_writen.c.o" \
"CMakeFiles/opend.dir/log.c.o"

# External object files for target opend
opend_EXTERNAL_OBJECTS =

opend: CMakeFiles/opend.dir/serv_main.c.o
opend: CMakeFiles/opend.dir/daemonize.c.o
opend: CMakeFiles/opend.dir/loop.c.o
opend: CMakeFiles/opend.dir/client.c.o
opend: CMakeFiles/opend.dir/serv_listen.c.o
opend: CMakeFiles/opend.dir/serv_accept.c.o
opend: CMakeFiles/opend.dir/handle_request.c.o
opend: CMakeFiles/opend.dir/buf_args.c.o
opend: CMakeFiles/opend.dir/cli_args.c.o
opend: CMakeFiles/opend.dir/send_err.c.o
opend: CMakeFiles/opend.dir/send_fd.c.o
opend: CMakeFiles/opend.dir/readn_writen.c.o
opend: CMakeFiles/opend.dir/log.c.o
opend: CMakeFiles/opend.dir/build.make
opend: CMakeFiles/opend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable opend"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opend.dir/build: opend
.PHONY : CMakeFiles/opend.dir/build

CMakeFiles/opend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opend.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opend.dir/clean

CMakeFiles/opend.dir/depend:
	cd /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2 /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2 /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build /Users/ryanlu/Project/CPrj/APUE/17_advanced_IPC/open_server_v2/build/CMakeFiles/opend.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opend.dir/depend

