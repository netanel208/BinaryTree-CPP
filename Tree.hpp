#include "Node.hpp"
namespace ariel
{
    class Tree{

    Node * _root;
    int Size;
    int val = 0;
    
    public:
        Tree();
       ~Tree();

        void destruct(Node * root);
        void insert(int);
        void remove(int);
        int size();
        bool contains(int);
        int root();
        int parent(int);
        int left(int);
        int right(int);
        void print();   
        void printVal();   
    };
}
