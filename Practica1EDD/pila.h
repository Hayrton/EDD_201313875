#ifndef PILA_H
#define PILA_H
#include <iostream>

typedef struct NodoPila NodoPila;
typedef struct Pila Pila;

struct NodoPila{
    int dato;
    NodoPila *siguiente;
    NodoPila(int dato);
};

struct Pila{
    NodoPila *primero;
    NodoPila *ultimo;
    void push(Pila *p, int dat);
    int pop(Pila *p);
    void recorrer(Pila *p);
};

#endif // PILA_H
