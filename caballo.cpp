#include "caballo.h"
#include <QtCore>
#include <QRandomGenerator>
Caballo::Caballo(QObject *parent,string nombre) : QThread(parent)
{
    name=nombre;
}

void Caballo::run(){
    int w;
    QString name_e=QString::fromStdString(name);
    emit setName(name_e);
    QTime tiempo;
    QString td;
    QString aux;
    int tiempo_carrera;
    QTime tiempo_d;
    int tiempo_descanso;
    tiempo.start();
    for (int i = 0; i < 5; i++) {
        //cout<<"Posición " + i + ": " + name<<endl;
        emit modificarTiempo(i);
        aux = QString::fromStdString("Posición " + to_string(i) + ": " + name + "\n");
        emit insertarTexto(aux);
        try {
            w = QRandomGenerator::global()->bounded(10,2000);
            tiempo_d.start();
            this->msleep(w);
            aux = QString::fromStdString("El caballo " + name + " descansa" + "\n");
            emit insertarTexto(aux);
            tiempo_descanso = tiempo_d.elapsed();
            td= QString::number(tiempo_descanso);
            emit modificarTextoTD(td);
            aux = QString::fromStdString("El caballo " + name + " descansó: " + to_string(tiempo_descanso) + "\n");
            emit insertarTexto(aux);
            //cout<<"El caballo " + name + " descansa."<<endl;
        } catch (const std::exception& e) {
            //mensajes->addItem(QString::fromStdString(e.what())+QString::fromStdString("\n"));
            cout<<e.what();
        }
    }
    tiempo_carrera = tiempo.elapsed();
    QString t = QString::number(tiempo_carrera);
    emit modificarTextoTC(t);
    //cout<<"Fin de la carrera para: " + name<<endl;
    aux = QString::fromStdString("Fin de la carrera para: " + name + ". Tiempo: "+ to_string(tiempo_carrera) + "\n");
    emit insertarTexto(aux);
}
