//reishaul1@gmail.com
//implementation of queue
#include <stdexcept>
#include "Queue.hpp"

namespace graph{
   
    Queue::Queue(): size(0), first(nullptr), last(nullptr) {} // constructor
    
    Queue::~Queue(){//destructor
        while(!isEmpty()){
        dequeue();
        }

    }
    bool Queue::isEmpty() const{//usful func
        return first==nullptr;
    }

    int Queue::getSize() const{
        return size;
    }
    int Queue::dequeue(){//extract
        if(isEmpty()){
            throw std::runtime_error("Queue is empty");
        }
    
        Node* tmp=first;
        int num=first->num;
        first= first->next;
        size--;
        if(first==nullptr){
            last=nullptr;}

        delete tmp;
        return num;
    }

    void Queue::enqueue(int num){//insert object
        Node* tmp=new Node(num );

        if(isEmpty()){
            first=last=tmp;
        }
        else{
            last->next=tmp;
            last=tmp;

        }
        size++;

    }
    
    int Queue::getFirst() const{
        if(isEmpty()){
            throw std::runtime_error("there is no nodes");
            
        }
    
        return first->num;
    
    }
    
}
