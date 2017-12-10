#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    //printf("Hello world!\n");
    ListaD *listt = (ListaD*)malloc(sizeof(ListaD));
    listt->primero = NULL;
    listt->ultimo = NULL;
    int num;
    int dat;
    do{
        menu();
        scanf("%d",&num);
        switch(num){
        case 1:
            printf("ingrese dato: ");
            scanf("%d",&dat);
            insertar(listt,dat);
            break;
        case 2:
            mostrar(listt);
            break;
        case 3:
            printf("ingrese dato a eliminar: ");
            scanf("%d",&dat);
            eliminar(listt,dat);
            break;
        }
    }while(num != 4);

    return 0;
}

void menu(){
    printf("\n\n **   MENU  **\n");
    printf("    1. Insertar\n");
    printf("    2. Mostrar\n");
    printf("    3. Eliminar\n");
    printf("    4. Salir\n");
    printf(" Seleccionar Opcion: ");
}

void insertar(ListaD *lista, int d){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->siguiente = NULL;
    if(lista->primero == NULL){
        lista->primero = nuevo;
        lista->ultimo = lista->primero;
    }
    else{
        lista->ultimo->siguiente = nuevo;
        nuevo->anterior = lista->ultimo;
        lista->ultimo = nuevo;
    }
}

void mostrar(ListaD *lista){
   Nodo *actual = lista->primero;
   if(actual == NULL){
    printf("Lista Vacia");
   }
   else{
    while(actual != NULL){
        printf("valor: %d", actual->dato);
        printf("\n");
        actual = actual->siguiente;
    }
   }
}

void eliminar(ListaD *lista, int d){
    Nodo *actual = lista->primero;
    Nodo *ant = NULL;
    while(actual->siguiente != NULL){
        if(actual->dato == d){
            if(ant == NULL){
                if(actual->siguiente == lista->primero){
                    lista->primero = NULL;
                    lista->ultimo = NULL;
                }
                else{
                    ant = actual->anterior;
                    ant->siguiente = actual->siguiente;
                    actual = actual->siguiente;
                    actual->anterior = ant;
                    lista->primero = actual;
                    ant = NULL;
                }
            }
            else{
                actual->anterior = NULL;
                ant->siguiente = actual->siguiente;
                actual = actual->siguiente;
                actual->anterior = ant;
            }
        }
        else{
            ant = actual;
            actual = actual->siguiente;
        }
    }
}
