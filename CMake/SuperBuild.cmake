# This function is used to force a build on a dependant project at cmake configuration phase.
# 
function (build_sub_project) #FOLLOWING ARGUMENTS are the CMAKE_ARGS of ExternalProject_Add

	set(options)
	set(OneValArg "TARGET;PREFIX;SOURCE_DIR")
	set(MultiValArgs)
	
    include (CMakeParseArguments)
    cmake_parse_arguments (SUBPRJ "${options}" "${OneValArg}" "${MultiValArgs}" ${ARGN})
    if (NOT EXISTS "${SUBPRJ_SOURCE_DIR}")
        message (FATAL_ERROR "The SUBPROJECT Source Directory ${SUBPRJ_SOURCE_DIR} does not exist")
    endif ()
    #ARCHIVE DIR and 	
	#list(APPEND ARGN "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
    set(TRIGGER_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/force_${SUBPRJ_TARGET})

    #mktemp dir in build tree
    file(MAKE_DIRECTORY ${TRIGGER_BUILD_DIR} ${TRIGGER_BUILD_DIR}/build)
	message(STATUS "The trigger build direcctory is ${TRIGGER_BUILD_DIR}")
	message(STATUS "The CMAKE GENERATOR used is ${CMAKE_GENERATOR}")
	message(STATUS "The CMAKE GENERATOR PLATFORM used is ${CMAKE_GENERATOR_PLATFORM}")	
	
    #generate false dependency project
    set(CMAKE_LIST_CONTENT "
        cmake_minimum_required(VERSION 2.8)

        include(ExternalProject)
        ExternalProject_add(
		${SUBPRJ_TARGET} 
		DOWNLOAD_COMMAND \"\" 
		UPDATE_COMMAND \"\" 
		PREFIX ${SUBPRJ_PREFIX} 
		SOURCE_DIR ${SUBPRJ_SOURCE_DIR} 
		CMAKE_GENERATOR ${CMAKE_GENERATOR} 
		CMAKE_GENERATOR_PLATFORM ${CMAKE_GENERATOR_PLATFORM}
        INSTALL_COMMAND \"\"
        )

        add_custom_target(TRIGGER_${SUBPRJ_TARGET})
        add_dependencies(TRIGGER_${SUBPRJ_TARGET} ${SUBPRJ_TARGET})
    ")

    file(WRITE ${TRIGGER_BUILD_DIR}/CMakeLists.txt "${CMAKE_LIST_CONTENT}")

	message (STATUS "Executing the configure step for the dummy target")
    execute_process(COMMAND ${CMAKE_COMMAND} -G${CMAKE_GENERATOR} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ..
        WORKING_DIRECTORY ${TRIGGER_BUILD_DIR}/build
        )
	
	message (STATUS "Executing the build step for the dummy target")	
    execute_process(COMMAND ${CMAKE_COMMAND} -G${CMAKE_GENERATOR} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} --build .
        WORKING_DIRECTORY ${TRIGGER_BUILD_DIR}/build
        )

endfunction()