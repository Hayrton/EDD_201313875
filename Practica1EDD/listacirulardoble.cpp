#include <listacirculardoble.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

NodoLDC::NodoLDC(Equipaje *maleta){
    this->maleta = maleta;
    this->siguiente = NULL;
    this->anterior =  NULL;
}

void ListaDC::addListaDC(ListaDC *list, Equipaje *m){
    NodoLDC *nuevo = new NodoLDC(m);
    if(list->primero == NULL){
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        list->primero = nuevo;
    }
    else{
        list->ultimo = list->primero->anterior;
        nuevo->siguiente = list->primero;
        nuevo->anterior = list->ultimo;
        list->primero->anterior = nuevo;
        list->primero->siguiente = nuevo;
    }
}

void ListaDC::eliminar(Equipaje *m){
    NodoLDC *aux = primero;
    if(aux == NULL){
        cout<<"Lista de equipaje vacia"<<endl;
    }
    else{

    }
}
