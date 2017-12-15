#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <coladoble.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ColaDoble *colaAvion = new ColaDoble();
    int pasajeros;
    int mantenimiento;
    int datoRandom(int LINF, int LSUP);
    void agregarAviones(int noAvion);
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
