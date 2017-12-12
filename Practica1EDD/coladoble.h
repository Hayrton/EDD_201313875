#ifndef COLADOBLE_H
#define COLADOBLE_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

typedef struct NodoColaD NodoColaD;
typedef struct ColaDoble ColaDoble;
typedef struct Avion Avion;

struct NodoColaD{
    int dato;
    Avion *avion;
    NodoColaD *siguiente;
    NodoColaD *anterior;
    NodoColaD(Avion *avion);
};

struct ColaDoble{
    NodoColaD *primero;
    NodoColaD *ultimo;
    NodoColaD *current;
public:
    void addCola(ColaDoble *cola, Avion *avion);
    void mostrarCola(ColaDoble *cola);
    int descolar(ColaDoble *cola);
    int getSiguiente();
    int getAnterior();
    int getCurrent();
};

struct Avion{
    int nombre;
    int pasajeros;
    int desbordajes;
    int mantenimiento;
    Avion(int nombre, int pasajeros, int desbordajes, int mantenimiento){
        this->nombre = nombre;
        this->pasajeros = pasajeros;
        this->desbordajes = desbordajes;
        this->mantenimiento = mantenimiento;
    }
    std::string getAvion(Avion *a);
};

#endif // COLADOBLE_H
