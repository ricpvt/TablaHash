#include <iostream>
#include "TablaHash.h"

int main() {
    // Create a hash table with an initial capacity of 10
    int initialCapacity = 10;
    TablaHash tabla(initialCapacity);

    // Example of inserting elements
    Element elemento1 = {"Alice", 1};
    Element elemento2 = {"Bob", 2};
    Element elemento3 = {"Charlie", 3};

    tabla.InsertarElemento(elemento1);
    tabla.InsertarElemento(elemento2);
    tabla.InsertarElemento(elemento3);

    // Print the table
    tabla.ImprimirTabla();

    // Example of searching for an element
    std::cout << "Buscando elemento con ID 2: " << (tabla.Buscar(2) ? "Encontrado" : "No encontrado") << std::endl;

    // Example of deleting an element
    tabla.EliminarElemento(2);

    // Print the table after deletion
    tabla.ImprimirTabla();

    return 0;
}
