#pragma once   

#if !defined(HEADER_FILE_ALREADY_INCLIDED)
    #include "SortedQueue.h"
#endif // HEADER_FILE_ALREADY_INCLIDED




template<typename Tp>
void Node<Tp>::insert(Cell<Tp>* newCell)
{
    this->sizes++;

    if( this->isEmpty() ){                     // empty queue
        this->first = newCell; 
        this->last  =  this->first;
    return; 
    }

    if( newCell->value < this->first->value ){
        newCell->nextCell  =  this->first->nextCell;
        this->first  =  newCell;
     return;
    }

    if( newCell->value > this->last->value ){  // insert the highest value
        this->last->nextCell  =  newCell;
        this->last  =  newCell;

    return;
    }

    // insert betyin fist and last
    Cell<Tp>* currentCell  =  this->first;
    Cell<Tp>* next  =  this->first;

    while ( next->value < newCell->value && next!=this->last){
        currentCell  =  next;
        next  =  next->nextCell;
    }

    newCell->hasNextCell = true;
    currentCell->nextCell  =  newCell;
    newCell->nextCell  =  next;
}



template<typename Tp>
Node<Tp>** Node<Tp>::split(Cell<Tp>** risedCell){

    
    // a -> b -> c -> d
    Cell<Tp>* a  =  this->first;
    *risedCell  =  a->nextCell; // b
    Cell<Tp>* c  =  (*risedCell)->nextCell;

    a->nextCell = nullptr;
    (*risedCell)->nextCell  =  nullptr;

    Node<Tp>** arrNode  =  new Node<Tp>*[2]();
    arrNode[0] = new Node<Tp>{};
    arrNode[1] = new Node<Tp>{};

    arrNode[0]->insert( a );
    arrNode[1]->insert( c );

    (*risedCell)->higherNode  =  arrNode[1];
    (*risedCell)->lowerNode   =  arrNode[0];

 return arrNode;
}



template<typename Tp>  // aux - print factory
Tp* Node<Tp>::keys()
{
    Tp* keys  =  new Tp [ this->sizes ];
    for( unsigned i = 0; i < this->sizes; i++ ){
        keys[i]  =  this->operator[](i)->value;
    }

    /*DEBUG*//*
    std::cout << "[";
    for(int i = 0; i < this->sizes; i++ ) { std::cout << keys[i] << " ";  }
    std::cout <<"]";*/
    /*DEBUG*/


 return keys;
}



template<typename Tp>  // aux - print factory
Node<Tp>** Node<Tp>::C()
{
    Node<Tp>** nodeArr  =  new Node<Tp>* [ this->sizes + 1 ];
    unsigned index = 0;
    Cell<Tp>* i = nullptr;

    for(i = this->first; i->nextCell!=nullptr; i = i->nextCell){
        nodeArr[index]  =  i->lowerNode;
        index++;
    }

    nodeArr[ index ]  =  i->lowerNode;
    nodeArr[ ++index ]  =  i->higherNode;

 return nodeArr;
}











#define HEADER_FILE_ALREADY_INCLIDED
#include "SortedQueueOperator.cpp"