#include <cola.h>
#include <fstream>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>

using namespace std;

NodoCola::NodoCola(int dato){
    this->dato = dato;
    this->siguiente = NULL;
}

void cola::agregar(cola *c, int dat){
    NodoCola *nuevo = new NodoCola(dat);
    if(c->primero == NULL)
        c->primero = c->ultimo = nuevo;
    c->ultimo->siguiente = nuevo;
    c->ultimo = nuevo;
}

int cola::desc(cola *c){
    int dat;
    NodoCola *aux = c->primero;
    dat = aux->dato;
    delete(aux);
    return dat;
}

void cola::recorrerCola(cola *c){
    NodoCola *actual = c->primero;
    while (actual != NULL) {
        std::cout<<"dato: "<<actual->dato<<std::endl;
        actual = actual->siguiente;
    }
}

void cola::graficarCola(cola *c){
    string cadena = "";
    string cc = "";
    ofstream fichero("C:\\Users\\Hayrton\\Documents\\GitHub\\EDD_201313875\\Practica1EDD\\graficaCola.dot");
    if(fichero.fail()){
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
   cadena = "digraph grafico{\n";
   cadena += contenidoCola(c);
   cadena += "}";
   fichero<<cadena<<endl;
   fichero.close();

}

string cola::contenidoCola(cola *c){
    NodoCola *tmp = c->primero;
    string aux1 = "";
    string aux2 = "";
    while(tmp->siguiente != NULL){
        aux1 = to_string(tmp->dato);
        aux2 = to_string(tmp->siguiente->dato);
        cad += aux1 + " -> " + aux2 + "\n";
        tmp = tmp->siguiente;
    }
    cout<< cad << endl;
    return cad;
}


