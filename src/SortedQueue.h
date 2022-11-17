#pragma once

#include <iostream>

template<typename Tp>
class Node {

    public:

        template<typename T>
        struct Cell {
            T value;
            Cell* nextCell  =  nullptr;
            Node<T>* higherNode  =  nullptr;
            Node<T>* lowerNode  =  nullptr;

            Cell(T val) : value(val){}
        };

        int sizes = 0;
        bool isleaf  =  true;
        Cell<Tp>* first  =  nullptr;
        Cell<Tp>* last  =  nullptr;

    public:
        
        int size(){ return this->sizes; }
        bool isLeaf(){ return this->isleaf; }
        bool isEmpty(){ return bool(this->first == nullptr); }

        void insert(Tp val){ this->insert( new Cell<Tp>(val) ); }
        void insert(Cell<Tp>* newCell);

        Node<Tp>** split() ;


        template<typename T>
        friend std::ostream& operator<<(std::ostream& os, Node<T>& sq){
            os << "[  ";
            for(Cell<T>* i = sq.first; i != nullptr; i = i->nextCell ){ os << i->value << ","; }
            os << "\b  ]";
         return os;
        }
        
};

template<typename Tp>
void Node<Tp>::insert(Cell<Tp>* newCell)
{
    this->sizes++;
    //Cell<Tp>* newCell  =  new Cell<Tp>(val);

    if( this->isEmpty() ){ 
        this->first = newCell; 
        this->last  =  this->first;
     return; 
    }

    if( newCell->value > this->last->value ){
        this->last->nextCell  =  newCell;
        this->last  =  newCell;

     return;
    }

    Cell<Tp>* currentCell  =  this->first;
    Cell<Tp>* next  =  this->first;

    while ( next->value < newCell->value && next!=this->last){
        currentCell  =  next;
        next  =  next->nextCell;
    }

    currentCell->nextCell  =  newCell;
    newCell->nextCell  =  next;
}







