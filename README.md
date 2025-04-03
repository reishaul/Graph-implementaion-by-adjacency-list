# GRAPH IMPLEMENTATION BY ADJACENCY LIST

## Project Description

In this project, we were tasked with implementing a graph using an adjacency list without relying on standard libraries. To accomplish this, I implemented the following data structures:
- **Queue**
- **Stack**
- **Union-Find**
- **MinHeap**
- **Edge Object**

These data structures were used to implement the required algorithms, and some were added for convenience and better understanding.

## Project Structure

The project includes the following classes:

1. **Graph**  
   Represents a graph with a fixed number of vertices. It supports adding/removing edges and printing the graph.

2. **Algorithms**  
   Implements classic algorithms on graphs:
   - **BFS**: Returns a rooted tree from the BFS traversal.
   - **DFS**: Returns a DFS forest.
   - **Dijkstra**: Computes the shortest paths.
   - **Prim**: Computes the Minimum Spanning Tree (MST).
   - **Kruskal**: Computes the Minimum Spanning Tree (MST).

3. **UnionFind**  
   Implements the Union-Find data structure for efficiently handling dynamic connectivity.

4. **Additional Data Structures**  
   Queue, Stack, MinHeap, and Edge object.

## System Requirements

The project was compiled using the g++ compiler:
g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0


## AI Tools Used

For the **Prim** function implementation, I provided my existing code along with the output of the tree (which I did not fully understand its formation). I received guidance on how to fix the issue and adjust my approach.

## Answer
Union-Find Data Structure

For the implementation of **Union-Find**, after reviewing the data structure in the course on algorithms, I asked about the key functionalities that the Union-Find structure should provide.  
The main functions in **Union-Find** are:
1. **makeSet(int n)** – Initializes `n` disjoint sets, where each element starts as its own set (usually implemented in the constructor).
2. **find(int x)** – Finds the root of the set to which `x` belongs (with path compression for optimization).
3. **unionSet(int x, int y)** – Merges two disjoint sets (uses either "union by rank" or "union by size" to improve performance).
4. **isConnected(int x, int y)** – Checks if two elements belong to the same set (i.e., if they share the same root).
5. **print()** (Optional) – Prints the `parent[]` array for debugging purposes.
6. **~UnionFind()** – Destroys dynamically allocated memory if dynamic memory allocation is used.

## Compilation and Running

To build, compile, and run the project, you can use the following `make` commands:

- `make` - Builds the `.o` files after linking.
- `make Main` - Runs the sample file.
- `make test` - Runs the test file.
- `make valgrind` - Checks for memory leaks.
- `make clean` - Cleans the `.o` files created during compilation.

## Error Handling

Additionally, I implemented exception throwing for cases where invalid input is received. This helps ensure that the program handles incorrect data gracefully.

## Conclusion

This project demonstrates how to build a graph and implement various classic algorithms using only fundamental data structures, while also avoiding the use of standard C++ libraries.
