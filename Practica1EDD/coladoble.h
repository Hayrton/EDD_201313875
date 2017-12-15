#ifndef COLADOBLE_H
#define COLADOBLE_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


typedef struct NodoColaD NodoColaD;
typedef struct ColaDoble ColaDoble;
typedef struct Avion Avion;
typedef Avion *av;

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
    int pasajeros;
    int mantenimiento;
    Avion *avio;
public:
    void addCola(Avion *avion);
    void mostrarCola();
    int descolar(ColaDoble *cola);
    int getSiguiente();
    int getAnterior();
    int getCurrent();
    av obtenerAvion(ColaDoble *cola);
    std::string contenidoNodos();
};


struct Avion{
    int tam;
    int nombre;
    int pasajeros;
    int desbordajes;
    int mantenimiento;
    Avion(int tam, int nombre, int pasajeros, int desbordajes, int mantenimiento){
        this->tam = tam;
        this->nombre = nombre;
        this->pasajeros = pasajeros;
        this->desbordajes = desbordajes;
        this->mantenimiento = mantenimiento;
    }
    std::string getAvion();
};

#endif // COLADOBLE_H
