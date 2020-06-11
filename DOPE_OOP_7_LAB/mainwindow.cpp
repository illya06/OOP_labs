#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "elements.h"

Queue queue;

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


void MainWindow::on_pushButton_clicked()
{
    Object a(ui->lineEdit->text().toInt());
    queue + a;
}

void MainWindow::on_pushButton_4_clicked()
{
    for(int j = 0; j < ui->tableWidget->rowCount(); j++){
        QTableWidgetItem *item = new QTableWidgetItem(0);
        ui->tableWidget->setItem(j+1,0,item);
    }
    for(int i = 0; i < queue.Size(); i++){
        //qDebug()<<*it_v << " " << i;
        QString val = QString::number(queue.data[i].value);
        QTableWidgetItem *item = new QTableWidgetItem(val);
        ui->tableWidget->setItem(i,0,item);

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    queue.DeleteLast();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit_2->setText(QString::number(queue.Size()));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit_3->setText(QString::number(queue.Max()));
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit_4->setText(QString::number(queue.Min()));
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_5->setText(QString::number(queue.Avg()));
}

void MainWindow::on_pushButton_8_clicked()
{
    queue.Clear();
}

void MainWindow::on_pushButton_9_clicked()
{
    if(queue.isEmpty()){
        ui->lineEdit_6->setText("Empty");
    }else{
        ui->lineEdit_6->setText("Not empty");
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    queue * ui->lineEdit_7->text().toInt();
}

void MainWindow::on_pushButton_11_clicked()
{

}
