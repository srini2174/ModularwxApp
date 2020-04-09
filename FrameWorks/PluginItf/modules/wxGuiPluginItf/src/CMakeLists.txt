# ============================================================================
# Copyright (c) 2018 <provider-name>
# All rights reserved.
#
# See COPYING file for license information.
# ============================================================================

##############################################################################
# @file  CMakeLists.txt
# @brief Build configuration of software.
##############################################################################

# ============================================================================
# library target(s)
# ============================================================================

# Add library target for each library using basis_add_library().
#
# This command can not only be used to build libraries from C/C++, but also source
# code written in other programming languages such as Java, Python, Perl,
# MATLAB, and Bash. Note that here we consider modules written in a scripting
# language which are no executables but to be included by other scripts written
# in the particular language as libraries.
#
# Note: Public modules written in a scripting language such as Python, Perl,
#       MATLAB, or Bash which are intended for use by other packages should
#       be placed in the lib/[<lang>/]module-a/ directory,
#       where <lang> is the language name in lowercase and is optional.
#       BASIS will automatically add a library build target for these modules.



# ============================================================================
# executable target(s)
# ============================================================================

# Add executable target for each executable program using basis_add_executable().
#
# This command can not only be used to build executables from C/C++, but also
# source code written in other programming languages such as Java, Python, Perl,
# MATLAB, and Bash.

#message ("The value of wxWidgets_DEFINITIONS is ${wxWidgets_DEFINITIONS}")
#message ("The value of wxWidgets_CXX_FLAGS is ${wxWidgets_CXX_FLAGS}")
#message ("The value of wxWidgets_LIBRARY_DIRS is ${wxWidgets_LIBRARY_DIRS}")
#message ("The value of wxWidgets_LIBRARIES is ${wxWidgets_LIBRARIES}")
#message ("The value of wxWidgets_USE_FILE is ${wxWidgets_USE_FILE}")

#message("The value of wxWidgets_LIBRARY_DIRS ${wxWidgets_LIBRARY_DIRS}")

cmake_policy(SET CMP0043 OLD)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
basis_add_library(wxGuiPluginItf SHARED wxGuiPluginBase.cpp)
basis_link_directories(${wxWidgets_LIBRARY_DIRS})
target_link_libraries(wxGuiPluginItf ${wxWidgets_LIBRARIES})
