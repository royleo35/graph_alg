//
// Created by liufurui on 2023/3/12.
//
#include "strongly_connected_components.h"
#include <iostream>
using namespace scc;
std::vector<GraphPtr> scc::strongly_connected_components(Graph &g) {
    auto stack = dfs::dfs(g); // dfs遍历图
    auto gt = build_gt(g);  // 转置遍历后的图
    // init node attr
    for(auto& [_, node]: gt.nodeid_to_node) {
        node->color = Color::White;
        node->prev = nullptr;
    }
    std::vector<GraphPtr> components;
    // init global time
    int time = 0;
    while(!stack.empty()) {
        auto& node = stack.top();
        stack.pop();
        std::stack<NodePtr> local_stack;
        if(node->color == Color::White) {
            dfs::dfs_visit(gt, node, time, local_stack);
            // std::cout<<node->node_id<<"|";
        }
        // 如果栈非空，里面保存的是一个强连通分量的节点列表
        // 下面利用这个节点列表和原始graph构造出强连通分量图
        if(!local_stack.empty()) {
            auto com = std::make_shared<Graph>();
            while (!local_stack.empty()) {
                auto n = local_stack.top();
                local_stack.pop();
                com->nodeid_to_node[n->node_id] = n;
                com->nodeid_to_neighbors[n->node_id] = g.nodeid_to_neighbors[n->node_id]; // neighbor不变
            }
            // 通过nodeid_to_neighbors构造edgeid_to_edge
            // 实际使用时edge的其他属性需要copy原图
            for(auto& [node_id, ns]: com->nodeid_to_neighbors) {
                for(auto&nei: ns) {
                    auto edge_id = dfs::make_edge_id(node_id, nei->node_id);
                    auto edge = std::make_shared<Edge>(edge_id, double(1.0));
                    com->edgeid_to_edge[edge_id] = edge;
                }
            }
            components.push_back(com);
        }
    }
    return components;
}

