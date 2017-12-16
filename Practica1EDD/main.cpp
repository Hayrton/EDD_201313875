#include "mainwindow.h"
#include <QApplication>
#include <coladoble.h>
#include <cola.h>
#include <datos.h>
#include <pila.h>
#include <listacirculardoble.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
