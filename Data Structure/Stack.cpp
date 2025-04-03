//reishaul1@gmail.com
//implemetation of stack
#include <stdexcept>
#include "Stack.hpp"

namespace graph{
   
    Stack::Stack(): top(nullptr) {} // constructor
    
    Stack::~Stack(){//destructor
        while(!isEmpty()){
        pop();
        }

    }
    bool Stack::isEmpty() const{
        return top==nullptr;
    }

 
    int Stack::pop(){//extract from the stack bring the last which insert
        if(isEmpty()){
            throw std:: out_of_range("stack is empty");
        }
    
        Node* tmp=top;
        int num=tmp->num;
        top= top->next;

        delete tmp;
        return num;

    }
    //insert to the first place
    void Stack::push(int num){
        Node* tmp=new Node(num );
        tmp->next=top;
        top=tmp;

    }
    //only chek the first element without removing
    int Stack::peek() const{
        if(isEmpty()){
            throw std::runtime_error("the stack is empty");
            
        }
        return top->num;
    
    }
    
}
