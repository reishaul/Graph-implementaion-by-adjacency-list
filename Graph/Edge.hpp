
#ifndef EDGE_H
#define EDGE_H

struct Edge {
    //parameters for the kruskal algorithem
    int src;     
    int dest;     
    int weight; 

    //constructor
    Edge() :src(0), dest(0), weight(0){}
    Edge(int s, int d, int w): src(s), dest(d), weight(w) {}
};


void bubbleSort(Edge* edges, int n);

#endif 