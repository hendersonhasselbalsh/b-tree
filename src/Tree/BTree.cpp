#pragma once


#if !defined(HEADER_FILE_ALREADY_INCLIDED)
    #include "Btree.h"
#endif // HEADER_FILE_ALREADY_INCLIDED


template<typename Tp>
BTreeStruct BTree<Tp>::getPrintStruct()
{

}


template<typename Tp>
void BTree<Tp>::print(Node<Tp>* root)
{

    if( root->isleaf ) {    }


}













#define HEADER_FILE_ALREADY_INCLIDED
#include "TreeOperator.cpp"
