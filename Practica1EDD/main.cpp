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
    Avion *av = new Avion(888,33,2,2);
    Avion *v = new Avion(333,23,3,1);
    cl->addCola(cl,av);
    cl->addCola(cl,v);
    cl->mostrarCola(cl);

    delete(av);
    delete(cl);

    return a.exec();
}
