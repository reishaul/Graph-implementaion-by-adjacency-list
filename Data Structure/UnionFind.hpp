#ifndef UNION_FIND_H
#define UNION_FIND_H


namespace graph {
    class UnionFind {

        private:
        int* parent;
        int* rank;
        int size;
        
        public:
        UnionFind(int n);//constructor
        ~UnionFind();//destructor

        //declaration
        int find(int x);
        void unionSets(int x, int y);
        //bool connected(int x, int y);
    };
}
#endif



