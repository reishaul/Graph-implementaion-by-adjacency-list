//reishaul1@gmail.com
/**
 * implementatiom of a min heap
 */
#include <stdexcept>
#include "MinHeap.hpp"

namespace graph{
    MinHeap::MinHeap(int ver){//data structor for prim algorithem
        capacity = ver;
        heap = new HeapNode[ver];
        helper = new int[ver];
        
        // initialize
        for (int i = 0; i < ver; ++i) {
            helper[i] = -1;
        }
        
        size = 0;
    }
    
    MinHeap::~MinHeap(){//destructor
        delete[] heap;
        delete[] helper;

    }

    //here i asked the chat gpt for which function minheap consist
    void MinHeap::swap(int x, int y){
        HeapNode temp = heap[x];
        heap[x] = heap[y];
        heap[y] = temp;
        
        helper[heap[x].vertex] = x;
        helper[heap[y].vertex] = y;
    }
    //function which her role is to keep the heap orgenaized
    void MinHeap::heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent].distance > heap[index].distance) {
            swap(parent, index);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    //function which her role is to keep the heap orgenaized
    void MinHeap::heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left].distance < heap[smallest].distance)
            smallest = left;

        if (right < size && heap[right].distance < heap[smallest].distance)
            smallest = right;

        if (smallest != index) {
            swap(index, smallest);
            heapifyDown(smallest);
        }
    }

    //insert node to the heap
    void MinHeap::push(int vertex, int dist) {
        if (size == capacity) {
            throw std::runtime_error("Heap is full");
        }

        // if we already see this node
        if (helper[vertex] != -1) {
            int index = helper[vertex];
            
            // check if the new destination is smaller and if yes- update
            if (dist < heap[index].distance) {
                heap[index].distance = dist;
                heapifyUp(index);
            }
            return;
        }

        
        heap[size] = HeapNode(vertex, dist);// adding new node
        helper[vertex] = size;
        heapifyUp(size);//to keep correctness in the heap
        size++;//trivial
    }


    //extract node from the heap
    MinHeap::HeapNode MinHeap::pop() {
        if (size <= 0) {
            throw std::runtime_error("Heap is empty");
        }

        HeapNode root = heap[0];
        
        // replace the root with the last element- we learn in data stracure course
        heap[0] = heap[size - 1];
        helper[heap[0].vertex] = 0;
        helper[root.vertex] = -1; 
        
        size--;
        
        // to keep correctness
        if (size > 0) {
            heapifyDown(0);
        }
        
        return root;
    }


    bool MinHeap::isEmpty(){//very useful function
        return size==0;
    }
    int MinHeap::getSize(){
        return size;
    }

}



