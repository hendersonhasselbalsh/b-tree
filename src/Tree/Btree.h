#pragma once

#include <iostream>
#include "../TreeNode/SortedQueue.h"
#include "../TreePrinter/BTreePrinter.h"



template<typename Tp>
class BTree {

    public:
        Node<Tp>* root  =  nullptr;
        int nodes  =  0;


    public:

        bool isEmty(){  return bool(this->root == nullptr);  }
        
};