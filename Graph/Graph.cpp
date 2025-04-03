// reishaul1@gmail.com
/** 
 The Graph class represents an undirected graph using an adjacency list.
 It provides methods to add and remove edges, print the graph, and retrieve
 graph-related information such as the number of vertices and edges.
*/
#include "Graph.hpp"
#include <stdexcept>
#include <iostream>

namespace graph {

/**
 * @brief Constructs a graph with the given number of vertices.
 * @param num_ver The number of vertices in the graph.
 * @throws std::invalid_argument if the number of vertices is invalid.
 */
Graph::Graph(int num_ver) {
    if (num_ver > Graph::max_nodes || num_ver <= 0) {
        throw std::invalid_argument("Invalid number of vertex");
    }
    num_of_vertex = num_ver;
    adj_list = new Node*[num_ver]; // list for the neighbors

    for (int i = 0; i < num_of_vertex; i++) {
        adj_list[i] = nullptr; // initial
    }
}

Graph::~Graph() {//destructor
    for (int i = 0; i < num_of_vertex; i++) {
        Node* cur = adj_list[i];
        while (cur != nullptr) {//free the memory carefully according to what we learn
            Node* tmp = cur;
            cur = cur->next;
            delete(tmp);
        }
    }
    delete[] adj_list;
}

/**
 * @brief Adds an edge between two vertices with a specified weight.
 * @param src Source vertex.
 * @param dest Destination vertex.
 * @param w Weight of the edge.
 */
void Graph::addEdge(int src, int dest, int w) {
    if (src >= 0 && src < num_of_vertex && dest < num_of_vertex && dest >= 0) {
        //beacuse the graph is undirected-there os two direction
        adj_list[src] = new Node(dest, w, adj_list[src]);
        adj_list[dest] = new Node(src, w, adj_list[dest]);
    } else {
        std::cout << "adding this node is impossible\n";
    }
}

/**
 * @brief Adds an edge to form a tree structure (used in spanning trees).
 * @param parent Parent vertex.
 * @param child Child vertex.
 * @param w Weight of the edge.
 */
void Graph::addTreeEdge(int parent, int child, int w) {//function for addding edge to a tree 
    if (parent >= 0 && parent < num_of_vertex && child < num_of_vertex && child >= 0) {
        adj_list[parent] = new Node(child, w, adj_list[parent]);
        //adj_list[child] = new Node(parent, w, adj_list[child]);
    } else {
        std::cout << "adding this node is impossible\n";
    }
}

/**
 * @brief Removes an edge between two vertices.
 * @param src Source vertex.
 * @param dest Destination vertex.
 * @throws std::runtime_error if the edge does not exist.
 */
void Graph::removeEdge(int src, int dest) {
    if (src >= 0 && src < num_of_vertex && dest < num_of_vertex && dest >= 0) {
        bool flag = remove(src, dest);
        flag = flag && remove(dest, src); //beacuse this is a undirected graph
        if (!flag) {
            throw std::runtime_error("edge not found in the graph");
        }
    } else {
        std::cout << "cannot remove this edge\n";
    }
}
/**
 * @brief Helper function to remove an edge from the adjacency list.
 * @param src Source vertex.
 * @param dest Destination vertex.
 * @return True if the edge was successfully removed, false otherwise.
 */
bool Graph::remove(int src, int dest) {
    Node* cur = adj_list[src];
    Node* prev = nullptr;

    while (cur != nullptr && cur->dest != dest) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == nullptr) { //if the edge not in the list
        return false;
    }
    if (prev == nullptr) { // if the edge is the first one
        adj_list[src] = cur->next;
    } else { 
        prev->next = cur->next;
    }
    //free the memory
    delete cur;
    return true;
}

/**
 * @brief Prints the adjacency list representation of the graph.
 */
void Graph::print_graph() {//printing the graph in a logical way
    for (int i = 0; i < num_of_vertex; i++) {
        std::cout << "Node " << i << ": ";
        Node* cur = adj_list[i];
        while (cur) {
            std::cout << "(" << cur->dest << ", weight: " << cur->weight << ") ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Returns the number of vertices in the graph.
 * @return The number of vertices.
 */
int Graph::get_num_of_vertex() const{
    return num_of_vertex;
}

/**
 * @brief Retrieves all edges in the graph.
 * @param numEdges Reference to store the number of edges found.
 * @return A dynamically allocated array of edges.
 */
Edge* Graph::get_edges(int &numEdges) const {
    numEdges = 0;//counter

    
    for (int i = 0; i < num_of_vertex; i++) {
        Node* cur = adj_list[i];
        while (cur != nullptr) {
            if (i < cur->dest) { // the logic for adding edge
                numEdges++;
            }
            cur = cur->next;
        }
    }

    Edge* edges = new Edge[numEdges];//array for the edges
    int index = 0;

    for (int i = 0; i < num_of_vertex; i++) {
        Node* cur = adj_list[i];
        while (cur != nullptr) {
            if (i < cur->dest) { //for safety
                edges[index++] = Edge(i, cur->dest, cur->weight);
            }
            cur = cur->next;
        }
    }
    return edges;
}

}
