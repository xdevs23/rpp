# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/cmake/252/bin/cmake

# The command to remove a file.
RM = /snap/cmake/252/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mvx/git/AMDRPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mvx/git/AMDRPP/build

# Utility rule file for tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.

# Include the progress variables for this target.
include src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/progress.make

src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mvx/git/AMDRPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "clang-tidy: Running clang-tidy on target /home/mvx/git/AMDRPP/src/modules/rppi_computer_vision.cpp..."
	cd /home/mvx/git/AMDRPP/src/modules && /usr/bin/clang-tidy -quiet -p /home/mvx/git/AMDRPP/build -checks='*,-cert-env33-c,-android-cloexec-fopen,-cert-msc30-c,-cert-msc50-cpp,-clang-analyzer-alpha.core.CastToStruct,-clang-analyzer-optin.performance.Padding,-clang-diagnostic-deprecated-declarations,-clang-diagnostic-extern-c-compat,-clang-diagnostic-unused-command-line-argument,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,-cppcoreguidelines-pro-bounds-constant-array-index,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-pro-type-member-init,-cppcoreguidelines-pro-type-reinterpret-cast,-cppcoreguidelines-pro-type-union-access,-cppcoreguidelines-pro-type-vararg,-cppcoreguidelines-special-member-functions,-fuchsia-*,-google-explicit-constructor,-google-readability-braces-around-statements,-google-readability-todo,-google-runtime-int,-google-runtime-references,-hicpp-braces-around-statements,-hicpp-explicit-conversions,-hicpp-no-array-decay,-hicpp-signed-bitwise,-hicpp-special-member-functions,-hicpp-use-equals-default,-hicpp-use-override,-llvm-header-guard,-llvm-include-order,-misc-misplaced-const,-modernize-pass-by-value,-modernize-use-default-member-init,-modernize-use-equals-default,-modernize-use-transparent-functors,-performance-unnecessary-value-param,-readability-braces-around-statements,-readability-else-after-return,-readability-named-parameter,-hicpp-use-auto,-modernize-use-auto,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cppcoreguidelines-macro-usage,-misc-non-private-member-variables-in-classes,-cppcoreguidelines-non-private-member-variables-in-classes,-readability-isolate-declaration,-cppcoreguidelines-avoid-c-arrays,-hicpp-avoid-c-arrays,-modernize-avoid-c-arrays,-readability-uppercase-literal-suffix,-hicpp-uppercase-literal-suffix,-cert-msc32-c,-cert-msc51-cpp,-bugprone-exception-escape' -warnings-as-errors='*,-readability-inconsistent-declaration-parameter-name' -extra-arg=-DMIOPEN_USE_CLANG_TIDY -header-filter='.*hpp' /home/mvx/git/AMDRPP/src/modules/rppi_computer_vision.cpp -export-fixes=/home/mvx/git/AMDRPP/build/fixits/modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.yaml

tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp: src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp
tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp: src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/build.make

.PHONY : tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp

# Rule to build all files generated by this target.
src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/build: tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp

.PHONY : src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/build

src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/clean:
	cd /home/mvx/git/AMDRPP/build/src/modules && $(CMAKE_COMMAND) -P CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/cmake_clean.cmake
.PHONY : src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/clean

src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/depend:
	cd /home/mvx/git/AMDRPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mvx/git/AMDRPP /home/mvx/git/AMDRPP/src/modules /home/mvx/git/AMDRPP/build /home/mvx/git/AMDRPP/build/src/modules /home/mvx/git/AMDRPP/build/src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/depend

