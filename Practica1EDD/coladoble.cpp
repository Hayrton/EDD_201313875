#include <coladoble.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

NodoColaD::NodoColaD(Avion *avion){
    this->anterior = NULL;
    this->siguiente = NULL;
    this->avion = avion;
}
void ColaDoble::addCola(Avion *avion){
    NodoColaD *nuevo = new NodoColaD(avion);
    if(ultimo == NULL){
        primero = nuevo;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    }
}

void ColaDoble::descolar(){
    int dat;
    NodoColaD *aux = primero;
    if(primero == NULL){
        cout<<"Lista Vacia"<<endl;
    }else{
        dat = aux->avion->pasajeros;
        primero = primero->siguiente;
        delete(aux);
    }
    delete(aux);
}

void ColaDoble::mostrarCola(){
    NodoColaD *aux = primero;
    while(aux != NULL){
        cout << aux->avion->getAvion()<<endl;
        aux = aux->siguiente;
    }
}

av ColaDoble::obtenerAvion(){
    Avion *avi;
    NodoColaD *aux = primero;
    if(primero == NULL){
        cout<<"cola de avion vacia"<<endl;
        return NULL;
    }
    else{
        avi = aux->avion;
        primero = primero->siguiente;
        delete(avi);
    }
    return avi;
}

int ColaDoble::mostrarPrimero(){
    if(primero == NULL)
        cout<<"Lista de Aviones vacia"<<endl;
    return primero->avion->desbordajes;
}

int ColaDoble::No_Pesonas(){
    if(primero == NULL){
        cout << "Lista de aviones vacia"<<endl;
    }
    return primero->avion->pasajeros;
}

std::string Avion::getAvion(){
    string av ="Tamanio: "+ to_string(tam) + " Nombre: " + to_string(nombre) + " No. Pasajeros: " + to_string(pasajeros);
    av += " No. Desabordaje: "+to_string(desbordajes) + " No. Mantenimiento: "+ to_string(mantenimiento);
    return av;
}

std::string ColaDoble::contenidoNodos(){
    NodoColaD *tmp1 = primero;
    string cadena = "";
    if(tmp1 == NULL){
        return NULL;
    }
    else{
        while(tmp1->siguiente !=NULL){
            string contmp1 = to_string(tmp1->avion->nombre)+"[label=\""+ tmp1->avion->getAvion()+"\"]";
            string contmp2 = to_string(tmp1->siguiente->avion->nombre)+"[label=\""+ tmp1->siguiente->avion->getAvion()+"\"]";
            string nodAp = to_string(tmp1->avion->nombre) + " -> " + to_string(tmp1->siguiente->avion->nombre);
            if(tmp1->anterior != NULL){
                string conant1 = to_string(tmp1->avion->nombre)+"[label=\""+ tmp1->avion->getAvion()+"\"]";
                string conant2 = to_string(tmp1->anterior->avion->nombre)+"[label=\""+ tmp1->anterior->avion->getAvion()+"\"]";
                string nodAnt = to_string(tmp1->avion->nombre) + " -> " + to_string(tmp1->anterior->avion->nombre);
                cadena += conant1 + "\n";
                cadena += conant2 + "\n";
                cadena += nodAnt + "\n";
            }
            cadena += contmp1 + "\n";
            cadena += contmp2 + "\n";
            cadena += nodAp + "\n";
            tmp1 = tmp1->siguiente;
        }
    }
    return cadena;
}


