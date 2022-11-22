


#if !defined(HEADER_FILE_ALREADY_INCLIDED)
    #include "Btree.h"
#endif // HEADER_FILE_ALREADY_INCLIDED


unsigned layer = 0;  // for DEBUG

template<typename Tp>
Cell<Tp>* BTree<Tp>::insert( Tp val, Node<Tp>* node, bool* shouldInsert )
{
    layer++; // for DEBUG
    Cell<Tp>* risedCell  =  nullptr;
    unsigned nodeSizes  =  node->size();
    //bool shouldInsert;

    if( !node->isLeaf() ){
        
        // caso so tenha 1 elemento
        if( nodeSizes==1 &&  val < (*node)[0]->value ){
            risedCell = this->insert(val, (*node)[0]->lowerNode, shouldInsert );
        }
        else if( nodeSizes==1 && val > (*node)[0]->value ){
            risedCell = this->insert(val, (*node)[0]->higherNode, shouldInsert );
        }

        // caso tenha 2 elementos
        else if( nodeSizes==2 &&  val < (*node)[0]->value ){
            risedCell = this->insert(val, (*node)[0]->lowerNode, shouldInsert );
        }
        else if( nodeSizes==2 && val > (*node)[0]->value  &&   val < (*node)[1]->value  ){
            risedCell = this->insert(val, (*node)[1]->lowerNode, shouldInsert );
        }
        else if( nodeSizes==2 && val > (*node)[1]->value ){
            risedCell = this->insert(val, (*node)[1]->higherNode, shouldInsert );
        }

        //caso tenha odo os 3 elementos
        else if( nodeSizes==3 &&  val < (*node)[0]->value ){
            risedCell = this->insert(val, (*node)[0]->lowerNode, shouldInsert );
        }
        else if( nodeSizes==3 && val > (*node)[0]->value  &&   val < (*node)[1]->value  ){
            risedCell = this->insert(val, (*node)[1]->lowerNode, shouldInsert );
        }
        else if( nodeSizes==3 && val > (*node)[1]->value  &&   val < (*node)[2]->value  ){
            risedCell = this->insert(val, (*node)[2]->lowerNode, shouldInsert );
        }
        else if( nodeSizes==3 && val > (*node)[2]->value ){
            risedCell = this->insert(val, (*node)[2]->higherNode, shouldInsert );
        }
    }

    if( *shouldInsert && node->isLeaf() ) {  node->insert(val); *shouldInsert=false; }

    if( risedCell != nullptr ){  
        node->insert(risedCell); }

    Cell<Tp>* newRisedCell  =  nullptr;
    if( node == this->root  &&  node->isFull() ){
        newRisedCell  =  new Cell<Tp>{};
        node->split( &newRisedCell );
        delete node; node = nullptr;

        this->root  =  new Node<Tp>{};
        this->root->insert(newRisedCell);
        node = this->root;
    }

    if( node->isFull() ){
        newRisedCell  =  new Cell<Tp>{};
        node->split( &newRisedCell );
        delete node; node = nullptr;
    }

    layer--;
 return newRisedCell;
}










#define HEADER_FILE_ALREADY_INCLIDED
#include "TreeOperator.cpp"
