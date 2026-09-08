#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -------------------------------------------------------------
//  Dos funciones hash simples para cadenas.
//  Con estas dos simulamos las 'k' funciones hash del pseudocodigo
//  usando la formula:  pos = (hash1(item) + i * hash2(item)) % m
// -------------------------------------------------------------
int hash1(string item);
int hash2(string item);

// -------------------------------------------------------------
//  Estructura del Bloom Filter.
//    m -> tamaño del arreglo de bits
//    k -> cantidad de funciones hash
//    B -> arreglo de bits (0 o 1)
// -------------------------------------------------------------
struct BloomFilter {
    int m;            // tamaño del arreglo de bits
    int k;            // cantidad de funciones hash
    vector<int> B;    // arreglo de bits

    void initialize(int m, int k);
    void insert(string item);
    bool lookup(string item);
};

#endif
