#include <iostream>
#include "bfs.h"
#include "dfs.h"
#include <unordered_map>

extern void test_bfs();
extern void test_dfs();
extern void test_topological_sort();
extern void test_strongly_connected_components();

void test() {
    // test_bfs();
    // test_dfs();
    // test_topological_sort();
    test_strongly_connected_components();
}


int main() {
    test();
    return 0;
}
