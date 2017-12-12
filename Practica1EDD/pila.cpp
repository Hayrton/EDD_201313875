#include <pila.h>
#include <iostream>

NodoPila::NodoPila(int dato){
    this->dato = dato;
    this->siguiente = NULL;
}

void Pila::push(Pila *p, int dat){
    NodoPila *nuevo = new NodoPila(dat);
    if(p->primero == NULL)
        p->primero = p->ultimo = nuevo;
    p->primero->siguiente = nuevo;
    p->primero = nuevo;
}

int Pila::pop(Pila *p){
    int num;
    if(p->primero != NULL){
        NodoPila *tmp = p->primero;
        num = tmp->dato;
        p->primero = p->primero->siguiente;
        delete tmp;
    }
    return num;
}

void Pila::recorrer(Pila *p){
    NodoPila *tmp = p->primero;
    while (tmp != NULL) {
        std::cout<<tmp->dato<<" ";
        tmp = tmp->siguiente;
    }
}
