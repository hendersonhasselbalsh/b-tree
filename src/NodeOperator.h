#pragma once

#if defined(node_class_h_not_included)
    #include "SortedQueue.h"
#endif // node_class_h

#include <iostream>


template<typename T>
friend std::ostream& operator<<(std::ostream& os, Node<T>& sq){
    os << "[  ";
    for(Cell<T>* i = sq.first; i != nullptr; i = i->nextCell ){ os << i->value << ","; }
    os << "\b  ]";
 return os;
}
