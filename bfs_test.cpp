//
// Created by liufurui on 2023/3/12.
//
#include <iostream>
#include "bfs.h"
#include "unordered_map"
void test_bfs() {

    //   A
    // /1 \3
    // B    C
    //  \7  /4
    //    D

    // build graph
    // A->B->C
    // B->A->D
    // C->A->D
    // D->B->C
    using NodePtr = std::shared_ptr<BFS::Node>;
    using NodeList = std::list<NodePtr>;
    std::unordered_map<std::string, NodePtr> m = {
            {"A", std::make_shared<BFS::Node>("A")},
            {"B", std::make_shared<BFS::Node>("B")},
            {"C", std::make_shared<BFS::Node>("C")},
            {"D", std::make_shared<BFS::Node>("D")},
    };
    std::list<std::shared_ptr<BFS::Node>> l1 = {m["A"], m["B"], m["C"]};
    std::list<std::shared_ptr<BFS::Node>> l2 = {m["B"], m["A"], m["D"]};
    std::list<std::shared_ptr<BFS::Node>> l3 = {m["C"], m["A"], m["D"]};
    std::list<std::shared_ptr<BFS::Node>> l4 = {m["D"], m["B"], m["C"]};
    BFS::Gragh g={l1,l2,l3,l4};
    BFS::BFS(g, *l1.begin());
    // A -> D
    BFS::print_path(g, m["A"], m["D"]);
    std::cin.get();
}

