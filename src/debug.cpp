#include <iostream>
#include "TreeNode/SortedQueue.h"
#include "Tree/Btree.h"
#include "TreePrinter/BTreePrinter.h"


int main(int argc, const char** argv)
{

    BTree<int> t{};
    BTreePrinter printer{};





    t.insert(1); 
    t.insert(2); 
    t.insert(3); 
    std::cout << "\n\n-------------------------------\n\n";
    //printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";

    

    t.insert(4);    
    //printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";

        


    t.insert(5);    
    //printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";


        
    t.insert(6);    
    //printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";



    t.insert(7);    
    ////printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";



    t.insert(8);    
    //printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";



    t.insert(9);    
    printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";

    t.insert(11);    
    printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";


/*
    t.insert(11);    
    printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";



    t.insert(12);    
    printer.print( t );

    std::cout << "\n\n-------------------------------\n\n";

*/

    std::cout << "\n\n\n[SUCESSO - !-- ^^ --!]\n";

    
}