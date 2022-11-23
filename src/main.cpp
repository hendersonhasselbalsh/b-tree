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
    t.insert(10);
    t.insert(2);
    t.insert(1);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(8);

    printer.print( t );
    std::cout << "\n-------------------------------------------\n\n";



    *t.get(10000) = 90000;


    std::cout << "\n\n\n";
    printer.print( t );






    std::cout << "\n\n\n[SUCESSO - !--^^--!]\n";
}