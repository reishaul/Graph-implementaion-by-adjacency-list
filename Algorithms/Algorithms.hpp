
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "../Graph/Graph.hpp"
#include "../Data Structure/Queue.hpp"
#include "../Data Structure/Stack.hpp"
#include "../Data Structure/MinHeap.hpp"
#include "../Data Structure/UnionFind.hpp"
#include "../Graph/Edge.hpp"

#include <iostream>

namespace graph {
class Algorithms{
    ////declaration of all the function we used in Algorithems.cpp
    public:
    static Graph bfs(Graph&graph, int src);
    static Graph dfs(Graph&graph, int src);
    static void dfs_util(Graph& graph, int src, Graph& tree, bool* visited);
    static Graph dijkstra(Graph& graph,int src);
    static Graph prim(Graph& graph);
    static Graph kruskal(Graph& graph);
};
}

#endif 


