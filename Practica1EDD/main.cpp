#include "mainwindow.h"
#include <QApplication>
#include <coladoble.h>
#include <cola.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cola *cl = new cola();
    cl->agregar(cl,3);
    cl->agregar(cl,5);
    cl->agregar(cl,9);
    cl->agregar(cl,7);
    //cl->recorrerCola(cl);
    cl->graficarCola(cl);

    delete(cl);
    MainWindow w;
    w.show();

    return a.exec();
}
