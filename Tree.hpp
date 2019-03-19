#include "Node.hpp"
namespace ariel
{
    class Tree{

    Node * _root;
    int Size;
    
    public:
        Tree();
       ~Tree();

        void insert(int);
        void remove(int);
        int size();
        bool contains(int);
        int root();
        int parent(int);
        int left(int);
        int right(int);
        void print();     
    };
}
