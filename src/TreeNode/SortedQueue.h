#pragma once

#include <iostream>

template<typename Tp>  class Node;


template<typename T>
struct Cell {
    T value;
    Cell* nextCell  =  nullptr;
    Node<T>* higherNode  =  nullptr;
    Node<T>* lowerNode  =  nullptr;
    bool hasNextCell  =  false;

    Cell(){}
    Cell(T val) : value(val){}
};





template<typename Tp>
class Node {

    public:

        unsigned sizes = 0;
        bool isleaf  =  true;
        Cell<Tp>* first  =  nullptr;
        Cell<Tp>* last  =  nullptr;
        unsigned nodeLenght  =  0;
        

    public:
        Node(){}
        Node(unsigned _nodeLength) : nodeLenght(_nodeLength) {}

        template<typename T>
        friend std::ostream& operator<<(std::ostream& os, Node<T>& sq);

        Cell<Tp>* operator[](int i);
        
        int size(){ return this->sizes; }
        bool isLeaf(){ return this->isleaf; }
        bool isEmpty(){ return bool(this->first == nullptr); }

        void insert(Tp val){ this->insert( new Cell<Tp>(val) ); }
        void insert(Cell<Tp>* newCell);

        Node<Tp>** split(Cell<Tp>** risedCell); // 

        Tp* keys();
        Node<Tp>** C();

};



#define HEADER_FILE_ALREADY_INCLIDED
#include "SortedQueue.cpp"