#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// class Vector
// perenav(+-*(*)vector), angle, length,
// perenav friend: vect*val, <<(from form), >>(to form), >(more), <(less)
// == (if vector equals other vector)

class Vector
{
public:
    double x;
    double y;
    static int amount;
    Vector(){
        amount++;
    }

    Vector(double val1, double val2)
    {
        x = val1;
        y = val2;
        amount++;
    }

    double len()
    {
        return sqrt(x*x+y*y);
    }

    Vector operator + (Vector V)
    {
        return Vector(x+V.x, y+V.y);
    }

    Vector operator - (Vector V)
    {
        return Vector(x-V.x, y-V.y);
    }


    double operator * (Vector V)//scalar V1 * V2
    {
        return x * V.x + y * V.y;
    }

    double operator % (Vector V)
    {//cosinus of angle
        return (x * V.x + y * V.y)/(std::abs(sqrt(V.x*V.x+V.y*V.y)*sqrt(x*x+y*y)));
    }

    static int how_much()
    {
        return amount;
    }

    friend Vector multply(Vector * V, int val)
    {
        return Vector(V->x*val,V->y*val);
    }

    friend bool operator > (Vector &V1, Vector &V2);
    friend bool operator < (Vector &V1, Vector &V2);
    friend bool operator == (Vector &V1, Vector &V2);
};

int Vector::amount = 0;

bool operator > (Vector &V1, Vector &V2){
    return V1.len()<V2.len();
};

bool operator < (Vector &V1, Vector &V2){
    return V1.len()>V2.len();
};

bool operator == (Vector &V1, Vector &V2){
    return V1.x == V2.x && V1.y == V2.y;
};

//creating test vectors
Vector V1(1.0,1.0);
Vector V2(3.0,0.0);
Vector V3;

void MainWindow::on_pushButton_clicked()
{
    V3 = V1 + V2;
    ui->x_cord->setText(QString::number(V3.x));
    ui->y_cord->setText(QString::number(V3.y));
}

void MainWindow::on_pushButton_2_clicked()
{
    V3 = V1 - V2;
    ui->x_cord->setText(QString::number(V3.x));
    ui->y_cord->setText(QString::number(V3.y));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->cos->setText(QString::number(V1*V2));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->cos->setText(QString::number(V1%V2));
}

void MainWindow::on_pushButton_5_clicked()
{
    if(V1 > V2)
    {
        ui->por->setText("true");
    }else
    {
        ui->por->setText("false");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(V1 < V2)
    {
        ui->por->setText("true");
    }else
    {
        ui->por->setText("false");
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(V1 == V2)
    {
        ui->por->setText("true");
    }else
    {
        ui->por->setText("false");
    }
}
