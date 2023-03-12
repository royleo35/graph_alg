//
// Created by liufurui on 2023/3/12.
//

#ifndef GRAPH_ALG_TOPOLOGICAL_SORT_H
#define GRAPH_ALG_TOPOLOGICAL_SORT_H


#include<list>
#include<string>
#include "dfs.h"

namespace topolotic_sort {
    // 拓扑排序可以在dfs中每个节点访问完成时插入链表头，这里先DFS遍历完链表之后，对节点列表按照finish_time排序即可
    using NodePtr = std::shared_ptr<dfs::Node>;
    std::list<NodePtr> topolotic_sort(dfs::Graph& g);
}


#endif //GRAPH_ALG_TOPOLOGICAL_SORT_H
