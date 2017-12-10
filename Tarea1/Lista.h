#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Nodo Nodo;
typedef struct ListaD ListaD;

struct Nodo{
    Nodo *siguiente;
    Nodo *anterior;
    int dato;
};

typedef Nodo *NNodo;

struct ListaD{
    Nodo *primero;
    Nodo *ultimo;
};

void insertar(ListaD *lista, int d);
void mostrar(ListaD *lista);
void eliminar(ListaD *lista, int d);

#endif // LISTA_H_INCLUDED
