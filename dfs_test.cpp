//
// Created by liufurui on 2023/3/12.
//
#include <iostream>
#include "dfs.h"
void test_dfs() {
    // build test graph
    using namespace dfs;
    using NodeList = std::list<NodePtr>;
    using Graph = dfs::Graph;
    using EdgePtr = std::shared_ptr<dfs::Edge>;
    NodesMap nodeid_to_node = {
            {"A", std::make_shared<dfs::Node>("A")},
            {"B", std::make_shared<dfs::Node>("B")},
            {"C", std::make_shared<dfs::Node>("C")},
            {"D", std::make_shared<dfs::Node>("D")},
    };

    //   A
    // /1 \3
    // B    C
    //  \7  /4
    //    D

    // A->B->C
    // B->A->D
    // C->A->D
    // D->B->C
//    std::unordered_map<std::string, std::list<NodePtr>> nodeid_to_neighbors = {
//            {"A", {nodeid_to_node["B"], nodeid_to_node["C"]}},
//            {"B", {nodeid_to_node["A"], nodeid_to_node["D"]}},
//            {"C", {nodeid_to_node["A"], nodeid_to_node["D"]}},
//            {"D", {nodeid_to_node["B"], nodeid_to_node["C"]}},
//    };
    using namespace dfs;
    std::unordered_map<dfs::EdgeId , EdgePtr, dfs::pair_hash> edgeid_to_edge = {
            {make_edge_id("A", "B"), std::make_shared<Edge>(make_edge_id("A", "B"), double(1.0))},
            {make_edge_id("A", "C"), std::make_shared<Edge>(make_edge_id("A", "C"), double(1.0))},
            {make_edge_id("B", "A"), std::make_shared<Edge>(make_edge_id("B", "A"), double(1.0))},
            {make_edge_id("B", "D"), std::make_shared<Edge>(make_edge_id("B", "D"), double(1.0))},
            {make_edge_id("C", "A"), std::make_shared<Edge>(make_edge_id("C", "A"), double(1.0))},
            {make_edge_id("C", "D"), std::make_shared<Edge>(make_edge_id("C", "D"), double(1.0))},
            {make_edge_id("D", "B"), std::make_shared<Edge>(make_edge_id("D", "B"), double(1.0))},
            {make_edge_id("D", "C"), std::make_shared<Edge>(make_edge_id("D", "C"), double(1.0))},
    };
    std::unordered_map<std::string, std::unordered_set<std::shared_ptr<Node>, node_ptr_hash>> nodeid_to_neighbors;
    for(auto& [edge_id, _]: edgeid_to_edge) {
        nodeid_to_neighbors[edge_id.first].insert(nodeid_to_node[edge_id.second]);
    }
    dfs::Graph g = {std::move(nodeid_to_node), std::move(nodeid_to_neighbors), std::move(edgeid_to_edge)};

    dfs::dfs(g);
    std::cin.get();

}
