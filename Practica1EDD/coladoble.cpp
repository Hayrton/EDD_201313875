#include <coladoble.h>

NodoColaD::NodoColaD(Avion *avion){
    this->anterior = NULL;
    this->siguiente = NULL;
    this->avion = avion;
}
void ColaDoble::addCola(ColaDoble *cola, Avion *avion){
    NodoColaD *nuevo = new NodoColaD(avion);
    if(ultimo == NULL)
        cola->primero = cola->ultimo = cola->current = nuevo;
    cola->ultimo->siguiente = nuevo;
    nuevo->anterior = cola->ultimo;
    cola->ultimo = nuevo;
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
    if(aux == NULL){
        std::cout<<"Lista Vacia"<<std::endl;
    }else{
        while(aux != NULL){
            std::cout<<"dato: "<<aux->dato<<std::endl;
            aux = aux->siguiente;
        }
    }
}


