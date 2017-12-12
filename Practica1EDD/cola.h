#ifndef COLA_H
#define COLA_H
#include <iostream>

using namespace std;

typedef struct NodoCola NodoCola;
typedef struct Cola Cola;

struct NodoCola{
    int dato;
    NodoCola *siguiente;
    NodoCola(int dato);
};

struct cola{
  NodoCola *primero;
  NodoCola *ultimo;
 public:
    string cad;
    void agregar(cola *c, int dat);
    int desc(cola *c);
    void recorrerCola(cola *c);
    void graficarCola(cola *c);
    string contenidoCola(cola *c);
};


#endif // COLA_H
