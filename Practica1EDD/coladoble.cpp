#include <coladoble.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

NodoColaD::NodoColaD(Avion *avion){
    this->anterior = NULL;
    this->siguiente = NULL;
    this->avion = avion;
}
void ColaDoble::addCola(ColaDoble *cola, Avion *avion){
    NodoColaD *nuevo = new NodoColaD(avion);
    if(ultimo == NULL){
        cola->primero = nuevo;
        cola->ultimo = cola->primero;
    }else{
        cola->ultimo->siguiente = nuevo;
        nuevo->anterior = cola->ultimo;
        cola->ultimo = nuevo;
    }
}

int ColaDoble::descolar(ColaDoble *cola){
    int dat;
    NodoColaD *aux = cola->primero;
    dat = aux->dato;
    cola->primero = cola->primero->siguiente;
    delete(aux);
    return dat;
}

void ColaDoble::mostrarCola(ColaDoble *cola){
    NodoColaD *aux = cola->primero;
    while(aux != NULL){
        cout << "Name: " << aux->avion->nombre<<endl;
        aux = aux->siguiente;
    }
}

std::string Avion::getAvion(Avion *a){
    string av = "Nombre: " + to_string(a->nombre) + " No. Pasajeros: " + to_string(a->pasajeros);
    av += " No. Desabordaje: "+to_string(a->desbordajes) + " No. Mantenimiento: "+ to_string(a->mantenimiento);
    return av;
}

