
add_executable( string_sort_test string_sort_test.cpp )

add_executable( binary_search binary_search.cpp )
target_link_libraries( binary_search
    MyUtil
)

add_executable( sort_int_array sort_int_array.cpp)
target_link_libraries( sort_int_array
    MyUtil
)


add_executable( thread_test thread_test.cpp )
target_link_libraries( thread_test
    boost_system
    boost_thread
)