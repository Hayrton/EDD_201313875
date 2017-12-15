#include <datos.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;
Datos::Datos(){}

int Datos::generarDatos(int LINF, int LSUP){
    int num;
    //srand(time(NULL));
    num = LINF+(rand()%((LSUP+1)-LINF));
    //cout << num <<endl;
    return num;
}

void Datos::graficar(){
    string cadena = "";
    string cc = "";
    ofstream fichero("grafica.dot");
    if(fichero.fail()){
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    cadena = "digraph grafico{\n";
    //cadena += contenidoCola(c);
    cadena += "}";
    fichero<<cadena<<endl;
    fichero.close();
    system("dot -Tpng grafica.dot -o cola.png");
}

void Datos::DesabordajePasajero(int NoPasajeros){
    colaPasajero = new cola();
    int cont = 0;
    while(cont < NoPasajeros){
        int numMaletas = generarDatos(1,4);
        int numDocumento = generarDatos(1,10);
        int numRegistros = generarDatos(1,3);
        pasaje = new Pasajeros(NamePasajero,numMaletas,numDocumento,numRegistros);
        colaPasajero->agregar(colaPasajero,pasaje);
        cont++;
        NamePasajero++;
    }
    colaPasajero->recorrerCola(colaPasajero);
    colaPasajero->graficarCola(colaPasajero);
}
