#include <cola.h>
#include <fstream>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>

using namespace std;

NodoCola::NodoCola(Pasajeros *pas){
    this->pasajero = pas;
    this->siguiente = NULL;
}

void cola::agregar(cola *c, Pasajeros *pas){
    NodoCola *nuevo = new NodoCola(pas);
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
        std::cout<<"dato: "<<actual->pasajero->getPasajero()<<std::endl;
        actual = actual->siguiente;
    }
}

void cola::graficarCola(cola *c){
    string cadena = "";
    string cc = "";
    ofstream fichero("graficaCola.dot");
    if(fichero.fail()){
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    cadena = "digraph grafico{\n";
    cadena += contenidoCola(c);
    cadena += "}";
    fichero<<cadena<<endl;
    fichero.close();
    system("dot -Tpng graficaCola.dot -o colaAvion.png");
}

string cola::contenidoCola(cola *c){
    NodoCola *tmp = c->primero;
    string aux1 = "";
    string aux2 = "";
    while(tmp->siguiente != NULL){
        aux1 = to_string(tmp->pasajero->NombrePasajero);
        aux2 = to_string(tmp->siguiente->pasajero->NombrePasajero);
        cad += aux1 + " -> " + aux2 + "\n";
        tmp = tmp->siguiente;
    }
    cout<< cad << endl;
    return cad;
}

Pasajeros::Pasajeros(int name, int maleta, int documento, int registro){
    this->NombrePasajero = name;
    this->NoMaletas = maleta;
    this->NoDocumentos = documento;
    this->NoRegistros = registro;
}

string Pasajeros::getPasajero(){
    string cad = "Nombre: " + to_string(NombrePasajero) + " Cant Maletas: "+ to_string(NoMaletas);
    cad += " Cant Documentos: " + to_string(NoDocumentos) + " Cant Registro: " + to_string(NoRegistros);
    return cad;
}

