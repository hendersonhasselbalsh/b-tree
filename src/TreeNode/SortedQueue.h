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

    bool hasChildren(){ return bool(lowerNode!=nullptr); }
};



/*
  node = {  a   ->    b   ->    c  }
          /          /         / \
         n1         n2        n3  n4              
*/

template<typename Tp>
class Node {

    public:

        //unsigned sizes = 0;
        Cell<Tp>* first  =  nullptr;
        Cell<Tp>* last  =  nullptr;
        unsigned nodeLenght  =  0;
        

    public:
        Node(){}
        Node(unsigned _nodeLength) : nodeLenght(_nodeLength) {}

        template<typename T>
        friend std::ostream& operator<<(std::ostream& os, Node<T>& sq);

        Cell<Tp>* operator[](int i);
        
        int size();
        bool isLeaf();
        bool isEmpty(){ return bool(this->first == nullptr); }
        bool isFull(){ return this->size() > 3; }
        void checkNodeIsLeaf();

        void insert(Tp val){ this->insert( new Cell<Tp>(val) ); }
        void insert(Cell<Tp>* newCell, Cell<Tp>** risedCell = nullptr);

        Node<Tp>** split(Cell<Tp>** risedCell); // 

        Tp* keys();
        Node<Tp>** C();

};



#define HEADER_FILE_ALREADY_INCLIDED
#include "SortedQueue.cpp"