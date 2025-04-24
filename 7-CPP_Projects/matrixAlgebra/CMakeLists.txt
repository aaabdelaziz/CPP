cmake_minimum_required( VERSION 3.10 )

# Project name and programming language
project( matrixAlgebra CXX )

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Gather source files and store paths in CMake variables
set(SOURCES drivers/main.cpp )
file( GLOB LIBRARY_SOURCE_FILES library/src/*.cpp )
file( GLOB TEST_SOURCE_FILES library/test/*.cpp external/catch/*.cpp  )
file( GLOB HEADER_FILES library/inc/*.h*  external/catch/*.h* )

# Specify the header directories, otherwise our includes are not found 
include_directories( external/catch )
include_directories( library/inc )

# Enables exporting all symbols to the dll on windows
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

# When compiling with gcc we need to compile libraries with fPIC (stands for position independent code).
if( CMAKE_COMPILER_IS_GNUCXX )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -pedantic -Wall -Werror" )
endif( CMAKE_COMPILER_IS_GNUCXX )

# Add compilation target for our library
add_library( matrix_algebra SHARED ${LIBRARY_SOURCE_FILES} ${HEADER_FILES} )

# Add compilation target for our executables
add_executable( matrix_algebra_testrunner ${TEST_SOURCE_FILES} ${HEADER_FILES} )
add_executable( main ${SOURCES})

# Add link depenencies
target_link_libraries( matrix_algebra_testrunner matrix_algebra )
target_link_libraries( main matrix_algebra )
