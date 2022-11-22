#include <iostream>
#include "TreeNode/SortedQueue.h"
#include "Tree/Btree.h"
#include "TreePrinter/BTreePrinter.h"


int main(int argc, const char** argv)
{
    BTree<int> t{};
    BTreePrinter printer{};

    t.insert(0); 
    t.insert(50); 
    t.insert(100);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";



    t.insert(10);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";



    t.insert(2);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";


    t.insert(1);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";

    
    t.insert(3);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";
    

    t.insert(4);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";


    t.insert(5);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";


    t.insert(6);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";

    t.insert(8);
    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";










    std::cout << "\n\n\n[SUCESSO - erro]\n";
}