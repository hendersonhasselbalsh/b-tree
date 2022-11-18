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





#define HEADER_FILE_ALREADY_INCLIDED
#include "SortedQueueOperator.cpp"