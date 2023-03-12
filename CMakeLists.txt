cmake_minimum_required(VERSION 3.24)
project(graph_alg)

set(CMAKE_CXX_STANDARD 17)

add_executable(graph_alg main.cpp bfs.cpp dfs.h dfs.cpp bfs_test.cpp dfs_test.cpp topological_sort.h topological_sort.cpp topologic_sort_test.cpp strongly_connected_components.h strongly_connected_components.cpp strongly_connected_components_test.cpp)
