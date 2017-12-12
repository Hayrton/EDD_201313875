#include "mainwindow.h"
#include <QApplication>
#include <coladoble.h>
#include <cola.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ColaDoble *cl = new ColaDoble();
    Avion *av = new Avion();

    av->nombre = 888;
    av->pasajeros = 5;
    av->desbordajes = 2;
    av->mantenimiento = 2;
    cl->addCola(cl,av);
    av->nombre = 333;
    av->pasajeros =5;
    av->desbordajes =2;
    av->mantenimiento =3;
    cl->addCola(cl,av);
    cl->mostrarCola(cl,av);

    delete(av);
    delete(cl);

    return a.exec();
}
