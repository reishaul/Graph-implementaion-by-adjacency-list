//reishaul1@gmail.com
/**
The Algorithms class provides static methods for performing BFS, DFS, Dijkstra, Prim, and Kruskal algorithms on a graph.
This class is designed to operate on an instance of the Graph class, offering various algorithms for graph traversal,
shortest path calculations, and minimum spanning tree construction. It relies on additional data structures such as
Queue, Stack, MinHeap, and UnionFind to implement these algorithms efficiently.
*/
#include "Algorithms.hpp"
#include <stdexcept>
#include <iostream>
#include "../Data Structure/Queue.hpp"
#include "../Data Structure/Stack.hpp"
#include "../Data Structure/MinHeap.hpp"
#include "../Data Structure/UnionFind.hpp"
#include "../Graph/Edge.hpp"


namespace graph {

/**
* @brief Performs Breadth-First Search (BFS) on a graph.
* @param graph The graph to traverse.
* @param src The source vertex.
* @return A spanning tree representing the BFS traversal.
* @throws std::invalid_argument if src is out of bounds.
*/  
Graph Algorithms::bfs(Graph& graph,int src){//return the nodes in order which visited

    if(src<0||src>=graph.get_num_of_vertex()){//condition
        throw std::invalid_argument("the src is invalid");
    }

    int a=graph.get_num_of_vertex();
    
    Graph tree(a);
    bool* visited=new bool[a]();//array for menage the visited nodes

    int* parent = new int[a];
    for (int i = 0; i < a; i++) {
        parent[i] = -1; // initialize
    }


    //now using the queue functionallity 
    Queue q;//queue by my implementation
    visited[src]=true;
    
    q.enqueue(src); 
    parent[src]=-1;//the parent of the src node is -1(null)

    while(!q.isEmpty()){
        int current=q.getFirst();
        q.dequeue();

        const Graph::Node* tmp=graph.get_adj_list()[current];//check the  neighbors
        while(tmp!=nullptr){
            int adj_vertex=tmp->dest;

            if(!visited[adj_vertex]){
                visited[adj_vertex]=true;//sign that this vertex is visited
                parent[adj_vertex]=current;


                tree.addEdge(current, adj_vertex, tmp->weight);
                //tree.addTreeEdge(current, adj_vertex, tmp->weight);
                
                q.enqueue(adj_vertex);

            }
            tmp=tmp->next;

        }
    }
    delete[] visited;
    
    delete[] parent;
    return tree;
    }
    /**
     * @brief Performs Depth-First Search (DFS) on a graph.
     * @param graph The graph to traverse.
     * @param src The source vertex.
     * @return A spanning tree representing the DFS traversal.
     * @throws std::invalid_argument if src is out of bounds.
     * 
     */

    Graph Algorithms::dfs(Graph& graph, int src) {
        if(src<0 || src>=graph.get_num_of_vertex()){
            throw std::invalid_argument("the src is invalid");
        }
        
        int a = graph.get_num_of_vertex();
        Graph tree(a);
        bool* visited = new bool[a]();
    
        // start the scan from the first node
        dfs_util(graph, src, tree, visited);
    
        // check if there is nodes which we no visited yet
        for(int i = 0; i < a; i++) {
            if(!visited[i]) {
                dfs_util(graph, i, tree, visited);
            }
        }
    
        delete[] visited;//free the memory
        return tree;
    }

    /**
     * @brief Utility function for DFS traversal.
     * @param graph The graph to traverse.
     * @param src The source vertex.
     * @param tree The resulting DFS tree.
     * @param visited Array to track visited nodes.
     */

    void Algorithms::dfs_util(Graph& graph, int src, Graph& tree, bool* visited) {//I'm spilit dfs to two function for my convenience 
        Stack s;//my implementation for stack
        int* parent = new int[graph.get_num_of_vertex()];

        for(int i = 0; i < graph.get_num_of_vertex(); i++) {
            parent[i] = -1;
        }

        s.push(src);
    
        while(!s.isEmpty()) {//main logic
            int cur = s.pop();
            
            if(visited[cur]) continue;
            
            visited[cur] = true;

            if(parent[cur]!=-1){
                const Graph::Node* tmp = graph.get_adj_list()[parent[cur]];
                int weight = 1; // Default weight

                while(tmp != nullptr) {
                    if(tmp->dest == cur) {
                        weight = tmp->weight;
                        break;
                    }
                    tmp = tmp->next;
                }
                
                tree.addTreeEdge(parent[cur], cur, weight);

            }
    
            const Graph::Node* tmp = graph.get_adj_list()[cur];
            Stack tmpStack;
            while (tmp != nullptr) {
                int neig = tmp->dest;
    
                if(!visited[neig]) {
                    parent[neig]=cur;
                    tmpStack.push(neig);
                }
                tmp = tmp->next;
            }
                    // Push from temporary stack to main stack
            while(!tmpStack.isEmpty()) {
                s.push(tmpStack.pop());
            }

        }
        delete[] parent;
    }

     /**
     * @brief Implements Dijkstra's algorithm to find the shortest paths from a source vertex.
     * @param graph The input graph.
     * @param src The source vertex.
     * @return A tree representing the shortest paths from the source.
     * @throws std::invalid_argument if src is out of bounds.
     */
    Graph Algorithms::dijkstra(Graph& graph,int src){
        const int MAX_INT= 2147483647;//const of the biggest integet in cpp- using this later

        if(src<0||src>=graph.get_num_of_vertex()){
            throw std::invalid_argument("the src is invalid");
        }
    
        int a=graph.get_num_of_vertex();
        
        Graph tree(a);

        int* w = new int[a];//weighs array
        int* parent = new int[a];//parent array

        for (int i = 0; i < a; i++) {
            w[i] = MAX_INT; //initialize 
            parent[i]=-1;
    
        }
        w[src]=0;//according to the algorithem
        MinHeap m(a);
        m.push(src,0);



        while (!m.isEmpty()){
            MinHeap::HeapNode cur= m.pop();
            int u= cur.vertex;

    
            Graph::Node* neig = graph.get_adj_list()[u];
            while (neig != nullptr) {
                int v = neig->dest;
                double Edge_weight=neig->weight;

                if(w[u] != MAX_INT &&w[u]+Edge_weight<w[v]){
                    w[v]=w[u]+Edge_weight;
                    parent[v]=u;
                    m.push(v, w[v]);
                }
                neig=neig->next;

            }
        }
        for(int i=0; i<a;i++){
            if(parent[i]!=-1){

                tree.addTreeEdge(parent[i], i, w[i]);//
                //tree.addEdge(parent[i],i,w[i]-w[parent[i]]);
            }

        }
        for(int i = 0; i < a; i++) {//for the isolated vertics
            if(parent[i] == -1 && i != src) {
                tree.addTreeEdge(i, i, MAX_INT);
            }
        }

        //free the memory
        delete[] w;
        delete[] parent;

        return tree;
    }


     /**
     * @brief Implements Prim's algorithm to find the Minimum Spanning Tree (MST).
     * @param graph The input graph.
     * @return A graph representing the MST.
     * @throws std::invalid_argument if the number of vertices is less than or equal to zero.
     */
    Graph Algorithms::prim(Graph& graph){
        
        int a = graph.get_num_of_vertex();
        //exception
        if(a<=0){
            throw std::invalid_argument("not enough vertex");
        }


        Graph tree(a);
        int* parent=new int[a];
        bool* mark = new bool[a]();//vertex that we already visit
        int* val=new int[a];

        // Initialize all keys as infinite and Set as false according to the algo' we learn
        for (int i = 0; i < a; i++) {
            val[i] = MAX_INT;
            mark[i] = false;
            parent[i] = -1;
        }
        parent[0]=-1;
        val[0]=0;



        MinHeap m(a);
        m.push(0,0);

        while(!m.isEmpty()){
            MinHeap::HeapNode cur=m.pop();
            int u=cur.vertex;
            mark[u]=true;//mark that we visit


            Graph::Node* neig=graph.get_adj_list()[u];
            while(neig!=nullptr){

                double weight=neig->weight;
                int v= neig->dest;
            
            if(!mark[v]&&weight<val[v]){
                parent[v]=u;
                val[v]=weight;
                m.push(v,weight);

            }
            neig=neig->next;
        }
    }
    for(int i=1; i<a; i++){
        if(parent[i]!=-1){//if we already visit the node
            Graph::Node* cur=graph.get_adj_list()[parent[i]];

            double Eweight=0;//first initialization
            while(cur!=nullptr){//go over the neighbors
                if(cur->dest==i){//if it match the dest vertex
                    Eweight=cur->weight;
                    break;

                }
                cur=cur->next;//moving to the next node
            }
            tree.addTreeEdge(parent[i],i,Eweight);

        }
    }

    //free the memory
    delete[] parent;
    delete[] mark;
    delete[] val;
    return tree;

    }

    /**
     * @brief Implements Kruskal's algorithm to find the Minimum Spanning Tree (MST).
     * @param graph The input graph.
     * @return A graph representing the MST.
     * @throws std::invalid_argument if the number of vertices is less than or equal to zero.
     */
    Graph Algorithms::kruskal(Graph& graph){

        int a = graph.get_num_of_vertex();
        
        if(a<=0){
            throw std::invalid_argument("not enough vertex");
        }

        Graph tree(a);
        int edgeCount=0;
        Edge* edges=graph.get_edges(edgeCount);

        bubbleSort(edges,edgeCount);
        UnionFind U(a);

        //helpers
        int e=0;
        int i=0;

        while (i < a - 1 && e < edgeCount) {//until we achive v-1 edges
            // take the next edge 
            Edge nextEdge = edges[e++];
            
            int x = U.find(nextEdge.src);
            int y = U.find(nextEdge.dest);

            if (x != y) {// if the edge not create circle
                
                tree.addEdge(nextEdge.src, nextEdge.dest, nextEdge.weight);
            
                U.unionSets(x, y);//union x and y to connect x and y in a one connect component
                i++;
            }
        }
        //free the memory
        delete[] edges;
        return tree;
    }
}






