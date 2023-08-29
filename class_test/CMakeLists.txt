cmake_minimum_required( VERSION 2.8 )
project ( class_test )

add_compile_options(-std=c++14)

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++14 -march=native -O3" )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

############### dependencies ######################

find_package(Boost REQUIRED COMPONENTS system)

find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})

############### dependencies ######################

include_directories( ${PROJECT_SOURCE_DIR}/include )
add_subdirectory( src )
add_subdirectory( test )