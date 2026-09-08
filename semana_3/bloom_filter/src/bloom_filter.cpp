#include "bloom_filter.h"

// ====================================================================
//  FUNCIONES HASH
//  Las 3 suman los codigos ASCII de la cadena, pero cada una usa una
//  ponderacion distinta y un primo distinto.
// ====================================================================

// hash1: suma simple de los codigos ASCII
int hash1(string item) {
    int suma = 0;
    for (int j = 0; j < (int)item.size(); j++) {
        suma = suma + (int)item[j];
    }
    return suma % 101;
}

// hash2: suma de los codigos ASCII ponderados por la posicion (pos+1)
int hash2(string item) {
    int suma = 0;
    for (int j = 0; j < (int)item.size(); j++) {
        suma = suma + (int)item[j] * (j + 1);
    }
    return suma % 103;
}

// hash3: suma de los codigos ASCII ponderados por la posicion al cuadrado
int hash3(string item) {
    int suma = 0;
    for (int j = 0; j < (int)item.size(); j++) {
        suma = suma + (int)item[j] * (j + 1) * (j + 1);
    }
    return suma % 107;
}

// hi: aplica la i-esima funcion hash al item (i va de 1 a k)
int hi(string item, int i, int m) {
    if (i == 1) return hash1(item) % m;
    if (i == 2) return hash2(item) % m;
    if (i == 3) return hash3(item) % m;
    return 0;
}

// initialize: guarda m y k, crea el arreglo B de tamaño m y pone todos sus bits en 0
void BloomFilter::initialize(int m, int k) {
    this->m = m;
    this->k = k;

    B.resize(m);  // Crear el array de bits de tamaño 'm'

    for (int i = 0; i < m; i++) {
        B[i] = 0;
    }
    // Las k funciones hash ya estan definidas arribas: hash1, hash2, hash3
}

// insert: marca en 1 las k posiciones del arreglo B que le corresponden al item
void BloomFilter::insert(string item) {
    for (int i = 1; i <= k; i++) {
        // obtenemos el valor de cada función hash
        int pos = hi(item, i, m);
        B[pos] = 1;
    }
}

// lookup: revisa las k posiciones del item; si alguna esta en 0 devuelve false, si todas estan en 1 devuelve true
bool BloomFilter::lookup(string item) {
    for (int i = 1; i <= k; i++) {
        int pos = hi(item, i, m);
        if (B[pos] == 0) {
            return false;
        }
    }
    return true;
}
