# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rayaanirani/Desktop/Sentiment-Analyizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SentimentAnalyzer.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/SentimentAnalyzer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SentimentAnalyzer.dir/flags.make

CMakeFiles/SentimentAnalyzer.dir/main.cpp.o: CMakeFiles/SentimentAnalyzer.dir/flags.make
CMakeFiles/SentimentAnalyzer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SentimentAnalyzer.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentimentAnalyzer.dir/main.cpp.o -c /Users/rayaanirani/Desktop/Sentiment-Analyizer/main.cpp

CMakeFiles/SentimentAnalyzer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentimentAnalyzer.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/Sentiment-Analyizer/main.cpp > CMakeFiles/SentimentAnalyzer.dir/main.cpp.i

CMakeFiles/SentimentAnalyzer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentimentAnalyzer.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/Sentiment-Analyizer/main.cpp -o CMakeFiles/SentimentAnalyzer.dir/main.cpp.s

CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.o: CMakeFiles/SentimentAnalyzer.dir/flags.make
CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.o: ../DSString.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.o -c /Users/rayaanirani/Desktop/Sentiment-Analyizer/DSString.cpp

CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/Sentiment-Analyizer/DSString.cpp > CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.i

CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/Sentiment-Analyizer/DSString.cpp -o CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.s

CMakeFiles/SentimentAnalyzer.dir/tests.cpp.o: CMakeFiles/SentimentAnalyzer.dir/flags.make
CMakeFiles/SentimentAnalyzer.dir/tests.cpp.o: ../tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SentimentAnalyzer.dir/tests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentimentAnalyzer.dir/tests.cpp.o -c /Users/rayaanirani/Desktop/Sentiment-Analyizer/tests.cpp

CMakeFiles/SentimentAnalyzer.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentimentAnalyzer.dir/tests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/Sentiment-Analyizer/tests.cpp > CMakeFiles/SentimentAnalyzer.dir/tests.cpp.i

CMakeFiles/SentimentAnalyzer.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentimentAnalyzer.dir/tests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/Sentiment-Analyizer/tests.cpp -o CMakeFiles/SentimentAnalyzer.dir/tests.cpp.s

CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.o: CMakeFiles/SentimentAnalyzer.dir/flags.make
CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.o: ../Train_Tweet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.o -c /Users/rayaanirani/Desktop/Sentiment-Analyizer/Train_Tweet.cpp

CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/Sentiment-Analyizer/Train_Tweet.cpp > CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.i

CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/Sentiment-Analyizer/Train_Tweet.cpp -o CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.s

CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.o: CMakeFiles/SentimentAnalyzer.dir/flags.make
CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.o: ../Test_Tweet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.o -c /Users/rayaanirani/Desktop/Sentiment-Analyizer/Test_Tweet.cpp

CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/Sentiment-Analyizer/Test_Tweet.cpp > CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.i

CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/Sentiment-Analyizer/Test_Tweet.cpp -o CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.s

CMakeFiles/SentimentAnalyzer.dir/manager.cpp.o: CMakeFiles/SentimentAnalyzer.dir/flags.make
CMakeFiles/SentimentAnalyzer.dir/manager.cpp.o: ../manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SentimentAnalyzer.dir/manager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentimentAnalyzer.dir/manager.cpp.o -c /Users/rayaanirani/Desktop/Sentiment-Analyizer/manager.cpp

CMakeFiles/SentimentAnalyzer.dir/manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentimentAnalyzer.dir/manager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/Sentiment-Analyizer/manager.cpp > CMakeFiles/SentimentAnalyzer.dir/manager.cpp.i

CMakeFiles/SentimentAnalyzer.dir/manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentimentAnalyzer.dir/manager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/Sentiment-Analyizer/manager.cpp -o CMakeFiles/SentimentAnalyzer.dir/manager.cpp.s

# Object files for target SentimentAnalyzer
SentimentAnalyzer_OBJECTS = \
"CMakeFiles/SentimentAnalyzer.dir/main.cpp.o" \
"CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.o" \
"CMakeFiles/SentimentAnalyzer.dir/tests.cpp.o" \
"CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.o" \
"CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.o" \
"CMakeFiles/SentimentAnalyzer.dir/manager.cpp.o"

# External object files for target SentimentAnalyzer
SentimentAnalyzer_EXTERNAL_OBJECTS =

SentimentAnalyzer: CMakeFiles/SentimentAnalyzer.dir/main.cpp.o
SentimentAnalyzer: CMakeFiles/SentimentAnalyzer.dir/DSString.cpp.o
SentimentAnalyzer: CMakeFiles/SentimentAnalyzer.dir/tests.cpp.o
SentimentAnalyzer: CMakeFiles/SentimentAnalyzer.dir/Train_Tweet.cpp.o
SentimentAnalyzer: CMakeFiles/SentimentAnalyzer.dir/Test_Tweet.cpp.o
SentimentAnalyzer: CMakeFiles/SentimentAnalyzer.dir/manager.cpp.o
SentimentAnalyzer: CMakeFiles/SentimentAnalyzer.dir/build.make
SentimentAnalyzer: CMakeFiles/SentimentAnalyzer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable SentimentAnalyzer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SentimentAnalyzer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SentimentAnalyzer.dir/build: SentimentAnalyzer
.PHONY : CMakeFiles/SentimentAnalyzer.dir/build

CMakeFiles/SentimentAnalyzer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SentimentAnalyzer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SentimentAnalyzer.dir/clean

CMakeFiles/SentimentAnalyzer.dir/depend:
	cd /Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rayaanirani/Desktop/Sentiment-Analyizer /Users/rayaanirani/Desktop/Sentiment-Analyizer /Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug /Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug /Users/rayaanirani/Desktop/Sentiment-Analyizer/cmake-build-debug/CMakeFiles/SentimentAnalyzer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SentimentAnalyzer.dir/depend

