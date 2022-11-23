#pragma once

#include <iostream>
#include "../TreeNode/SortedQueue.h"
//#include "../TreePrinter/BTreePrinter.h"


/**
 * @brief essa classse foi pensada para que possa armazenar dados do tipo Tp,
 * onde Tp é do tipo classe, em uma arvore 234. 
 * Ao instanciar essa classe por exemplo BTree<Person> t{}; onde Person seja 
 * uma classe implementada pelo usuario. Seria ideal ter um membro ID privado 
 * que sera usado como criterio de comparação entre os objetos instanciados de 
 * Person. A lem disso é ideal que se sobrecarregue todos os operadores binario 
 * principalmente os operadores >, <, e ==. Em ipotese alguma sobrecarregue o operador =
 * a menos que se saiba exatamente o que esteja fazendo. 
 * 
 */
template<typename Tp>
class BTree {

    public: // <- private para facilitar o debug 
        Node<Tp>* root  =  nullptr;
        int nodes  =  0;

        Cell<Tp>* insert( Tp val, Node<Tp>* node, bool* shouldInsert);


    public:

        BTree(){ this->root  =  new Node<Tp>{}; }

        bool isEmty(){  return bool(this->root == nullptr);  }
        void insert( Tp element){  
            bool shouldInser = true;
            this->insert( element, this->root, &shouldInser );  
        }


        /**
         * @brief this function provide the a hability to find a object of 
         * a class type Tp, so you can modify some public atributes. For exemple:
         * you have a class Person
         * 
         *     class Person{ 
         *       private:
         *          unsigned ID;
         *       public:
         *          Person(unsigned id): ID(id){}; // constructor
         *          String name;
         *          char age; 
         *          ... other atributes or methods ...
         *      }; 
         * 
         *     BTree<Person> t{};
         * 
         *     ... some insertions ...
         * 
         * then, at this point, by some reason, you need to change the name of the person 123
         * To do this you can can use the function get()
         * 
         *       *t.get( Person{123} ).name  =  "new name";    // * is needed because this function returns a pointer
         * 
         * again, the class Person must have some overloaded operators, xpecialy > < and ==, 
         * but dont overload the = operator. 
         * When you are using this function and get a segmentation default error, probably you are 
         * trying to get a person that arent in this tree.
         * 
         * @param toBeFindedObj 
         * @return Tp* 
         */
        Tp* get(Tp toBeFindedObj);
        
};



#define HEADER_FILE_ALREADY_INCLIDED
#include "Btree.cpp"