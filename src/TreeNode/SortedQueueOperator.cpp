#pragma once   

#if !defined(HEADER_FILE_ALREADY_INCLIDED)
    #include "SortedQueue.h"
#endif // HEADER_FILE_ALREADY_INCLIDED


    
template<typename T>
std::ostream& operator<<(std::ostream& os, Node<T>& sq){
    if(sq.isEmpty()){  os << ""; return os;  }

    os << "[";
    for(Cell<T>* i = sq.first; i != nullptr; i = i->nextCell ){ os << i->value << " "; }
    os << "\b]";
 return os;
}


template<typename Tp>
Cell<Tp>* Node<Tp>::operator[](int i){

    if( this->isEmpty() ){  return nullptr;  }
    if( i > this->size() ){  
        std::cerr << "\n[warning - in node operator []]: index do not exist\n";  
        return nullptr;  
    }

    Cell<Tp>* currentCell  =  this->first;

    int a = 0;
    while(a < i  ){
        currentCell  =  currentCell->nextCell;
        a++;
    }

 return currentCell;
}




