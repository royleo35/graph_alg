//
// Created by liufurui on 2023/3/12.
//
#include <iostream>
#include "dfs.h"
#include <stack>

using namespace dfs;
std::stack<NodePtr> dfs::dfs(dfs::Graph& g) {
    // init node attr
    for(auto& [_, node]: g.nodeid_to_node) {
        node->color = Color::White;
        node->prev = nullptr;
    }
    // init global time
    int time = 0;

    // 从每个没有访问过的节点节点进行深度优先搜索
    std::stack<NodePtr> stk;
    for(auto& [_, node]: g.nodeid_to_node)  {
        if(node->color == Color::White) {
            dfs::dfs_visit(g, node, time, stk);
        }
    }
    return stk;
}

void dfs::dfs_visit(Graph& g, const std::shared_ptr<Node>& s, int& time,  std::stack<NodePtr>& stack) {
    time++;
    // first touch node s
    s->find_time = time;
    s->color = Color::Gray;
    auto& ns = g.nodeid_to_neighbors[s->node_id];
    for(auto& n : g.nodeid_to_neighbors[s->node_id]) {
        // 如果node n 没有被访问过，则将n的前驱设置为s, 并从节点n开始进行深度优先搜索
        if(n->color == Color::White) {
            n->prev = s.get();
            dfs::dfs_visit(g, n, time, stack);
        }
    }
    // 至此，节点s的邻居已经访问完毕
    time++;
    s->color = Color::Black;
    s->finish_time = time;
    stack.push(s);
    // std::cout<<"node: "<<s->node_id<<" visited.\n";
}