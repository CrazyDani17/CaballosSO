#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "caballo.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Caballo *T;
    Caballo *P;
    Caballo *S;

private slots:
    void on_pushButton_clicked();
    void on_SetName1(QString);
    void on_SetName2(QString);
    void on_SetName3(QString);
    void on_InsertarTexto(QString);
    void on_ModificarTiempo(int);
    void on_ModificarTiempo2(int);
    void on_ModificarTiempo3(int);
    void on_ModificarTextoTD1(QString);
    void on_ModificarTextoTD2(QString);
    void on_ModificarTextoTD3(QString);
    void on_ModificarTextoTC1(QString);
    void on_ModificarTextoTC2(QString);
    void on_ModificarTextoTC3(QString);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
