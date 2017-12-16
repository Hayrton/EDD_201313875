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


