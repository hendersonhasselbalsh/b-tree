#include <iostream>
#include <cstdlib>
#include <cmath>
#include "TreeNode/SortedQueue.h"
#include "Tree/Btree.h"
#include "TreePrinter/BTreePrinter.h"


int main(int argc, const char** argv)
{

    BTree<int> t{};
    BTreePrinter printer{};


    for( int i = 0; i < 30; i++ ){

        int toBeInsertedNumber  =  std::abs( std::rand() % 10000 );
        std::cout << "#### inserting " << toBeInsertedNumber << "\n\n";

        t.insert( toBeInsertedNumber );
        printer.print( t );
        std::cout << "\n-----------------------------------\n\n";

    }


    

    std::cout << "\n\n\n[SUCESSO - !-- ^^ --!]\n";

    
}