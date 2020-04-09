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

# ============================================================================
# directories
# ============================================================================

# check for availability of wxWidgets library

# By default, build applications
set(BUILD_APPLICATIONS_DEFAULT OFF)

# By default, do not regenerate .rst files of command help pages
option(BUILD_DOCUMENTATION_SOURCES "Regenerate help of commands in reStructuredText format when missing" OFF)

# By default, most modules are enabled already...
mark_as_advanced(BUILD_ALL_MODULES)

# Testing is yet very limited, hence mark this option as advanced for now
#mark_as_advanced(BUILD_TESTING)

# Installation directories
if (WIN32)
  set(INSTALL_CMAKE_MODULES_DIR "${INSTALL_SHARE_DIR}/CMake")
  set(MIRTK_TOOLS_DIR           "${INSTALL_LIBEXEC_DIR}/Tools")
else ()
  set(INSTALL_CMAKE_MODULES_DIR "${INSTALL_SHARE_DIR}/cmake")
  set(MIRTK_TOOLS_DIR           "${INSTALL_LIBEXEC_DIR}/tools")
endif ()

set (BASIS_DEBUG TRUE)
# set (BASIS_USE_FULLY_QUALIFIED_TARGET_UIDS 	 ON)
# set (BASIS_USE_TARGET_UIDS  TRUE)
#set (BASIS_SUPERBUILD_MODULES  TRUE)
