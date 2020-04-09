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

# CMake >=3.15 warns if top-level CMakeLists.txt contains no project command
basis_project_args(ARGS)
project(${ARGS})
unset(ARGS)

set (CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/config" ${CMAKE_MODULE_PATH})

foreach (MODULE_DIR IN LISTS CMAKE_MODULE_PATH)
    find_path(BOOTSTRAPPING_SCRIPT_DIR NAMES "BasisBootstrapping.cmake" PATHS ${MODULE_DIR})
endforeach()

if (BOOTSTRAPPING_SCRIPT_DIR)
    #Bootstrap the BASIS module
    include ("${BOOTSTRAPPING_SCRIPT_DIR}/BasisBootstrapping.cmake")
endif()

#use only the cmake-basis modules
if (NOT BASIS_MODULE_PATH)
    basis_bootstrap_module(
        VERSION 3.3.0                           # CMake BASIS version to download
        ARCHIVE_DIR     "${CMAKE_MODULE_PATH}"  #The config folder contains a copy of the BASIS repository
        )
    set(BASIS_MODULE_PATH "${BASIS_CMAKE_MODULES_DIR}")
endif()

# look for an existing CMake BASIS installation and use it if found
if (NOT BASIS_MODULE_PATH)
    find_package (BASIS QUIET)
    if (NOT BASIS_FOUND)

        # otherwise download and build BASIS in build tree of project
        basis_bootstrap(
            VERSION 3.3.0          # CMake BASIS version to download

            USE_MATLAB       FALSE # Enable/disable Matlab support
            USE_PythonInterp FALSE # Enable/disable Python support
            USE_JythonInterp FALSE # Enable/disable Jython support
            USE_Perl         FALSE # Enable/disalbe Perl   support
            USE_BASH         FALSE # Enable/disable Bash   support
            USE_Doxygen      FALSE # Enable/disable documentation generation using Doxygen
            USE_Sphinx       FALSE # Enable/disable documentation generation using Sphinx
            USE_ITK          FALSE # Enable/disable image processing regression testing
            CONFIGURE_ONLY   TRUE  # Basis only needs to be configured.  We do not need the Perl and Python Modules
            ARCHIVE_DIR     "${CMAKE_MODULE_PATH}" #The config folder contains a copy of the BASIS repository
            #INFORM_USER     FALSE # Inform user during first configure step that BASIS needs to be bootstrapped or installed manually
            #    BASIS_COMPILE_SCRIPTS FALSE
            #    BUILD_DOCUMENTATION FALSE
            #    BUILD_EXAMPLE FALSE
            #    BUILD_TESTING FALSE
            #    BUILD_BASIS_UTILITIES_FOR_CXX FALSE
            #    BUILD_BASIS_UTILITIES_FOR_PERL FALSE
            #    BUILD_BASIS_UTILITIES_FOR_PYTHON FALSE
            )

        # circumvent issue with CMake's find_package() interpreting these variables
        # relative to the current binary directory instead of the top-level directory
        if (BASIS_DIR AND NOT IS_ABSOLUTE "${BASIS_DIR}")
            set (BASIS_DIR "${CMAKE_BINARY_DIR}/${BASIS_DIR}")
            get_filename_component (BASIS_DIR "${BASIS_DIR}" ABSOLUTE)
        endif ()

        set(DEPENDS_BASIS_DIR "${BASIS_DIR}")
        set(BASIS_ROOT "${BASIS_DIR}")
        set(BASIS_DIR  "${BASIS_ROOT}/CMake")

        # look for local installation
        find_package (BASIS QUIET)
        if (NOT BASIS_FOUND)
            message (FATAL_ERROR "Automatic CMake BASIS setup failed! Please install BASIS manually.")
        endif ()
        message("Basis package found successfully")
    endif ()
endif()

include ("${BASIS_MODULE_PATH}/BasisSettings.cmake" NO_POLICY_SCOPE)
include ("${BASIS_MODULE_PATH}/BasisTools.cmake")

# ----------------------------------------------------------------------------
# configure build system
basis_project_impl ()


