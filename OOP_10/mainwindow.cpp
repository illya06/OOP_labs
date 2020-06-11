#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "template.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
qDebug()<<"1 Створити шаблон класу Array, який містить однотипні\n елементи. Шаблон класу повинен давати можливість вивести всі\n елементи на екран, знайти суму всіх елементів, а також максимальний з\n елементів.\n2 Використати  функціонал шаблону на розробленому користувацькому\n типі з лаб.роботи 5.";
}

MainWindow::~MainWindow()
{
    delete ui;
}

Vector a(1,3);
Vector b(33,-1);
Vector c(0,-11);
Array<Vector> v(3);


void MainWindow::on_pushButton_clicked()
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
    ui->label->setText(v.print());
}



void MainWindow::on_pushButton_2_clicked()
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
    ui->label->setText(v.max());
}

void MainWindow::on_pushButton_3_clicked()
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
    ui->label->setText(v.sum());
}
