#ifndef DATOS_H
#define DATOS_H
#include <coladoble.h>
#include <cola.h>

typedef struct Datos Datos;

struct Datos{
public:
    int NoAviones;
    int NoPasajero;
    int NoDesabordaje;
    int NoMatenimiento;
    int NamePasajero;

    Datos();
    Avion *av;
    ColaDoble *colaAvion;
    cola *colaPasajero;
    Pasajeros *pasaje;
    int generarDatos(int LINF, int LSUP);
    void DesabordajePasajero(int NoPasajeros);
    void graficar();
};

#endif // DATOS_H
