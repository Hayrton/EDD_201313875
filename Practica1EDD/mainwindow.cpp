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
    if(ui->txtNoAvion->text() == ""){
        msgBox.setText("Ingres el numero de aviones");
    }
    int noAviones = ui->txtNoAvion->text().toInt();
    //std::cout<<noAviones<<std::endl;
    agregarAviones(noAviones);
    colaAvion->mostrarCola();
    delete(colaAvion);
    TurnoDesabordaje = colaAvion->mostrarPrimero();
    cout << "turnos " <<TurnoDesabordaje << endl;
    cont1 = colaAvion->No_Pesonas();
    cout << "pasajeros" << cont1 << endl;
    msgBox.setText("aviones agregados");
    msgBox.exec();
}

void MainWindow::agregarAviones(int noAvion){
    int contador=0;
    //std::cout<<noAvion<<std::endl;
    Avion *avio;
    //std::cout<<contador<<std::endl;
    while(contador<noAvion){
        //std::cout<<contador<<std::endl;
        int num = datoRandom(1,3);
        switch (num) {
        case 1:
            //std::cout<<"hola :C"<<std::endl;
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

void MainWindow::agregarPasajeros(int pas){
    int contador = 0;
    TurnoDesabordaje = 0;
    cont1 = 0;
    Pasajeros *P;
    while(contador < pas){
        int noMaletas = datoRandom(1,4);
        int noDoc = datoRandom(1,10);
        int noReg = datoRandom(1,3);
        P = new Pasajeros((*(int*)(void*)&P),noMaletas,noDoc,noReg);
        colaPasajero->agregar(P);
        contador++;
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    switch(TurnoDesabordaje){
    case 1:
        cout << cont1 << endl;
        cout << TurnoDesabordaje << endl;
        cout << "---------------------" << endl;
        //agregarPasajeros(cont1);
        if(colaAvion->obtenerAvion() == NULL){
            msgBox.setText("No existen aviones");
        }else{
            colaAvion->obtenerAvion();
            TurnoDesabordaje = colaAvion->mostrarPrimero();
            cont1 = colaAvion->No_Pesonas();
        }

        break;
    case 2:
        cout << cont1 << endl;
        cout << TurnoDesabordaje << endl;
        cout << "---------------------" << endl;
        //agregarPasajeros(10);
        cont1 = cont1 - 10;
        TurnoDesabordaje = 1;
        break;
    case 3:
        cout << cont1 << endl;
        cout << TurnoDesabordaje << endl;
        cout << "---------------------" << endl;
        //agregarPasajeros(15);
        cont1 = cont1 - 15;
        TurnoDesabordaje = 2;
        break;
    }

    colaAvion->mostrarCola();
    colaPasajero->recorrerCola();
    msgBox.setText("desabordaje realizado");
    msgBox.exec();
}
