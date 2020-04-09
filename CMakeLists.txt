##############################################################################
# @file  CMakeLists.txt
# @brief CMake configuration of bundle.
#
# Copyright (c) 2012 University of Pennsylvania. All rights reserved.
# See http://www.cbica.upenn.edu/sbia/software/license.html or COPYING file.
#
# Contact: SBIA Group <sbia-software at uphs.upenn.edu>
##############################################################################

# ----------------------------------------------------------------------------
# Minimum required CMake version
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

# ----------------------------------------------------------------------------
# Include BASIS policies, settings, macros, and functions
set(BASIS_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Basis")
set(MIRTK_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules")
set(CMAKE_MODULE_PATH "${MIRTK_MODULE_PATH}" "${BASIS_MODULE_PATH}")

include(mirtkPolicies NO_POLICY_SCOPE)

include(BasisSettings)
include(BasisTools)
include(mirtkTools)

# ----------------------------------------------------------------------------
# Default settings
#
# These variables have to be set before (mirtk|basis)_project_begin.
# See CMake/Config/Settings.cmake file for other settings.

# By default, require these optional dependencies such that the library
# features which depend on these external libraries are available
if (UNIX)
  set(WITH_ZLIB_DEFAULT ON)
endif ()

# ThirdParty/Eigen
# if (NOT Eigen3_DIR)
#   if (Eigen3_INCLUDE_DIR)
#     set(Eigen3_DIR "${Eigen3_INCLUDE_DIR}")
#   elseif (EIGEN3_INCLUDE_DIR)
#     set(Eigen3_DIR "${EIGEN3_INCLUDE_DIR}")
#   elseif (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/Eigen/signature_of_eigen3_matrix_library")
#     set(Eigen3_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/Eigen")
#   endif ()
# endif ()

# ----------------------------------------------------------------------------
# Configure build system

# CMake >=3.15 warns if top-level CMakeLists.txt contains no project command
basis_project_args(ARGS)
project(${ARGS})
unset(ARGS)

# Initialize project
mirtk_project_begin()

# Reset global properties used to collect information about MIRTK commands
# and the LD_LIBRARY_PATH of external libraries required by these
set_property(GLOBAL PROPERTY MIRTK_COMMANDS     "")
set_property(GLOBAL PROPERTY MIRTK_LIBRARY_PATH "")

# Process modules
foreach (MODULE IN LISTS PROJECT_MODULES_ENABLED)
  basis_add_module(${MODULE})
  basis_use_module(${MODULE})
endforeach ()

# Process subdirectories
foreach (SUBDIR IN LISTS PROJECT_SUBDIRS)
  basis_add_subdirectory(${SUBDIR})
endforeach ()

# Finalize project
mirtk_project_end()
