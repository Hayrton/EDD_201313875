#include <cola.h>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>


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
    QString cadena = "";
    QFile fichero("C:\\Users\\Hayrton\\Documents\\EDD\\VACD2017\\Practica1EDD\\graficaCola.dot");
    fichero.open(QIODevice::ReadWrite);
    QTextStream out(&fichero);
    cadena = "digraph grafica{\n";
    //cadena += contenidoCola(c);
    qInfo()<<contenidoCola(c);
    cadena += "}";
    out<<cadena;
    fichero.close();
    system("dot -Tpng C:\\Users\\Hayrton\\Documents\\EDD\\VACD2017\\Practica1EDD\\graficaCola.dot -o C:\\Users\\Hayrton\\Documents\\EDD\\VACD2017\\Practica1EDD\\cola.png");
}

QString cola::contenidoCola(cola *c){
    QString aux1 = "";
    QString aux2 = "";
    NodoCola *tmp = c->primero;
    while (tmp != NULL) {
        aux1 = QString::number(tmp->dato);
        aux2 = QString::number(tmp->siguiente->dato);
        cad += aux1 + " -> " + aux2 + "\n";
        tmp = tmp->siguiente;
    }
    return cad;
}
