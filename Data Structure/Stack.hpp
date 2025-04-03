#ifndef STACK_H
#define STACK_H

namespace graph {

    class Stack {
    private:
        struct Node {
            int num;
            Node* next;
            Node(int a) : num(a), next(nullptr) {}
        };

        Node* top;

    public:
        Stack();//constructor
        ~Stack();//destructor
        
        //declaration
        bool isEmpty() const;
        //int getSize() const;
        int pop();
        void push(int num);
        int peek() const;
    };

}

#endif
