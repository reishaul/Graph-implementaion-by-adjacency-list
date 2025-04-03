//reishaul1@gmail.com
#include <iostream>
#include "../Graph/Graph.hpp"
#include "../Algorithms/Algorithms.hpp"


int main(){

    graph::Graph g(4); 

    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4); 

    std::cout << "Original g graph:" << std::endl;
    g.print_graph();

    std::cout << "\nRunning BFS ON g from node 0" << std::endl;
    graph::Graph bfs_tree = graph::Algorithms::bfs(g, 0);

    std::cout << "BFS tree:" << std::endl;
    bfs_tree.print_graph();



    std::cout << "\nRunning DFS ON g from node 0" << std::endl;
    graph::Graph dfs_tree = graph::Algorithms::dfs(g, 0);

    std::cout << "DFS tree:" << std::endl;
    dfs_tree.print_graph();



    graph::Graph g1(5); 
    g1.addEdge(0, 1, 10);
    g1.addEdge(0, 2, 6);
    g1.addEdge(0, 3, 5);
    g1.addEdge(1, 3, 15);
    g1.addEdge(2, 3, 4);

    std::cout << "\nOriginal g1 graph:" << std::endl;
    g1.print_graph();



    std::cout << "\nRunning DIJKSTRA ON g1" << std::endl;
    graph::Graph dijkstra_tree = graph::Algorithms::dijkstra(g1, 0);

    std::cout << "DIJKSTRA tree:" << std::endl;
    dijkstra_tree.print_graph();



    std::cout << "\nRunning PRIM ON g1" << std::endl;
    graph::Graph prim_tree = graph::Algorithms::prim(g1);

    std::cout << "PRIM tree:" << std::endl;
    prim_tree.print_graph();



    std::cout << "\nRunning KRUSKAL ON g1" << std::endl;
    graph::Graph kruskal_tree = graph::Algorithms::kruskal(g1);

    std::cout << "KRUSKAL tree:" << std::endl;
    kruskal_tree.print_graph();


    return 0;
}



