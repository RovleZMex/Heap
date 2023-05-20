#include <iostream>
#include "Heap.h"

using namespace std;

template<typename T>
bool ordenamientoLongitud(const T&a, const T&b){
    return a.length() >= b.length();
}


int main() {
    // Crear un montículo de enteros con capacidad 10
    Heap<int> heap(10);

    // Insertar elementos en el montículo
    heap.InsertKey(5);
    heap.InsertKey(3);
    heap.InsertKey(8);
    heap.InsertKey(1);
    heap.InsertKey(9);

    // Extraer y mostrar los elementos del montículo
    cout << "Integer number heap:" << endl;
    while (heap.GetSize() > 0) {
        std::cout << heap.extractRoot() << " ";
    }
    std::cout << std::endl;

    return 0;
}
