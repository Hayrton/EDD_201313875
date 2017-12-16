#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct ListaDC ListaDC;
typedef struct NodoLDC NodoLDC;
typedef struct Equipaje Equipaje;

struct NodoLDC{
    Equipaje *maleta;
    NodoLDC *siguiente;
    NodoLDC *anterior;
    NodoLDC(Equipaje *maleta);
};

struct ListaDC{
    NodoLDC *primero;
    NodoLDC *ultimo;
    void addListaDC(Equipaje *m);
    void mostrar();
    void eliminar(Equipaje *m);
};

struct Equipaje{
    int NombreEquipaje;
    int Nopasajero;
    Equipaje(int nombre, int pasajero);
    string getEquipaje();
};


#endif // LISTACIRCULARDOBLE_H
