#ifndef EJERCICIO_4_H
#define EJERCICIO_4_H

#include <iostream>
using namespace std;

struct Student {
    string codigo;
    string nombres;
    float promedio;
};


// Nodo con constructor usando "{}"
struct Nodo {
    int dato;
    Nodo* sig;

    Nodo(int v) {
        dato = v;
        sig = nullptr;
    }
};

// Lista enlazada simple
struct Lista {
    Nodo* cabeza;
    int tam;   // contador de elementos

    // Constructor
    Lista() {
        cabeza = nullptr;
        tam = 0;
    }

    // ---- Declaraciones que usas en el .cpp ----
    void insertarInicio(int valor);
    int retirarDeInicio();
    void insertarFinal(int valor);
    void eliminar(int valor);
    Nodo* buscar(int valor);
    void imprimir();
    void liberar();

    int tamano();  // <- usado en tu .cpp

    // Nuevos que agregaste en el .cpp
    void AdicionaAPosicion(int dato, int posicion);
    int  RetiraDePosicion(int posicion);
    void AdicionarEnOrden(int dato);

    ~Lista() { liberar(); }
};

#endif
