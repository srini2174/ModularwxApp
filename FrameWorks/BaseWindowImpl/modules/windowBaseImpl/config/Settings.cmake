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

# check for availability of wxWidgets library
if (CMAKE_COMPILER_IS_GNUCXX)
    set (wxWidgets_ROOT_DIR 		"C:/ProgramFiles/wxWidgets/gcc71_x64" CACHE PATH "wxWidgets_ROOT_DIR")
    set (wxWidgets_LIB_DIR  		"${wxWidgets_ROOT_DIR}/gcc71_x64/lib" CACHE PATH "wxWidgets_LIB_DIR")
    set (wxWidgets_CONFIGURATION 	"gcc_dll/mswud")
elseif(MSVC)
    message("The selected compiler is MSVC")
 #   set (WX_ROOT_DIR                "C:/ProgramFiles/wxWidgets/vc15_x64" CACHE PATH "WX_ROOT_DIR")
    set (wxWidgets_ROOT_DIR 		"C:/ProgramFiles/wxWidgets/vc15_x64" CACHE PATH "wxWidgets_ROOT_DIR")
    set (wxWidgets_LIB_DIR  		"${wxWidgets_ROOT_DIR}/lib" CACHE PATH "wxWidgets_LIB_DIR")
    set (wxWidgets_CONFIGURATION 	"vc_x64_dll/mswud")
endif()


# Here we specify that we need DLL version of wxWidgets libs and dynamic CRT
# This is a MUST for applications with plugins. Both app and DLL plugin MUST
# use the same instance of wxWidgets and the same event loop.
#set(BUILD_SHARED_LIBS 1)

# Find wxWidgets library on current PC
# You should have %WXWIN%  environment variable which should point to the
# directory where wxWidgets source code is placed.
# wxWidgets libs MUST be compiled for both Debug and Release versions
find_package(wxWidgets COMPONENTS core base REQUIRED)


# This should be done only if it is windows, otherwise the individual compiler options needs to be added explicitly
if (wxWidgets_FOUND)

    add_definitions(-DwxUSE_UNICODE_MSLU)
    add_definitions(-DWXMAKINGDLL_GUIWINBASE)
    add_definitions(-DWXUSINGDLL_GUIBASE)
    
    if (WIN32)
    # check for availability of wxWidgets library
    if (CMAKE_COMPILER_IS_GNUCXX)
        add_compile_options(-mthreads)
        add_compile_options(-Wno-ctor-dtor-privacy -pipe -fmessage-length=0)
    elseif(MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /wd4996")
        add_definitions(/D__STDC_CONSTANT_MACROS)
    endif()
        add_definitions(-DHAVE_W32API_H)
        add_definitions(-D__WXMSW__)
    endif(WIN32)
    include( ${wxWidgets_USE_FILE} )
    
endif (wxWidgets_FOUND)

if (BASIS_DEBUG)
  basis_dump_variables ("${PROJECT_BINARY_DIR}/VariablesAfterDetectionOfModules.cmake")
endif ()
