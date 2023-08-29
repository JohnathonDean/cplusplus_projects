cmake_minimum_required( VERSION 2.8 )
project ( opencv_test )

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3" )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

############### dependencies ######################
# OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


# find_package(PythonLibs 2.7)
# include_directories(${PYTHON_INCLUDE_DIRS})

# message("----------------------++++++++++--------------------------")
# message(${EIGEN3_INCLUDE_DIRS})
# message("----------------------++++++++++--------------------------")

set( THIRD_PARTY_LIBS
    ${OpenCV_LIBS}
)
############### dependencies ######################

include_directories( ${PROJECT_SOURCE_DIR}/include )
add_subdirectory( src )
add_subdirectory( test )
