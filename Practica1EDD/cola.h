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
    void agregar(Pasajeros *pas);
    int descolar();
    void recorrerCola();
    void graficarCola();
    string contenidoCola();
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
