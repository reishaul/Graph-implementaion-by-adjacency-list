#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.hpp"

namespace graph {

class Graph {
public:
    struct Node {
        int dest;
        int weight;
        Node* next;

        Node(int d, int w, Node* n = nullptr) {
            dest = d;
            weight = w;
            next = n;
        }
    };
    static const int max_nodes = 100;
    int num_of_vertex;
    Node** adj_list; // our list

    bool remove(int src, int dest);

public:
  
    Graph(int num_ver);//constructor

    ~Graph();// destructor
   
    //declaration of all the function we used in Graph.cpp
    void addEdge(int src, int dest, int weight = 1);

    void addTreeEdge(int parent, int child, int w);

    void removeEdge(int src, int dest);

    void print_graph();

    int get_num_of_vertex() const;
    
    Edge* get_edges(int &numEdges) const;

    Node** get_adj_list() const{return adj_list;}

};
}

#endif
