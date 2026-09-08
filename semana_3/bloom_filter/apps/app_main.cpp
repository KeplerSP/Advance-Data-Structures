#include "bloom_filter.h"

int main() {

    // Definimos m y k con valores fijos
    int m = 10;   // tamaño del arreglo de bits
    int k = 3;    // cantidad de funciones hash

    // Creamos el Bloom Filter
    BloomFilter bloom;
    bloom.initialize(m, k);

    // Insertamos algunas palabras de ejemplo
    bloom.insert("gato");
    bloom.insert("perro");
    bloom.insert("pez");

    // Lookup de una palabra que SI fue insertada -> se espera true
    string item = "gato";
    if (bloom.lookup(item))
        cout << item << " -> true  (probablemente esta)" << endl;
    else
        cout << item << " -> false (seguro NO esta)" << endl;

    // Lookup de una palabra que NO fue insertada -> se espera false
    item = "casa";
    if (bloom.lookup(item))
        cout << item << " -> true  (probablemente esta)" << endl;
    else
        cout << item << " -> false (seguro NO esta)" << endl;

    // Lookup de otra palabra NO insertada que cae en bits ya marcados -> FALSO POSITIVO
    item = "sol";
    if (bloom.lookup(item))
        cout << item << " -> true  (FALSO POSITIVO: 'sol' no se inserto)" << endl;
    else
        cout << item << " -> false (seguro NO esta)" << endl;

    return 0;
}
