#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <coladoble.h>
#include <cola.h>
#include <listacirculardoble.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int cont1;
    int TurnoDesabordaje;
    ColaDoble *colaAvion = new ColaDoble();
    cola *colaPasajero = new cola();
    int pasajeros;
    int mantenimiento;
    int datoRandom(int LINF, int LSUP);
    void agregarAviones(int noAvion);
    void agregarPasajeros(int pas);
    void agregarMaleta(int equi);
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
