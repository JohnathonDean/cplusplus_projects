add_executable( parameter_passing_test parameter_passing_test.cpp )

add_executable( class_copy class_copy.cpp )

add_executable( class_destroy class_destroy.cpp )

add_executable( singleton_test Singleton_test.cpp )

add_executable( smart_ptr smart_ptr.cpp )


# target_link_libraries( myslam
#     ${THIRD_PARTY_LIBS}
# )

# add_executable( run_vo run_vo.cpp )
# target_link_libraries( run_vo myslam )