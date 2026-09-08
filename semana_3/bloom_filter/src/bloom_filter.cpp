#include "bloom_filter.h"

// ====================================================================
//  FUNCIONES HASH
//  Idea simple: sumar los valores ASCII de los caracteres del string 
//  y aplicar modulo con distintos numeros primos.
// ====================================================================

// hash1: suma directa de los codigos ASCII, modulo de un primo
int hash1(string item) {
    int suma = 0;
    for (int i = 0; i < (int)item.size(); i++) {
        suma = suma + (int)item[i];
    }
    return suma % 101;
}

// hash2: suma de los codigos ASCII ponderados por la posicion, modulo de otro primo distinto
int hash2(string item) {
    int suma = 0;
    for (int i = 0; i < (int)item.size(); i++) {
        suma = suma + (int)item[i] * (i + 1);
    }
    return suma % 103;
}

// initialize: guarda m y k, crea el arreglo B de tamaño m y pone todos sus bits en 0
void BloomFilter::initialize(int m, int k) {
    this->m = m;
    this->k = k;

    B.resize(m);                 // Crear un array de bits 'B' de tamaño m

    for (int i = 0; i < m; i++) {
        B[i] = 0;
    }
}

// insert: marca en 1 las k posiciones de B que le corresponden al item
void BloomFilter::insert(string item) {
    for (int i = 1; i <= k; i++) {
        int pos = (hash1(item) + i * hash2(item)) % m;
        B[pos] = 1;
    }
}

// lookup: revisa las k posiciones del item; si alguna esta en 0 devuelve false, si todas estan en 1 devuelve true
bool BloomFilter::lookup(string item) {
    for (int i = 1; i <= k; i++) {
        int pos = (hash1(item) + i * hash2(item)) % m;
        if (B[pos] == 0) {
            return false;
        }
    }
    return true;
}
