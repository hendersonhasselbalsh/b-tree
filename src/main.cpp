#include <iostream>
#include "TreeNode/SortedQueue.h"
#include "Tree/Btree.h"
#include "TreePrinter/BTreePrinter.h"


int main(int argc, const char** argv)
{
    
    Node<int> root  =  Node<int>();
    root.insert(7); root.insert(20); root.insert(30);
    root.isleaf = false;

    Node<int> n1  =  Node<int>();
    n1.insert(4); n1.insert(5); 

    Node<int> n2  =  Node<int>();
    n2.insert(11); n2.insert(15); 

    Node<int> n3  =  Node<int>();
    n3.insert(23); n3.insert(26); 
    //n3.isleaf  =  false;

    Node<int> n4  =  Node<int>();
    n4.insert(32); 
    n4.isleaf = false;

    Node<int> n5  =  Node<int>{};
    n5.insert(31);

    Node<int> n6  =  Node<int>{};
    n6.insert(40);

    //----------------------------------

    root[0]->lowerNode  =  &n1;

    root[1]->lowerNode  =  &n2; 

    root[2]->lowerNode  =  &n3;
    root[2]->higherNode =  &n4;

    n4[0]->lowerNode  =  &n5;
    n4[0]->higherNode  =  &n6;
    //------------------------------------------

    
    BTree<int> t  =  BTree<int>{};
    t.root  =  &root;

    BTreePrinter printer  =  BTreePrinter();

    printer.print( t );
    



    std::cout << "\n\n\n[SUCESSO - !----!]\n";
}