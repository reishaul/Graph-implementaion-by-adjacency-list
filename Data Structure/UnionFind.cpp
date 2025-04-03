//reishaul1@gmail.com
//implementation of UnionFind
#include <stdexcept>
#include <iostream>
#include "UnionFind.hpp"

namespace graph{
    UnionFind::UnionFind(int n){
        size = n;
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;  //first- each node is itself parent 
            rank[i] = 0;     // number of children
        }
    }

    // return the candidate of a grup according to what we learn
    int UnionFind::find(int x) {
        if(x<0||x>=size){
            std::cerr <<"error:("<< x <<") is out of bounds"<<std::endl;
            exit(1);

        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
    //union the group in one connect component
    void UnionFind::unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;
    
        // do union according to rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

 
    }

    // bool UnionFind::connected(int x, int y) {
    //     return find(x) == find(y);
    // }

    
    UnionFind::~UnionFind() {// destructor
        delete[] parent;
        delete[] rank;
    }
}




