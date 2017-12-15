#ifndef COLA_H
#define COLA_H
#include <iostream>

using namespace std;

typedef struct NodoCola NodoCola;
typedef struct Cola Cola;
typedef struct Pasajeros Pasajeros;

struct NodoCola{
    int dato;
    Pasajeros *pasajero;
    NodoCola *siguiente;
    NodoCola(Pasajeros *pas);
};

struct cola{
  NodoCola *primero;
  NodoCola *ultimo;
 public:
    string cad;
    void agregar(cola *c, Pasajeros *pas);
    int desc(cola *c);
    void recorrerCola(cola *c);
    void graficarCola(cola *c);
    string contenidoCola(cola *c);
};

struct Pasajeros{
    int NombrePasajero;
    int NoMaletas;
    int NoDocumentos;
    int NoRegistros;
    Pasajeros(int name, int maleta, int documento, int registro);
    std::string getPasajero();

};




#endif // COLA_H
