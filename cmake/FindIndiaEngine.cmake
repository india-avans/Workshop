# Locate IndiaEngine library
# This module defines
# IndiaEngine_LIBRARY, the name of the library to link against
# IndiaEngine_FOUND, if false, do not try to link to IndiaEngine
# IndiaEngine_INCLUDE_DIR, where to find India.h

SET(IndiaEngine_SEARCH_PATHS
     ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/IndiaEngine
)

IF(WIN32)
    IF(CMAKE_BUILD_TYPE MATCHES "Debug")
       SET(IndiaEngine_SEARCH_PATHS ${IndiaEngine_SEARCH_PATHS}
       ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/IndiaEngine/debug
    )
    ENDIF(CMAKE_BUILD_TYPE MATCHES "Debug")

    IF(CMAKE_BUILD_TYPE MATCHES "Release")
        SET(IndiaEngine_SEARCH_PATHS  ${IndiaEngine_SEARCH_PATHS}
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/IndiaEngine/release
    )
    ENDIF(CMAKE_BUILD_TYPE MATCHES "Release")
ENDIF(WIN32)

FIND_PATH(IndiaEngine_INCLUDE_DIR IndiaEngine.h
    HINTS
    $ENV{IndiaEngineDIR}
    PATH_SUFFIXES include/IndiaEngine include
    PATHS ${IndiaEngine_SEARCH_PATHS}
)

FIND_LIBRARY(IndiaEngine_LIBRARY_TEMP
    NAMES IndiaEngine
    HINTS
    $ENV{IndiaEngineDIR}
    PATH_SUFFIXES lib64 lib
    PATHS ${IndiaEngine_SEARCH_PATHS}
)

IF(IndiaEngine_LIBRARY_TEMP)
    # For IndiaEnginemain
    IF(NOT IndiaEngine_BUILDING_LIBRARY)
        IF(IndiaEngineMAIN_LIBRARY)
            SET(IndiaEngine_LIBRARY_TEMP ${IndiaEngineMAIN_LIBRARY} ${IndiaEngine_LIBRARY_TEMP})
        ENDIF(IndiaEngineMAIN_LIBRARY)
    ENDIF(NOT IndiaEngine_BUILDING_LIBRARY)

    # For MinGW library
    IF(MINGW)
        SET(IndiaEngine_LIBRARY_TEMP ${MINGW32_LIBRARY} ${IndiaEngine_LIBRARY_TEMP})
    ENDIF(MINGW)

    # Set the final string here so the GUI reflects the final state.
    SET(IndiaEngine_LIBRARY ${IndiaEngine_LIBRARY_TEMP} CACHE STRING "Where the IndiaEngine Library can be found")

    # Find IndiaEngine runtime directory
    FIND_PATH(IndiaEngine_RUNTIME_DIR IndiaEngine.dll
    HINTS
    $ENV{IndiaEngineDIR}
    PATH_SUFFIXES include/IndiaEngine bin
    PATHS ${IndiaEngine_SEARCH_PATHS})

   

    # Set the temp variable to INTERNAL so it is not seen in the CMake GUI
    SET(IndiaEngine_LIBRARY_TEMP "${IndiaEngine_LIBRARY_TEMP}" CACHE INTERNAL "")

    IF(WIN32)
        # Find IndiaEngine runtime library
        IF(IndiaEngine_RUNTIME_DIR)
        # Copy IndiaEngine runtime and runtime dependencies to the binary folder
            SET(IndiaEngine_RUNTIME "${IndiaEngine_RUNTIME_DIR}/IndiaEngine.dll" CACHE STRING "Where the IndiaEngine DLL can be found")
            #Define all runtime dependencies
              file(GLOB_RECURSE RUNTIME_DEPENDENCIES 
               "${IndiaEngine_RUNTIME_DIR}/*.dll"
            )
            file(COPY ${RUNTIME_DEPENDENCIES} DESTINATION ${CMAKE_BINARY_DIR})
        ENDIF(IndiaEngine_RUNTIME_DIR)
    ENDIF(WIN32)

ENDIF(IndiaEngine_LIBRARY_TEMP)

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(IndiaEngine REQUIRED_VARS IndiaEngine_LIBRARY IndiaEngine_INCLUDE_DIR)