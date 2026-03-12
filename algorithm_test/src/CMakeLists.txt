add_library(sort_algorithms sort/sort.cpp)

target_include_directories(sort_algorithms
    PUBLIC ${PROJECT_SOURCE_DIR}/src/sort
)

target_compile_options(sort_algorithms
    PRIVATE -O3 -march=native
)

add_executable(sort_test sort/sort_test.cpp)

target_link_libraries(sort_test PRIVATE sort_algorithms)

add_library(search_algorithms search/search.cpp)

target_include_directories(search_algorithms
    PUBLIC ${PROJECT_SOURCE_DIR}/src/search
)

target_compile_options(search_algorithms
    PRIVATE -O3 -march=native
)

add_executable(search_test search/search_test.cpp)

target_link_libraries(search_test PRIVATE search_algorithms)

add_library(graph_algorithms graph/graph.cpp)

target_include_directories(graph_algorithms
    PUBLIC ${PROJECT_SOURCE_DIR}/src/graph
)

target_compile_options(graph_algorithms
    PRIVATE -O3 -march=native
)

add_executable(graph_test graph/graph_test.cpp)

target_link_libraries(graph_test PRIVATE graph_algorithms)

add_library(tree_algorithms tree/tree.cpp)

target_include_directories(tree_algorithms
    PUBLIC ${PROJECT_SOURCE_DIR}/src/tree
)

target_compile_options(tree_algorithms
    PRIVATE -O3 -march=native
)

add_executable(tree_test tree/tree_test.cpp)

target_link_libraries(tree_test PRIVATE tree_algorithms)
