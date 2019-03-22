#include "Tree.hpp"
#include <stdexcept>
#include <iostream>

/////////////////////////////////////Auxiliary functions///////////////////////////////////

void printBT(const std::string& prefix, const Node* treeRoot, bool isLeft){
    if( treeRoot != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << treeRoot->value << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), treeRoot->right, true);
        printBT( prefix + (isLeft ? "│   " : "    "), treeRoot->left, false);
    }
};

Node* createNode(int x){
    struct Node* temp = new Node;
    temp->value = x;
    temp->left = temp->right = nullptr;
    return temp;
};

//destructor function
void destruct(Node * root){
    if(root != nullptr){
        destruct(root->left);
        destruct(root->right);
        delete(root);
    }
};


/////////////////////////////////////Constructor///////////////////////////////////////////

ariel::Tree::Tree(){
    this->_root=nullptr;
    this->Size=0;
};

ariel::Tree::~Tree(){
    destruct(this->_root);
};

/////////////////////////////////////Tree methods//////////////////////////////////////////

void ariel::Tree::insert(int x){
    if(this->Size == 0){
        _root = createNode(x);
        this->Size++;
    }
    else{
        Node * temp = createNode(x);
        Node * current = _root;

        bool exit = false;

        while(!exit){
            if(x < current->value){
                if(current->left == nullptr){
                    current->left = temp;
                    exit = true;
                    this->Size++;
                }
                else{
                    current = current->left;
                }
            }
            else if (x > current->value){                
                if(current->right == nullptr){
                    current->right = temp;
                    exit = true;
                    this->Size++;
                }
                else{
                    current = current->right;
                }
            }
            else{
                destruct(temp);
                throw std::out_of_range{ "The number is already exists..." };
            }
        }
    }
}

void ariel::Tree::remove(int x){
    if(!Tree::contains(x)){
        throw std::out_of_range{"Number doesn't exist in tree..."};
    }

    Node * current = _root;
    Node * father = nullptr;

    while(current->value != x){
        if(current->value > x){
            father = current;
            current = current->left;
        }
        else{
            father = current;
            current = current->right;;
        }
    }

    if(current->left == nullptr && current->right == nullptr){
        if(father == nullptr){
            _root = nullptr;
        }
        else if (x < father->value){
            father->left = nullptr;
        }
        else{
            father->right = nullptr;
        }

        destruct(current);
        this->Size--;
    }

    else if(current->left == nullptr){
        if(father == nullptr){
            _root = current->right;
            current->right = nullptr;
        }
        else if(x < father->value){
            father->left = current->right;
            current->right = nullptr;
        }
        else{
            father->right = current->right;
            current->right = nullptr;
        }
        destruct(current);
        this->Size--;
    }

    else if(current->right == nullptr){
        if(father == nullptr){
            _root = current->left;
            current->left = nullptr;
        }
        else if(x < father->value){
            father->left = current->left;
            current->left = nullptr;
        }
        else{
            father->right = current->left;
            current->left = nullptr;
        }
        destruct(current);
        this->Size--;
    }

    else {
        Node * replace = current->left;
        int value = replace->value;
        while(replace->right != nullptr){
            replace = replace->right;
            value = replace->value;
        }
        this->remove(replace->value);
        current->value = value;
    }
};

int ariel::Tree::size(){
    return this->Size;
};

bool ariel::Tree::contains(int x){
    Node * temp = _root;
    while(temp != nullptr){
        if(temp->value > x){
            temp = temp->left;
        }
        else if(temp->value < x){
            temp = temp->right;
        }
        else{
            return true;
        }
    }
    return false;
};

int ariel::Tree::root(){
    return this->_root->value;
};

int ariel::Tree::parent(int x){

    if(this->Size == 0){
        throw std::out_of_range{"Tree is empty..."};
    }
    if(this->Size == 1 || this->_root->value == x){
        throw std::out_of_range{"This number is a root and doesn't have parents..."};
    }

    bool numExist = this->contains(x);

    int parent;
    if(numExist){
        Node * temp = _root;
        Node * next = nullptr;
        while(temp != nullptr){
            if(temp->value > x){
                parent = temp->value;
                temp = temp->left;
            }
            else if(temp->value < x){
                parent = temp->value;
                temp = temp->right;
            }
            else{
                return parent;
            }
        }
    }
    else {
        throw std::out_of_range{"Number doesn't exist in tree..."};
    }
    return parent;
};


int ariel::Tree::left(int x){
    if(this->Size == 0){
        throw std::out_of_range{"Tree is empty..."};
    }
    if(this->Size == 1){
        throw std::out_of_range{"This number is a root and doesn't have child..."};
    }
    bool numExist = this->contains(x);

    if(numExist){
        Node * temp = _root;
        while(temp != nullptr){
            if(temp->value > x){
                temp = temp->left;
            }
            else if(temp->value < x){
                temp = temp->right;
            }
            else{
                break;                          //we found the node x
            }
        }
        if(temp->left){                         //if its not null
            return temp->left->value;
        }
        else{
          throw std::out_of_range{"This number doesn't have left child..."};
        }
    }
    else{
        throw std::out_of_range{"This number doesn't contains in tree..."};
    }
};

int ariel::Tree::right(int x){
    if(this->Size == 0){
        throw std::out_of_range{"Tree is empty..."};
    }
    if(this->Size == 1){
        throw std::out_of_range{"This number is a root and doesn't have child..."};
    }
    bool numExist = this->contains(x);

    if(numExist){
        Node * temp = _root;
        while(temp != nullptr){
            if(temp->value > x){
                temp = temp->left;
            }
            else if(temp->value < x){
                temp = temp->right;
            }
            else{
                break;                          //we found the node x
            }
        }
        if(temp->right){                         //if its not null
            return temp->right->value;
        }
        else{
          throw std::out_of_range{"This number doesn't have right child..."};
        }
    }
    else{
        throw std::out_of_range{"This number doesn't contains in tree..."};
    }
};

void ariel::Tree::print(){
    if(this->Size == 0){
        std::cout << "-NULL-" << std::endl;
    }
    else{
        printBT("", _root, false);
    }
};

