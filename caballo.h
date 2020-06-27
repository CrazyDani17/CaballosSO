#ifndef CABALLO_H
#define CABALLO_H

#include <QThread>
#include <iostream>
#include <QTime>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Caballo : public QThread
{
    Q_OBJECT
public:
    explicit Caballo(QObject *parent = nullptr,string str="Caballo");

private:
    string name;
    const int FIN = 4;
signals:
    void setName  (QString);
    void insertarTexto  (QString);
    void modificarTiempo (int);
    void modificarTextoTD (QString);
    void modificarTextoTC (QString);
protected:
    void run();
};

#endif // CABALLO_H
