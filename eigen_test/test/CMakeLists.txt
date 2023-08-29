
add_executable( isometry3d_test isometry3d_test.cpp )

add_executable( quaterion_test quaterion_test.cpp )

add_executable( matrix_test matrix_test.cpp )

add_executable( output_test output_test.cpp )



# target_link_libraries( isometry3d_test
#     ${Eigen3_LIBRARIES}
# )

# add_executable( run_vo run_vo.cpp )
# target_link_libraries( run_vo myslam )