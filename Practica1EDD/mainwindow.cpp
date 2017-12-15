#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <coladoble.h>
#include <cola.h>
#include <listacirculardoble.h>
#include <datos.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
    int noAviones = ui->txtNoAvion->text().toInt();
    std::cout<<noAviones<<std::endl;
    agregarAviones(noAviones);
    colaAvion->mostrarCola();
    delete(colaAvion);
    msgBox.setText("aviones agregados");
    msgBox.exec();
}

void MainWindow::agregarAviones(int noAvion){
    int contador=0;
    std::cout<<noAvion<<std::endl;
    Avion *avio;
    std::cout<<contador<<std::endl;
    while(contador<noAvion){
        std::cout<<contador<<std::endl;
        int num = datoRandom(1,3);
        switch (num) {
        case 1:
            std::cout<<"hola :C"<<std::endl;
            pasajeros = datoRandom(5,10);
            mantenimiento = datoRandom(1,3);
            avio = new Avion(num,*(int*)(void*)&avio,pasajeros,1,mantenimiento);
            colaAvion->addCola(avio);
            contador++;
            break;
        case 2:
            pasajeros = datoRandom(15,25);
            mantenimiento = datoRandom(2,4);
            avio = new Avion(num,*(int*)(void*)&avio,pasajeros,2,mantenimiento);
            colaAvion->addCola(avio);
            contador++;
            break;
        case 3:
            pasajeros = datoRandom(30,40);
            mantenimiento = datoRandom(3,6);
            avio = new Avion(num, *(int*)(void*)&avio,pasajeros,3,mantenimiento);
            colaAvion->addCola(avio);
            contador++;
            break;
        }
    }
}

int MainWindow::datoRandom(int LINF, int LSUP){
    int num;
    //srand(time(NULL));
    num = LINF+(rand()%((LSUP+1)-LINF));
    //cout << num <<endl;
    return num;
}


