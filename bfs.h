//
// Created by liufurui on 2023/3/12.
//

#ifndef GRAPH_ALG_BFS_H
#define GRAPH_ALG_BFS_H

#include <list>
#include <string>
namespace BFS {
    enum Color {
        White = 1,
        Gray = 2,
        Black = 3,
    };
    struct Node{
        std::string node_id;
        Color color;
        int dis;
        std::shared_ptr<Node> prev; // 前驱节点
        Node(const std::string& _node_id): node_id(_node_id){}
    };
    using Gragh = std::list<std::list<std::shared_ptr<Node>>>;

    void BFS(Gragh& g, std::shared_ptr<Node> s);
    void print_path(Gragh& g, const std::shared_ptr<Node>& s, const std::shared_ptr<Node>& v);
}

#endif //GRAPH_ALG_BFS_H
