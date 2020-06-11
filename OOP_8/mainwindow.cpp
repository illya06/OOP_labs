#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classes.h"

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

//int id, std::string n, std::string sn, int tonn, int ppt

Truck a(1,"a","b",10,30);
Truck b(2,"aa","bb",110,2);
Bus   c(2,"ccc","asd",110,1);

void MainWindow::on_pushButton_clicked()
{

    if(c.print() == 3){
        ui->car->setText("Bus");
        ui->id->setText(QString::number(c.GetID()));
        ui->name->setText(c.GetName());
        ui->sname->setText(c.GetSname());
        ui->l4->setText("Person per kilometer: ");
        ui->l5->setText("Minimal ammount: ");
        ui->l4_o->setText(QString::number(c.PPK));
        ui->l5_o->setText(QString::number(c.MinPrice));
    }

    if(a.print() == 2){
        ui->truck->setText("Truck");
        ui->id_2->setText("UNKNOWN");
        ui->name_2->setText("UNKNOWN");
        ui->sname_2->setText("UNKNOWN");
        ui->l4_2->setText("Person per tonn: ");
        ui->l5_2->setText("Tonn: ");
        ui->l4_o_2->setText(QString::number(a.PPT));
        ui->l5_o_2->setText(QString::number(a.Tonn));
    }

    if(b.print() == 2){
        ui->bus->setText("Truck");
        ui->id_5->setText("UNKNOWN");
        ui->name_5->setText("UNKNOWN");
        ui->sname_5->setText("UNKNOWN");
        ui->l4_5->setText("Person per tonn: ");
        ui->l5_5->setText("Tonn: ");
        ui->l4_o_5->setText(QString::number(b.PPT));
        ui->l5_o_5->setText(QString::number(b.Tonn));
     }

    if(a.PPT*a.Tonn > b.PPT*b.Tonn && a.PPT*a.Tonn > c.PPK*c.MinPrice/10){
        ui->winner->setText("Truck with "+QString::number(a.PPT)+" and " + QString::number(a.Tonn));
    }
    if(b.PPT*b.Tonn > a.PPT*a.Tonn && b.PPT*b.Tonn > c.PPK*c.MinPrice/10){
        ui->winner->setText("Truck with "+QString::number(b.PPT)+" and " + QString::number(b.Tonn));
    }
    if(c.PPK*c.MinPrice/10 > a.PPT*a.Tonn && b.PPT*b.Tonn < c.PPK*c.MinPrice/10){
        ui->winner->setText("Bus have won");
    }
}
