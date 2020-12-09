# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)
project (IndiaDemo)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

IF(WIN32)
    # Windows directory to install library to
    set(INSTALL_DIR "C:/dev/IndiaDemo/")
    # rc file to include for application icon
    set(ICON "${CMAKE_CURRENT_SOURCE_DIR}/rc/Icon.rc")  
ENDIF(WIN32)

# Find used packages

find_package(IndiaEngine REQUIRED)
include_directories(IndiaDemo PRIVATE ${IndiaEngine_INCLUDE_DIR})

# Define source files
file(GLOB_RECURSE SRC_FILES 
    "src/*.cpp"
)   

# Include header files
include_directories(include)

# Make executable file and link src
add_executable(IndiaDemo 
${SRC_FILES}
${ICON}
)

IF(WIN32)
    # Set installation directory to build type
     IF(CMAKE_BUILD_TYPE MATCHES "Debug")
        set(INSTALL_DIR "${INSTALL_DIR}/debug/")    
     ENDIF(CMAKE_BUILD_TYPE MATCHES "Debug")
     IF(CMAKE_BUILD_TYPE MATCHES "Release")
        set(INSTALL_DIR "${INSTALL_DIR}/release/")
     ENDIF(CMAKE_BUILD_TYPE MATCHES "Release")

    # Install target to specified install directory
    install(TARGETS IndiaDemo DESTINATION ${INSTALL_DIR})

    # Install dependencies to specified install directory
    install(FILES 
    ${IndiaEngine_RUNTIME} 
    DESTINATION ${INSTALL_DIR})

    # Install resources directory to specified install directory
     install(DIRECTORY resources DESTINATION ${INSTALL_DIR})

    # Install dependencies to the bin folder within the specified install directory
    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/" DESTINATION ${INSTALL_DIR}
        FILES_MATCHING
        PATTERN "*.dll"
        # Exclude any folders present in the binary directory
        PATTERN "docs" EXCLUDE
        PATTERN "resources" EXCLUDE
        PATTERN "Testing" EXCLUDE
        PATTERN "CMakeFiles" EXCLUDE
        PATTERN ".cmake" EXCLUDE
    )

ENDIF(WIN32)

# Link used libraries
target_link_libraries(IndiaDemo 
PRIVATE ${IndiaEngine_LIBRARY}
) 

# Copy resources to build
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

IF(CMAKE_BUILD_TYPE MATCHES "Release")
    # Doxygen
    # Check if Doxygen is installed
    find_package(Doxygen)
    IF (DOXYGEN_FOUND)
        # Set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.cfg)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        # Request to configure the file
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        message("Doxygen build started")

       # Build the documentation with the library
       add_custom_target(doc_doxygen ALL
           COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
           WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
           COMMENT "Generating API documentation with Doxygen"
           VERBATIM)
            # Copy Doxygen entry html to build
            file(GLOB BUILD_DOXYGEN
                "docs/doxygen.html"
            )
            file(COPY ${BUILD_DOXYGEN} DESTINATION  "${CMAKE_CURRENT_BINARY_DIR}/docs")
            # Install Doxygen documentation to install directory
            IF(WIN32)
                install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs" DESTINATION ${INSTALL_DIR})
            ENDIF(WIN32)

    ELSE (DOXYGEN_FOUND)
           message("Doxygen needs to be installed to generate the doxygen documentation")
    ENDIF (DOXYGEN_FOUND)

ENDIF(CMAKE_BUILD_TYPE MATCHES "Release")