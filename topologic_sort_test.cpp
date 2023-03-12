//
// Created by liufurui on 2023/3/12.
//
#include <iostream>
#include "topological_sort.h"

void test_topological_sort() {
    // build test graph
    using namespace dfs;
    using NodeList = std::list<NodePtr>;
    using Graph = dfs::Graph;
    using EdgePtr = std::shared_ptr<dfs::Edge>;
    NodesMap  nodeid_to_node = {
            {"内裤", std::make_shared<dfs::Node>("内裤")},
            {"裤子", std::make_shared<dfs::Node>("裤子")},
            {"腰带", std::make_shared<dfs::Node>("腰带")},
            {"衬衣", std::make_shared<dfs::Node>("衬衣")},
            {"领带", std::make_shared<dfs::Node>("领带")},
            {"夹克", std::make_shared<dfs::Node>("夹克")},
            {"袜子", std::make_shared<dfs::Node>("袜子")},
            {"鞋", std::make_shared<dfs::Node>("鞋")},
            {"手表", std::make_shared<dfs::Node>("手表")},

    };

    using namespace dfs;
    std::unordered_map<dfs::EdgeId , EdgePtr, dfs::pair_hash> edgeid_to_edge = {
            {make_edge_id("内裤", "裤子"), std::make_shared<Edge>(make_edge_id("内裤", "裤子"), double(1.0))},
            {make_edge_id("内裤", "鞋"), std::make_shared<Edge>(make_edge_id("内裤", "鞋"), double(1.0))},
            {make_edge_id("袜子", "鞋"), std::make_shared<Edge>(make_edge_id("袜子", "鞋"), double(1.0))},
            {make_edge_id("裤子", "腰带"), std::make_shared<Edge>(make_edge_id("裤子", "腰带"), double(1.0))},
            {make_edge_id("衬衣", "腰带"), std::make_shared<Edge>(make_edge_id("衬衣", "腰带"), double(1.0))},
            {make_edge_id("衬衣", "领带"), std::make_shared<Edge>(make_edge_id("衬衣", "领带"), double(1.0))},
            {make_edge_id("腰带", "夹克"), std::make_shared<Edge>(make_edge_id("腰带", "夹克"), double(1.0))},
            {make_edge_id("领带", "夹克"), std::make_shared<Edge>(make_edge_id("领带", "夹克"), double(1.0))},
            {make_edge_id("裤子", "鞋"), std::make_shared<Edge>(make_edge_id("裤子", "鞋"), double(1.0))},

    };
    std::unordered_map<std::string, std::unordered_set<std::shared_ptr<Node>, node_ptr_hash>> nodeid_to_neighbors;
    for(auto& [edge_id, _]: edgeid_to_edge) {
        std::cout<<"edge:"<<edge_id.first<<"->"<<edge_id.second<<std::endl;
        nodeid_to_neighbors[edge_id.first].insert(nodeid_to_node[edge_id.second]);
    }
    for(auto& [node_id, ns]: nodeid_to_neighbors) {
        auto& ns1 = ns;
        std::vector<std::string> ids;
        for(auto&n: ns) {
            ids.push_back(n->node_id);
        }
        std::cout<<"node:"<<node_id<< "的neighbor_ids:\n";
        for(auto&id: ids) {
            std::cout<<id<<"\t";
        }
        std::cout<<"\n end neighbor_ids:\n";
        ids.clear();
    }

    dfs::Graph g = {std::move(nodeid_to_node), std::move(nodeid_to_neighbors), std::move(edgeid_to_edge)};

    // dfs::dfs(g);
    auto res = topolotic_sort::topolotic_sort(g);
    for(auto& n: res) {
        std::cout<<n->node_id<<"-->";
    }
}