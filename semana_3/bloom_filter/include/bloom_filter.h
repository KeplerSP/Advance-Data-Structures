#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//  Las k = 3 funciones hash. Todas suman codigos ASCII,
// pero con distinta ponderacion y distinto primo.
int hash1(string item);
int hash2(string item);
int hash3(string item);

// hi: aplica las 'k' funciones hash (i va de 1 a k)
int hi(string item, int i, int m);

struct BloomFilter {
    int m;          // tamaño del arreglo de bits
    int k;          // cantidad de funciones hash
    vector<int> B;  // arreglo de bits

    void initialize(int m, int k);
    void insert(string item);
    bool lookup(string item);
};

#endif
