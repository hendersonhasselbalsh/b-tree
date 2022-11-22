#pragma once   

#if !defined(HEADER_FILE_ALREADY_INCLIDED)
    #include "SortedQueue.h"
#endif // HEADER_FILE_ALREADY_INCLIDED




template<typename Tp>
void Node<Tp>::insert(Cell<Tp>* newCell, Cell<Tp>** risedCell)
{
    //this->sizes++;

    if( this->isEmpty() ){                     // empty queue
        this->first = newCell; 
        this->last  =  this->operator[]( this->size()-1 );
    return; 
    }

    if( newCell->value < this->first->value ){
        newCell->nextCell  =  this->first;
        this->first  =  newCell;
        newCell->hasNextCell = true;
        this->first->nextCell->lowerNode = newCell->higherNode;
        newCell->higherNode = nullptr;
        //this->operator[](1)->lowerNode = newCell->lowerNode;
     return;
    }

    if( newCell->value > this->last->value ){  // insert the highest value
        this->last->nextCell  =  newCell;
        this->last  =  newCell;
        newCell->hasNextCell = false;
        //this->last->lowerNode  =  this->operator[](this->sizes-2);
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

    next->lowerNode  =  newCell->higherNode;
    newCell->higherNode = nullptr;
}



template<typename Tp>
Node<Tp>** Node<Tp>::split(Cell<Tp>** risedCell){
    /*
     {a -> b -> c -> d}                         
    
              b
            /   \
        {a}   {c -> d}
    */

    Cell<Tp>* a  =  this->first;
    *risedCell  =  a->nextCell; // b
    Cell<Tp>* c  =  (*risedCell)->nextCell;

    a->nextCell = nullptr;
    (*risedCell)->nextCell  =  nullptr;

    a->higherNode  =  (*risedCell)->lowerNode;  // right de a aponta para left de b

    Node<Tp>** arrNode  =  new Node<Tp>*[2]();
    arrNode[0] = new Node<Tp>{};
    arrNode[1] = new Node<Tp>{};

    arrNode[0]->insert( a );
    arrNode[1]->insert( c );

    (*risedCell)->lowerNode   =  arrNode[0];
    (*risedCell)->higherNode  =  arrNode[1];

 return arrNode;
}



template<typename Tp>  // aux - print factory
Tp* Node<Tp>::keys()
{
    Tp* keys  =  new Tp [ this->size() ];
    for( int i = 0; i < this->size(); i++ ){
        keys[i]  =  this->operator[](i)->value;
    }

 return keys;
}



template<typename Tp>  // aux - print factory
Node<Tp>** Node<Tp>::C()
{
    Node<Tp>** nodeArr  =  new Node<Tp>* [ this->size() + 1 ];
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


template<typename Tp>
int Node<Tp>::size(){
    Cell<Tp>* currentCell  =  this->first;
    int counter  =  0;
    while( currentCell != nullptr ){
        counter++;
        currentCell  =  currentCell->nextCell;
    }
 return counter;
}


template<typename Tp>
void Node<Tp>::checkNodeIsLeaf()
{
    Cell<Tp>* currentCell  =  this->first;
    while( currentCell!=nullptr ){
        if( currentCell->hasChildren() ){
            this->isleaf = false;
            break;
        }
        currentCell  =  currentCell->nextCell;
    }
}


template<typename Tp>
bool Node<Tp>::isLeaf(){
    Cell<Tp>* currentCell  =  this->first;
    while( currentCell!=nullptr ){
        if( currentCell->hasChildren() ){
            return false;
        }
        currentCell  =  currentCell->nextCell;
    }
 return true;
}






#define HEADER_FILE_ALREADY_INCLIDED
#include "SortedQueueOperator.cpp"