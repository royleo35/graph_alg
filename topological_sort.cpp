//
// Created by liufurui on 2023/3/12.
//

#include "topological_sort.h"

std::list<topolotic_sort::NodePtr> topolotic_sort::topolotic_sort(dfs::Graph &g) {
    dfs::dfs(g);
    std::list<topolotic_sort::NodePtr> l;
    for(auto& [_, node]: g.nodeid_to_node) {
        l.push_back(node);
    }
    // 逆序 因为深度优先搜索子节点先被探索完，父节点后被探索完
    l.sort([](auto& a, auto& b){return a->finish_time > b->finish_time;});
    return l;
}