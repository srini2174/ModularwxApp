# ============================================================================
# Copyright (c) 2011-2012 University of Pennsylvania
# Copyright (c) 2013-2016 Andreas Schuh
# All rights reserved.
#
# See COPYING file for license information or visit
# https://cmake-basis.github.io/download.html#license
# ============================================================================

##############################################################################
# @file  Settings.cmake
# @brief Non-default project settings.
#
# This file is included by basis_project_impl() after it looked for the
# required and optional dependencies and the CMake variables related to the
# project directory structure were defined (see BASISDirectories.cmake file
# in @c PROJECT_BINARY_DIR, where BASIS is here the name of the project).
# It is also included before the BasisSettings.cmake file.
#
# In particular, build options should be added in this file using CMake's
# <a href="http://www.cmake.org/cmake/help/cmake-2-8-docs.html#command:option">
# option()</a> command. Further, any common settings related to using a found
# dependency can be set here if the basis_use_package() command was enable
# to import the required configuration of a particular external package.
#
# @ingroup BasisSettings
##############################################################################

message(STATUS "In Settings.cmake file I am Looking for the PluginItf")
basis_find_package(PluginsItfFW)

# This should be done only if it is windows, otherwise the individual compiler options needs to be added explicitly
if (PluginsItfFW_FOUND)
    message(STATUS "PluginsItfFW is found")
endif (PluginsItfFW_FOUND)

