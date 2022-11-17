#include <iostream>
#include "SortedQueue.h"


int main(int argc, const char** argv)
{
    Node<int> sq  =  Node<int>();

    
    sq.insert(1);
    sq.insert(2);
    sq.insert(3);
    sq.insert(9);
    
    std::cout << sq << "\n";
    sq.insert(5);
    std::cout << sq << "\n";

    std::cout << "\n[SUCESSO include ]\n";
}