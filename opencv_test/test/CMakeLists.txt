
add_executable( aruco_gen aruco_gen.cpp )
target_link_libraries( aruco_gen ${OpenCV_LIBS} )

add_executable( aruco_calibrate_board aruco_calibrate_board.cpp )
target_link_libraries( aruco_calibrate_board ${OpenCV_LIBS} )


add_executable( generate_calibrate generate_calibrate.cpp )
target_link_libraries( generate_calibrate ${OpenCV_LIBS} )


# target_link_libraries( isometry3d_test
#     ${Eigen3_LIBRARIES}
# )

# add_executable( run_vo run_vo.cpp )
# target_link_libraries( run_vo myslam )