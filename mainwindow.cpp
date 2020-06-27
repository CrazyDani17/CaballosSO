#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    T = new Caballo(this,"Tornado");
    P = new Caballo(this,"Pegaso");
    S = new Caballo(this,"Socrates");
    connect(T,SIGNAL(setName(QString)),this,SLOT(on_SetName1(QString)));
    connect(P,SIGNAL(setName(QString)),this,SLOT(on_SetName2(QString)));
    connect(S,SIGNAL(setName(QString)),this,SLOT(on_SetName3(QString)));
    connect(T,SIGNAL(insertarTexto(QString)),this,SLOT(on_InsertarTexto(QString)));
    connect(P,SIGNAL(insertarTexto(QString)),this,SLOT(on_InsertarTexto(QString)));
    connect(S,SIGNAL(insertarTexto(QString)),this,SLOT(on_InsertarTexto(QString)));
    connect(T,SIGNAL(modificarTiempo(int)),this,SLOT(on_ModificarTiempo(int)));
    connect(P,SIGNAL(modificarTiempo(int)),this,SLOT(on_ModificarTiempo2(int)));
    connect(S,SIGNAL(modificarTiempo(int)),this,SLOT(on_ModificarTiempo3(int)));
    connect(T,SIGNAL(modificarTextoTD(QString)),this,SLOT(on_ModificarTextoTD1(QString)));
    connect(P,SIGNAL(modificarTextoTD(QString)),this,SLOT(on_ModificarTextoTD2(QString)));
    connect(S,SIGNAL(modificarTextoTD(QString)),this,SLOT(on_ModificarTextoTD3(QString)));
    connect(T,SIGNAL(modificarTextoTC(QString)),this,SLOT(on_ModificarTextoTC1(QString)));
    connect(P,SIGNAL(modificarTextoTC(QString)),this,SLOT(on_ModificarTextoTC2(QString)));
    connect(S,SIGNAL(modificarTextoTC(QString)),this,SLOT(on_ModificarTextoTC3(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_SetName1(QString Texto){
    ui->nombre1->setText(Texto);
}
void MainWindow::on_SetName2(QString Texto){
    ui->nombre2->setText(Texto);
}
void MainWindow::on_SetName3(QString Texto){
    ui->nombre3->setText(Texto);
}
void MainWindow::on_InsertarTexto(QString Texto){
    ui->listWidget->addItem(Texto);
}

void MainWindow::on_ModificarTiempo(int i){
    ui->recorrido1->setValue(i);
}

void MainWindow::on_ModificarTiempo2(int i){
    ui->recorrido2->setValue(i);
}

void MainWindow::on_ModificarTiempo3(int i){
    ui->recorrido3->setValue(i);
}
void MainWindow::on_ModificarTextoTD1(QString td){
    ui->TD1->setText(td);
}
void MainWindow::on_ModificarTextoTD2(QString td){
    ui->TD2->setText(td);
}
void MainWindow::on_ModificarTextoTD3(QString td){
    ui->TD3->setText(td);
}
void MainWindow::on_ModificarTextoTC1(QString td){
    ui->TC1->setText(td);
}
void MainWindow::on_ModificarTextoTC2(QString td){
    ui->TC2->setText(td);
}
void MainWindow::on_ModificarTextoTC3(QString td){
    ui->TC3->setText(td);
}
void MainWindow::on_pushButton_clicked()
{
    ui->recorrido1->setMinimum(0);
    ui->recorrido1->setMaximum(4);
    ui->recorrido2->setMinimum(0);
    ui->recorrido2->setMaximum(4);
    ui->recorrido3->setMinimum(0);
    ui->recorrido3->setMaximum(4);
    T->start();
    P->start();
    S->start();
}
