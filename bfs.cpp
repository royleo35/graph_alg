//
// Created by liufurui on 2023/3/12.
//
#include "bfs.h"
#include <limits>
#include <queue>
#include <iostream>
using namespace BFS;

static std::list<std::shared_ptr<Node>> find_neighbors(const Gragh& g, const std::shared_ptr<Node>& node) {
    for(auto&l: g) {
        if(l.begin()->get()->node_id == node->node_id) {
            return {++l.begin(),l.end()};
        }
    };
    return {};
}

// 三色标记，广度优先搜索
void BFS::BFS(Gragh& g, std::shared_ptr<Node> s) {
    // init
    for(auto& l: g) {
        for(const auto& node: l) {
            auto& n = *node;
            // s node
            if(n.node_id == s->node_id) {
                n.color = Color::Gray;
                n.dis = std::numeric_limits<int>::max();
                n.prev = nullptr;
            } else {
                n.color = Color::White;
                n.dis = 0;
                n.prev = nullptr;
            }
        }
    }
    // bfs
    std::queue<std::shared_ptr<Node>> q;
    q.push(s);
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        auto&& nei = find_neighbors(g, u);
        for(auto&node: nei) {
            auto& n = *node;
            // first time touched, color gray
            if(n.color == Color::White) {
                n.color = Color::Gray;
                n.dis += 1;
                n.prev = u;
                // enqueue n
                q.push(node);
            }
        }
        // already scan u's neighbors, u can color black
        u->color = Color::Black;
        std::cout<<"node:"<<u->node_id<<" visited\n";
    }
}

void BFS::print_path(Gragh& g, const std::shared_ptr<Node> &s, const std::shared_ptr<Node> &v) {
    if(s->node_id == v->node_id) {
        std::cout<<s->node_id<<"->";
    } else if (v->prev == nullptr){
        std::cout<<"no path from: "<<s->node_id<<" to: "<<v->node_id<<std::endl;
    } else {
        BFS::print_path(g, s, v->prev);
        std::cout<<v->node_id<<"->";
    }
}