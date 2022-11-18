#include <iostream>
#include "TreeNode/SortedQueue.h"


int main(int argc, const char** argv)
{
    
    Node<int> sq  =  Node<int>();

    
    sq.insert(1);
    sq.insert(2);
    sq.insert(3);
    sq.insert(9);

    Cell<int>* rised  =  new Cell<int>{}; 

    Node<int>** arr  =  sq.split( &rised );


    std::cout << "[rised]: " << rised->value << "\n\n";
    std::cout << "[0]: " << arr[0][0] << "\n\n";
    std::cout << "[1]: " << arr[1][0] << "\n\n";

    std::cout << "TESTE HIGHT : " << rised->higherNode[0] << "\n";
    std::cout << "TESTE LOW : " << rised->lowerNode[0] << "\n";

    std::cout << "\n[SUCESSO works !-----! ]\n";

    /*
    Node<int>** t  =  new Node<int>* [2];
    t[0]  =  new Node<int>{};
    t[1]  =  new Node<int>{};


    t[0]->insert(1);
    t[0]->insert(2);
    t[0]->insert(3);
    t[0]->insert(4);

    t[1]->insert(5);
    t[1]->insert(6);
    t[1]->insert(7);
    t[1]->insert(8);

    std::cout << t[0][0] << "\n\n";
    std::cout << t[1][0] << "\n\n";


    std::cout << "\n[SUCESSO !!-!! ]\n";
    */

}