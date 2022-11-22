#pragma once

#include <iostream>
#include "../TreeNode/SortedQueue.h"
//#include "../TreePrinter/BTreePrinter.h"



template<typename Tp>
class BTree {

    public:
        Node<Tp>* root  =  nullptr;
        int nodes  =  0;

        Cell<Tp>* insert( Tp val, Node<Tp>* node, bool* shouldInsert);


    public:

        BTree(){ this->root  =  new Node<Tp>{}; }

        bool isEmty(){  return bool(this->root == nullptr);  }
        void insert( Tp element){  
            bool shouldInser = true;
            this->insert( element, this->root, &shouldInser );  
        }
        
};



#define HEADER_FILE_ALREADY_INCLIDED
#include "Btree.cpp"