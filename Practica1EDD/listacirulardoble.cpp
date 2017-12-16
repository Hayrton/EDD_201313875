#include <listacirculardoble.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

NodoLDC::NodoLDC(Equipaje *maleta){
    this->maleta = maleta;
    this->siguiente = NULL;
    this->anterior =  NULL;
}

void ListaDC::addListaDC(Equipaje *m){
    NodoLDC *nuevo = new NodoLDC(m);
    if(primero == NULL){
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        primero = nuevo;
    }
    else{
        ultimo = primero->anterior;
        nuevo->siguiente = primero;
        nuevo->anterior = ultimo;
        primero->anterior = nuevo;
        primero->siguiente = nuevo;
    }
}

void ListaDC::mostrar(){
    NodoLDC *tmp = primero;
    if(tmp == NULL){
        cout<<"Lista doble circular vacia";
    }
    else{
        do{
            cout<<tmp->maleta->getEquipaje()<<endl;
            tmp = tmp->siguiente;
        }while(tmp != primero);
    }
}

void ListaDC::eliminar(Equipaje *m){
    if(primero != NULL){
        NodoLDC *aux = primero;
        NodoLDC *ant = NULL;
        while(aux->siguiente != primero){
            if(aux->maleta == m){
                if(ant == NULL){
                    if(aux->siguiente == primero){
                        primero = NULL;
                    }else{
                        ant = aux->anterior;
                        ant->siguiente = aux->siguiente;
                        aux = aux->siguiente;
                        aux->anterior = ant;
                        primero = aux;
                        ant = NULL;
                    }
                }
                else{
                    aux->anterior = NULL;
                    ant->siguiente = aux->siguiente;
                    aux = aux->siguiente;
                    aux->anterior = ant;
                }
            }
            else{
                ant = aux;
                aux = aux->siguiente;
            }
        }
    }
    else{
        cout<<"lista doble circular vacia";
    }
}

Equipaje::Equipaje(int nombre, int pasajero){
    this->NombreEquipaje = nombre;
    this->Nopasajero = pasajero;
}

string Equipaje::getEquipaje(){
    return "Nombre: " + to_string(NombreEquipaje) + " Id Pasajero: "+  to_string(Nopasajero);
}
