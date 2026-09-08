#include "bloom_filter.h"

int main() {

    // Definimos m y k con valores fijos
    int m = 20;   // tamano del arreglo de bits
    int k = 3;    // cantidad de funciones hash

    // Creamos el Bloom Filter en el Stack
    BloomFilter bloom;
    bloom.initialize(m, k);   // Initialize(m, k)

    // Insertamos algunas palabras de ejemplo
    bloom.insert("gato");
    bloom.insert("perro");
    bloom.insert("pez");

    // Busqueda de una palabra que SI fue insertada (se espera true)
    string item = "gato";
    if (bloom.lookup(item))
        cout << item << " -> true  (probablemente esta)" << endl;
    else
        cout << item << " -> false (seguro NO esta)" << endl;

    // Busqueda de una palabra que NO fue insertada (se espera false)
    item = "elefante";
    if (bloom.lookup(item))
        cout << item << " -> true  (probablemente esta)" << endl;
    else
        cout << item << " -> false (seguro NO esta)" << endl;

    return 0;
}
