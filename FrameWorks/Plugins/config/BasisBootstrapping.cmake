##############################################################################
# @file  BasisBootstrapping.cmake
# @brief Auxiliary function to bootstrap the build of CMake BASIS.
##############################################################################

#=============================================================================
# Copyright 2014-2016 Andreas Schuh
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# 
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#   documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#=============================================================================

# ----------------------------------------------------------------------------
## @brief Boostrap build of CMake BASIS during configuration of project.
#
# This function downloads, configures, and builds CMake BASIS. If the (cached)
# variable @c BASIS_INSTALL_PREFIX is set, it also installs BASIS into the
# specified directory. This is only required if the project uses the
# BASIS Utilities. Otherwise, the BASIS build tree can be used directly to
# build the software project which bootstrapped BASIS. It is not required
# during runtime of the software.
#
# @param[in] ARGN The list of arguments is parsed as follows:
# @par
# <table border=0>
#  <tr>
#    @tp @b VERSION major.minor.patch|commit @endtp
#    <td>Release, commit, or branch of CMake BASIS to download.</td>
#  </tr>
#  <tr>
#    @tp @b DOWNLOAD_URL url @endtp
#    <td>URL from which to download the CMake BASIS source distribution package.
#        The given URL can be either a complete download URL which includes the
#        package name (which must end with .tar.gz or .zip), the path of
#        a remote directory which contains the CMake BASIS packages named
#        cmake-basis-version.zip (for Windows) and cmake-basis-version.tar.gz
#        (for Unix), or the URL of a Git repository.
#        (default: https://github.com/cmake-basis/BASIS/archive/v${VERSION}.tar.gz
#                  or git@github.com:cmake-basis/BASIS.git)</td>
#  </tr>
#  <tr>
#    @tp @b INFORM_USER @endtp
#    <td>This option causes this function to abort the initial configure step
#        of CMake. It informs the user that this project required BASIS for
#        the build configuration and that it upon the next configure run it
#        will attempt to download and build BASIS automatically. It further
#        notes that the user can set the @c BASIS_DIR variable prior to the
#        next configure run in order to use an existing BASIS installation.
#        (default: off)</td>
#  </tr>
#  <tr>
#     @tp @b BASIS_VARIABLE_NAME value @endtp
#     <td>Adds a build configuration to the CMake command used to configure
#         the build of CMake BASIS using the -D option of @c cmake. The
#         @c BASIS_VARIABLE_NAME can be any CMake option or variable that
#         is normally used to configure a BASIS build using CMake. For example,
#         USE_PythonInterp, USE_BASH, USE_DOXYGEN.</td>
#  </tr>
# </table>
#
# @returns Sets the @c BASIS_DIR variable to the bootstrapped BASIS build.
function (basis_bootstrap)
    # parse arguments -- unparsed arguments are passed on to CMake using -D
    include (CMakeParseArguments)
    cmake_parse_arguments (BASIS "INFORM_USER" "VERSION;DOWNLOAD_URL;ARCHIVE_DIR;CONFIGURE_ONLY" "" ${ARGN})
    if (NOT BASIS_VERSION)
        message (FATAL_ERROR "No CMake BASIS version specified! Use 'VERSION 3.3.0', for example.")
    endif ()
    #ARCHIVE DIR and DOWNLOD _URL are mutually exclusive
    #perform the necessary checks
    if (BASIS_ARCHIVE_DIR AND BASIS_DOWNLOAD_URL)
        message (FATAL_ERROR "Options ARCHIVE_DIR and DOWNLOAD_URL are mutually exclusive!")
    endif()
    # abort the first time to give users a chance to specify where their
    # CMake BASIS installation is located by setting BASIS_DIR in the GUI
    if (BASIS_INFORM_USER)
        if (DEFINED DEPENDS_BASIS_DIR AND NOT DEFINED BASIS_INSTALL_PREFIX)
            set (BASIS_INSTALL_PREFIX "" CACHE PATH "Installation prefix for CMake BASIS.")
            message (FATAL_ERROR "Could not find an existing CMake BASIS installation!\n"
                "This project uses CMake BASIS for the build configuration."
                " Next time you configure this build by running CMake again,"
                " BASIS version ${BASIS_VERSION} will be automatically downloaded"
                " and build as part of the build configuration of this project."
                " If you want to install this version permanently,"
                " specify an installation prefix for CMake BASIS using"
                " BASIS_INSTALL_PREFIX. Otherwise, leave it blank.\n"
                "If you installed CMake BASIS already on your system, please"
                " specify its location by setting the DEPENDS_BASIS_DIR variable"
                " before you re-configure the build system of this project.\n"
                "Visit https://cmake-basis.github.io for"
                " more information about the CMake BASIS package.\n")
        endif()
    endif()

    set (COPY_SRC_URL "")
    set (DOWNLOAD_PATH "${CMAKE_CURRENT_BINARY_DIR}")
    if (BASIS_VERSION MATCHES "^[0-9]+\\.[0-9]+\\.[0-9]+(-[a-z]*)?$")
        if (WIN32)
            set (BASIS_ARCHIVE "BASIS-${BASIS_VERSION}.zip")
        else ()
            set (BASIS_ARCHIVE "BASIS-${BASIS_VERSION}.tar.gz")
        endif ()
        if (NOT BASIS_DOWNLOAD_URL)
            if (WIN32)
                set (BASIS_DOWNLOAD_URL "https://github.com/cmake-basis/BASIS/archive/v${BASIS_VERSION}.zip")
            else ()
                set (BASIS_DOWNLOAD_URL "https://github.com/cmake-basis/BASIS/archive/v${BASIS_VERSION}.tar.gz")
            endif ()
        endif ()

        if (NOT BASIS_DOWNLOAD_URL MATCHES "\\.(zip|tar\\.gz)$")
            set (BASIS_DOWNLOAD_URL "${BASIS_DOWNLOAD_URL}/${BASIS_ARCHIVE}")
        endif ()
        if (NOT COPY_SRC_URL MATCHES "\\.(zip|tar\\.gz)$")
            set (COPY_SRC_URL "${BASIS_ARCHIVE_DIR}/${BASIS_ARCHIVE}")
        endif()
    else ()
        set (BASIS_DOWNLOAD_URL "git@github.com:cmake-basis/BASIS.git")
    endif ()
    set (BASIS_SOURCE_DIR "${DOWNLOAD_PATH}/BASIS-${BASIS_VERSION}")
    set (BASIS_BINARY_DIR "${DOWNLOAD_PATH}/BASIS-${BASIS_VERSION}/build")

    # bootstrap BASIS build/installation only if not done before
    # or when BASIS_INSTALL_PREFIX has changed
    if (   NOT IS_DIRECTORY "${BASIS_BINARY_DIR}"
            OR NOT DEFINED BASIS_INSTALL_PREFIX_CONFIGURED
            OR NOT BASIS_INSTALL_PREFIX_CONFIGURED STREQUAL "${BASIS_INSTALL_PREFIX}")

        # download and extract source code if not done before
        if (NOT EXISTS "${BASIS_SOURCE_DIR}/BasisProject.cmake")

            #if ARCHIVE_DIR is defined then copy the local archive to the build directory
            #rather than downloading it
            if (BASIS_ARCHIVE_DIR)
                if (NOT EXISTS "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}")
                    if (NOT BASIS_ARCHIVE_DIR)
                        set(BASIS_ARCHIVE_DIR	"${CMAKE_MODULE_PATH}")
                    endif()
                    message (STATUS "Copying CMake BASIS v${BASIS_VERSION}... from ${BASIS_ARCHIVE_DIR}/${BASIS_ARCHIVE}"
                        " to ${DOWNLOAD_PATH}/${BASIS_ARCHIVE}")
                    if (CMAKE_COMMAND)
                        execute_process (
                            COMMAND "${CMAKE_COMMAND}" -E copy "${BASIS_ARCHIVE_DIR}/${BASIS_ARCHIVE}" "${DOWNLOAD_PATH}"
                            ERROR_VARIABLE  ERRMSG
                            RESULT_VARIABLE RETVAL
                            )
                    endif()
                endif()
                if (NOT RETVAL EQUAL 0)
                    message (FATAL_ERROR "Failed to copy CMake BASIS v${BASIS_VERSION} from\n"
                        "\t${BASIS_ARCHIVE_DIR}/${BASIS_ARCHIVE}\n"
                        "Error: ${ERRMSG}\n")
                endif ()
                message (STATUS "Copying CMake BASIS v${BASIS_VERSION}... - done")
            else() # Download using git repository or using wget or curl

                # clone Git repository and checkout specified commit/branch
                if (BASIS_DOWNLOAD_URL MATCHES ".git$")
                    find_package (Git QUIET)
                    if (NOT GIT_FOUND)
                        set (ERRMSG "Git client not found: GIT_EXECUTABLE")
                    else ()
                        mark_as_advanced (GIT_EXECUTABLE)
                        message (STATUS "Cloning CMake BASIS repository...")
                        execute_process (
                            COMMAND "${GIT_EXECUTABLE}" clone --depth=1 "${BASIS_DOWNLOAD_URL}" "${BASIS_SOURCE_DIR}"
                            RESULT_VARIABLE RETVAL
                            ERROR_VARIABLE  ERRMSG
                            )
                        if (RETVAL EQUAL 0)
                            execute_process (
                                COMMAND "${GIT_EXECUTABLE}" checkout --detach "${BASIS_VERSION}"
                                WORKING_DIRECTORY "${BASIS_SOURCE_DIR}"
                                RESULT_VARIABLE   RETVAL
                                ERROR_VARIABLE    ERRMSG
                                )
                            if (RETVAL EQUAL 0)
                                set (ERRMSG)
                                message (STATUS "Cloning CMake BASIS repository... - done")
                            endif ()
                        endif ()
                    endif () # Git not found
                    if (ERRMSG)
                        message (FATAL_ERROR "Failed to clone CMake BASIS ${BASIS_VERSION} from\n"
                            "\t${BASIS_DOWNLOAD_URL}\n"
                            "Error: ${ERRMSG}\n"
                            "Ensure GIT_EXECUTABLE is set and try again or follow the instructions at\n"
                            "\thttps://cmake-basis.github.io\n"
                            "to download and install it manually before configuring this project.\n")
                    endif ()

                else () # download using wget or curl

                    # download source code distribution package
                    if (NOT EXISTS "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}")
                        message (STATUS "Downloading CMake BASIS v${BASIS_VERSION}...")
                        find_program (CURL_EXECUTABLE NAMES curl)
                        mark_as_advanced (CURL_EXECUTABLE)
                        if (CURL_EXECUTABLE)
                            execute_process (
                                COMMAND "${CURL_EXECUTABLE}" -L -o "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}" "${BASIS_DOWNLOAD_URL}"
                                ERROR_VARIABLE  ERRMSG
                                RESULT_VARIABLE RETVAL
                                )
                        else ()
                            find_package (Wget QUIET)
                            if (WGET_EXECUTABLE)
                                execute_process (
                                    COMMAND "${WGET_EXECUTABLE}" -O "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}" "${BASIS_DOWNLOAD_URL}"
                                    ERROR_VARIABLE  ERRMSG
                                    RESULT_VARIABLE RETVAL
                                    )
                            else ()
                                set (CMAKE_USE_OPENSSL ON)
                                file (DOWNLOAD "${BASIS_DOWNLOAD_URL}" "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}" STATUS RETVAL)
                                list (GET RETVAL 1 ERRMSG)
                                list (GET RETVAL 0 RETVAL)
                            endif ()
                        endif ()
                        if (NOT RETVAL EQUAL 0)
                            message (FATAL_ERROR "Failed to download CMake BASIS v${BASIS_VERSION} from\n"
                                "\t${BASIS_DOWNLOAD_URL}\n"
                                "Error: ${ERRMSG}\n"
                                "Try again after installation either curl or wget or follow the instructions at\n"
                                "\thttps://cmake-basis.github.io\n"
                                "to download and install it manually before configuring this project.\n")
                        endif ()
                        message (STATUS "Downloading CMake BASIS v${BASIS_VERSION}... - done")
                    endif () #The archive doesn't exist
                endif() # end of download using wget or curl
            endif () #end of download using Git Wget or Curl
        endif () # end of BasisProject not found

        # extract source package
        message (STATUS "Extracting CMake BASIS...")
        execute_process (COMMAND ${CMAKE_COMMAND} -E tar -xvzf "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}" RESULT_VARIABLE RETVAL)
        if (NOT RETVAL EQUAL 0)
            file (REMOVE_RECURSE "${BASIS_SOURCE_DIR}")
            message (FATAL_ERROR "Failed to extract the downloaded archive file ${DOWNLOAD_PATH}/${BASIS_ARCHIVE}!")
        endif ()
        message (STATUS "Extracting CMake BASIS... - done")


        # configure
        file (MAKE_DIRECTORY "${BASIS_BINARY_DIR}")
        set (CMAKE_ARGUMENTS "-DBASIS_REGISTER:BOOL=OFF") # do not register this BASIS build/installation
        # as it should only be used by this project
        if (BASIS_INSTALL_PREFIX)
            list (APPEND CMAKE_ARGUMENTS "-DCMAKE_INSTALL_PREFIX=${BASIS_INSTALL_PREFIX}")
        endif ()
        list (LENGTH BASIS_UNPARSED_ARGUMENTS N)
        while (N GREATER 0)
            list (GET BASIS_UNPARSED_ARGUMENTS 0 VARIABLE_NAME)
            list (GET BASIS_UNPARSED_ARGUMENTS 1 VARIABLE_VALUE)
            list (APPEND CMAKE_ARGUMENTS "-D${VARIABLE_NAME}=${VARIABLE_VALUE}")
            list (REMOVE_AT BASIS_UNPARSED_ARGUMENTS 0 1)
            math (EXPR N "${N} - 2")
        endwhile ()

        execute_process (
            COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" ${CMAKE_ARGUMENTS} "${BASIS_SOURCE_DIR}"
            WORKING_DIRECTORY "${BASIS_BINARY_DIR}" RESULT_VARIABLE RETVAL
            )
        if (NOT RETVAL EQUAL 0)
            message (FATAL_ERROR "Failed to configure the BASIS package at ${BASIS_SOURCE_DIR}")
        endif()
        # build
        if (NOT BASIS_CONFIGURE_ONLY)
            execute_process (COMMAND "${CMAKE_COMMAND}" --build "${BASIS_BINARY_DIR}" --config Release WORKING_DIRECTORY "${BASIS_BINARY_DIR}" RESULT_VARIABLE RETVAL)
            if (NOT RETVAL EQUAL 0)
                message (FATAL_ERROR "Failed to build the BASIS package at ${BASIS_SOURCE_DIR}")
            endif ()
        endif()
        # install
        if (BASIS_INSTALL_PREFIX)
            execute_process (COMMAND "${CMAKE_COMMAND}" --build "${BASIS_BINARY_DIR}" --config Release --target install WORKING_DIRECTORY "${BASIS_BINARY_DIR}")
            set (BASIS_DIR "${BASIS_INSTALL_PREFIX}")
        else ()
            set (BASIS_DIR "${BASIS_BINARY_DIR}")
        endif ()

        # remember in which directory BASIS was installed to avoid re-running
        # the bootstrapping every time the project needs to be re-configured
        set (BASIS_INSTALL_PREFIX_CONFIGURED "${BASIS_INSTALL_PREFIX}" CACHE INTERNAL "" FORCE)

    elseif (BASIS_INSTALL_PREFIX_CONFIGURED)
        set (BASIS_DIR "${BASIS_INSTALL_PREFIX_CONFIGURED}")
    else ()
        set (BASIS_DIR "${BASIS_BINARY_DIR}")
    endif ()

    # return location of local CMake BASIS installation
    set (BASIS_DIR "${BASIS_DIR}" PARENT_SCOPE)
    unset(BASIS_ARCHIVE_DIR)
    unset(BASIS_CONFIGURE_ONLY)
endfunction (basis_bootstrap)


function (basis_bootstrap_module)
    # parse arguments -- unparsed arguments are passed on to CMake using -D
    include (CMakeParseArguments)
    cmake_parse_arguments (BASIS "INFORM_USER" "VERSION;DOWNLOAD_URL;ARCHIVE_DIR" "" ${ARGN})
    if (NOT BASIS_VERSION)
        message (FATAL_ERROR "No CMake BASIS version specified! Use 'VERSION 3.3.0', for example.")
    endif ()

    #ARCHIVE DIR and DOWNLOD _URL are mutually exclusive
    #perform the necessary checks
    if (BASIS_ARCHIVE_DIR AND BASIS_DOWNLOAD_URL)
        message (FATAL_ERROR "Options ARCHIVE_DIR and DOWNLOAD_URL are mutually exclusive!")
    endif()

    #Set all the necessary variables here for the download process
    set (DOWNLOAD_PATH "${CMAKE_MODULE_PATH}")
    if (BASIS_VERSION MATCHES "^[0-9]+\\.[0-9]+\\.[0-9]+(-[a-z]*)?$")
        if (WIN32)
            set (BASIS_ARCHIVE "modules-master.zip")
        else ()
            set (BASIS_ARCHIVE "modules-master.tar.gz")
        endif ()
        if (NOT BASIS_DOWNLOAD_URL)
            if (WIN32)
                set (BASIS_DOWNLOAD_URL "https://github.com/cmake-basis/modules/archive/${BASIS_ARCHIVE}.zip")
            else ()
                set (BASIS_DOWNLOAD_URL "https://github.com/cmake-basis/modules/archive/${BASIS_ARCHIVE}.tar.gz")
            endif ()
        endif ()

        if (NOT BASIS_DOWNLOAD_URL MATCHES "\\.(zip|tar\\.gz)$")
            set (BASIS_DOWNLOAD_URL "${BASIS_DOWNLOAD_URL}/${BASIS_ARCHIVE}")
			message (STATUS "The download URL is ${BASIS_DOWNLOAD_URL}")
        endif ()
        if (NOT ARCHIVE_SRC_URL MATCHES "\\.(zip|tar\\.gz)$")
            set (ARCHIVE_SRC_URL "${BASIS_ARCHIVE_DIR}/${BASIS_ARCHIVE}")
        endif()
    else ()
        set (BASIS_DOWNLOAD_URL "git@github.com:cmake-basis/modules.git")
    endif ()

	
    set (BASIS_SOURCE_DIR "${DOWNLOAD_PATH}")

    # first check it the modules are present in the CMAKE_CURRENT_BINARY_DIR/config/modules-master
    # if BasisSettings.cmake file exists then it is already extracted from previous run
    if (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/config/modules-master/BasisSettings.cmake")
        message (STATUS "BASIS modules are not found...  Extracting from archives ...")
        # Extract the BASIS CMake modules into the config folder

        # if the archive doesnt exist in the ARCHIVE_DIR then download it
        if (NOT EXISTS "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}")
            message (STATUS "Trying to download from ${BASIS_DOWNLOAD_URL}")
            if (BASIS_DOWNLOAD_URL MATCHES ".git$")
                find_package (Git QUIET)
                if (NOT GIT_FOUND)
                    set (ERRMSG "Git client not found: GIT_EXECUTABLE")
                else ()
                    mark_as_advanced (GIT_EXECUTABLE)
                    message (STATUS "Cloning CMake BASIS Modules repository...")
                    execute_process (
                        COMMAND "${GIT_EXECUTABLE}" clone --depth=1 "${BASIS_DOWNLOAD_URL}" "${BASIS_SOURCE_DIR}"
                        RESULT_VARIABLE RETVAL
                        ERROR_VARIABLE  ERRMSG )
                    if (RETVAL EQUAL 0)
                        execute_process (
                            COMMAND "${GIT_EXECUTABLE}" checkout --detach "${BASIS_VERSION}"
                            WORKING_DIRECTORY "${BASIS_SOURCE_DIR}"
                            RESULT_VARIABLE   RETVAL
                            ERROR_VARIABLE    ERRMSG )
                        if (RETVAL EQUAL 0)
                            set (ERRMSG)
                            message (STATUS "Cloning and Detaching the BASIS CMake Modules repository... - done")
                        endif ()
                    endif ()
                endif () # Git not found
                if (ERRMSG)
                    message (FATAL_ERROR "Failed to clone CMake BASIS modules ${BASIS_VERSION} from\n"
                        "\t${BASIS_DOWNLOAD_URL}\n"
                        "Error: ${ERRMSG}\n"
                        "Ensure GIT_EXECUTABLE is set and try again or follow the instructions at\n"
                        "\thttps://cmake-basis.github.io\n"
                        "to download and install it manually before configuring this project.\n")
                endif ()
            else () # download using wget or curl
                # download source code distribution package
                message (STATUS "Downloading CMake BASIS module repository using curl executable ...")
                find_program (CURL_EXECUTABLE NAMES curl)
                mark_as_advanced (CURL_EXECUTABLE)
                if (CURL_EXECUTABLE)
                    execute_process (
                        COMMAND "${CURL_EXECUTABLE}" -L -o "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}" "${BASIS_DOWNLOAD_URL}"
                        ERROR_VARIABLE  ERRMSG
                        RESULT_VARIABLE RETVAL )
                else ()
                    message(STATUS "Downloading CMAKE BASIS module repository using wget executable ...")
                    find_package (Wget QUIET)
                    if (WGET_EXECUTABLE)
                        execute_process (
                            COMMAND "${WGET_EXECUTABLE}" -O "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}" "${BASIS_DOWNLOAD_URL}"
                            ERROR_VARIABLE  ERRMSG
                            RESULT_VARIABLE RETVAL )
                    else ()
                        message (STATUS "Downloading CMAKE BASIS Module repository using OpenSSL executable ...")
                        set (CMAKE_USE_OPENSSL ON)
                        file (DOWNLOAD "${BASIS_DOWNLOAD_URL}" "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}" STATUS RETVAL)
                        list (GET RETVAL 1 ERRMSG)
                        list (GET RETVAL 0 RETVAL)
                    endif ()
                endif ()
                if (NOT RETVAL EQUAL 0)
                    message (FATAL_ERROR "Failed to download CMake BASIS modules repository v${BASIS_VERSION} from\n"
                        "\t${BASIS_DOWNLOAD_URL}\n"
                        "Error: ${ERRMSG}\n"
                        "Try again after installation either curl or wget or follow the instructions at\n"
                        "\thttps://cmake-basis.github.io\n"
                        "to download and install it manually before configuring this project.\n")
                endif ()
                message (STATUS "Downloading CMake BASIS modules repository v${BASIS_VERSION}... - done")
            endif() # end of download using wget or curl
        endif ()  #SOURCE ARCHIVE Exists

        if (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/config/modules-master/BasisSettings.cmake")
                    # extract source package
                    message (STATUS "Extracting CMake BASIS module ...")
                    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/config")
                    execute_process (COMMAND ${CMAKE_COMMAND} -E tar -xvzf "${DOWNLOAD_PATH}/${BASIS_ARCHIVE}"
                        WORKING_DIRECTORY "config" RESULT_VARIABLE RETVAL)
                    if (NOT RETVAL EQUAL 0)
                        message (FATAL_ERROR "Failed to extract the downloaded archive file ${DOWNLOAD_PATH}/${BASIS_ARCHIVE}!")
                    endif ()
                    message (STATUS "Extracting CMake BASIS module ... - done")
        endif()
    endif()# BasisSettings.cmake file exists

    if(IS_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/config/modules-master")
        set (BASIS_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/config/modules-master")
    endif()
    set(BASIS_CMAKE_MODULES_DIR ${BASIS_BINARY_DIR} PARENT_SCOPE)
endfunction (basis_bootstrap_module)
