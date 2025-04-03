#ifndef QUEUE_H
#define QUEUE_H

namespace graph {

    class Queue {
    private:
        struct Node {
            int num;
            Node* next;
            Node(int a) : num(a), next(nullptr) {}//constructor include initialize
        };

        int size;
        Node* first, * last;

    public:
        Queue();//constructor
        ~Queue();//destructor

        //declaration
        bool isEmpty() const;
        int getSize() const;
        int dequeue();
        void enqueue(int num);
        int getFirst() const;
    };

}

#endif 
