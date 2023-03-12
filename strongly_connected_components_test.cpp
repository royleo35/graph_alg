//
// Created by liufurui on 2023/3/12.
//
#include "strongly_connected_components.h"
#include <iostream>

static void push_node(dfs::Graph& g, const std::string& node_id) {
    g.nodeid_to_node[node_id] = std::make_shared<dfs::Node>(node_id);
}
static void push_edge(dfs::Graph& g, const std::string& from, const std::string& to) {
    auto edge_id = dfs::make_edge_id(from, to);
    g.edgeid_to_edge[edge_id] = std::make_shared<dfs::Edge>(edge_id, double(1.0));
}

static void build_neighbors(dfs::Graph& g) {
    for(auto& [edge_id, _]: g.edgeid_to_edge) {
        g.nodeid_to_neighbors[edge_id.first].insert(g.nodeid_to_node[edge_id.second]);
    }
}


void test_strongly_connected_components() {
    dfs::Graph g;
    push_node(g, "a");
    push_node(g, "b");
    push_node(g, "c");
    push_node(g, "d");
    push_node(g, "e");
    push_node(g, "f");
    push_node(g, "g");
    push_node(g, "h");

    push_edge(g, "a", "e");

    push_edge(g, "b", "a");


    push_edge(g, "c", "b");
    push_edge(g, "c", "d");

    push_edge(g, "d", "c");

    push_edge(g, "e", "b");


    push_edge(g, "f", "b");
    push_edge(g, "f", "e");
    push_edge(g, "f", "g");

    push_edge(g, "g", "f");
    push_edge(g, "g", "c");

    push_edge(g, "h", "h");
    push_edge(g, "h", "g");
    push_edge(g, "h", "d");

    build_neighbors(g);

    auto res = scc::strongly_connected_components(g);
    std::cout<<"na";
}