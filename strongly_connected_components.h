//
// Created by liufurui on 2023/3/12.
//

#ifndef GRAPH_ALG_STRONGLY_CONNECTED_COMPONENTS_H
#define GRAPH_ALG_STRONGLY_CONNECTED_COMPONENTS_H
#include "dfs.h"
#include <vector>

namespace scc {
    using namespace dfs;
    // 图的转置： node列表不变，edge方向反转
    inline Graph build_gt(Graph& g) {
        auto nodes = g.nodeid_to_node;
        EdgeMap edges;
        for(auto& [edge_id, edge]: g.edgeid_to_edge) {
            auto&& e = std::make_shared<Edge>(make_edge_id(edge_id.second, edge_id.first), edge->weight);
            edges[make_edge_id(edge_id.second, edge_id.first)] = e;
        }
        NeighbersMap ns;
        for(auto& [edge_id, _]: edges) {
            ns[edge_id.first].insert(nodes[edge_id.second]);
        };
        return {std::move(nodes), std::move(ns), std::move(edges)};
    }
    using GraphPtr = std::shared_ptr<Graph>;
    std::vector<GraphPtr> strongly_connected_components(Graph& g);
}

#endif //GRAPH_ALG_STRONGLY_CONNECTED_COMPONENTS_H
