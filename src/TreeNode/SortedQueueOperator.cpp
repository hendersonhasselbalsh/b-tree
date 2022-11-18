#pragma once   

#if !defined(HEADER_FILE_ALREADY_INCLIDED)
    #include "SortedQueue.h"
#endif // HEADER_FILE_ALREADY_INCLIDED


    
template<typename T>
std::ostream& operator<<(std::ostream& os, Node<T>& sq){
    os << "[  ";
    for(Cell<T>* i = sq.first; i != nullptr; i = i->nextCell ){ os << i->value << ","; }
    os << "\b  ]";
return os;
}



