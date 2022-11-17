
template<typename T>
struct Cell {
    T value;
    Cell* nextCell  =  nullptr;
    Node<T>* higherNode  =  nullptr;
    Node<T>* lowerNode  =  nullptr;

    Cell(T val) : value(val){}
};