//
// Created by liufurui on 2023/3/12.
//

#ifndef GRAPH_ALG_DFS_H
#define GRAPH_ALG_DFS_H

#include <list>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <stack>
namespace dfs {
    enum class Color {
        White = 1,
        Gray = 2,
        Black = 3,
    };

    struct Node {
        std::string node_id;
        int find_time;
        int finish_time;
        Color color;
        Node* prev; // 算法用来记录前驱节点，使用raw pointer防止成环后导致内存泄露
        Node(const std::string& _node_id): node_id(_node_id) {}

    };
    using NodePtr = std::shared_ptr<Node>;
    using EdgeId = std::pair<std::string, std::string> ;
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2> &pair) const {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };
    struct node_ptr_hash{
        std::size_t operator() (const std::shared_ptr<Node>& node) const {
            return std::hash<std::string>()(node->node_id);
        }
    };
    struct Edge {
        EdgeId edge_id;         // 边id
        double weight;          // 边的权重
        bool is_bidirectional;  // 是否双向边
        Edge(const EdgeId& id, double w): edge_id(id), weight(w) {}
    };
    using EdgePtr = std::shared_ptr<Edge>;
    using EdgeMap = std::unordered_map<EdgeId, EdgePtr, pair_hash>;
    using NodesMap = std::unordered_map<std::string, std::shared_ptr<Node>>;
    using NeighbersMap = std::unordered_map<std::string, std::unordered_set<std::shared_ptr<Node>, node_ptr_hash>>;
    struct Graph {
        NodesMap nodeid_to_node; // nodeid 到 node的映射
        NeighbersMap nodeid_to_neighbors; // nodeid 到 邻居列表的映射
        EdgeMap edgeid_to_edge; // 变id到边的映射

    };

    inline EdgeId make_edge_id(const std::string& from_node, const std::string& to_node) {
        return {from_node, to_node};
    }

    std::stack<NodePtr> dfs(Graph& g);
    void dfs_visit(Graph& g, const std::shared_ptr<Node>& s,int& time, std::stack<NodePtr>& stack);
}



#endif //GRAPH_ALG_DFS_H
