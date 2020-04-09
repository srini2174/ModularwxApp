# ============================================================================
# Copyright (c) 2018 <provider-name>
# All rights reserved.
#
# See COPYING file for license information.
# ============================================================================

##############################################################################
# @file  CMakeLists.txt
# @brief Root build configuration file.
#
# @note Based on <a href="https://cmake-basis.github.io">CMake BASIS</a>.
##############################################################################

# ----------------------------------------------------------------------------
# minimum required CMake version
cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)
set (MINIMUM_BASIS_VERSION "3.3.0")

# ----------------------------------------------------------------------------
# include BASIS policies, settings, macros, and functions

set (PROJECT_CONFIG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/config")
set (CMAKE_MODULE_PATH  "${PROJECT_CONFIG_DIR}" ${CMAKE_MODULE_PATH})

# ----------------------------------------------------------------------------
# configure build system
basis_project_impl ()
