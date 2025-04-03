#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include "../Graph/Graph.hpp"


const int MAX_INT = 2147483647; 

namespace graph {

    class MinHeap {
        
        public:
            struct HeapNode {
                int vertex;
                int distance;
                // int source;//new
                // int weight;//new
                
                HeapNode(int v = 0, int dist = MAX_INT) : 
                    vertex(v), distance(dist) {}
                
                // if the distance of the other object is bigger then false
                bool operator>(const HeapNode& other) const {
                    return distance > other.distance;
                }

            };
            
        private:
            HeapNode* heap;
            int* helper; 
            int capacity;
            int size;
            //declaration
            void swap(int a, int b);
            void heapifyUp(int index);
            void heapifyDown(int index);

        public:
        MinHeap(int ver);//constructor
        ~MinHeap();//destructor
        //more declaration
        void push(int ver, int dist);
        HeapNode pop();
        bool isEmpty();
        int getSize();
        
    };
}

#endif


