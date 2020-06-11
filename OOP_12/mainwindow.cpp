#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Chyslo.h"
#include <QRegularExpression>
#include <QDebug>

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

Chyslo a;
Chyslo b;
Chyslo temp;



void MainWindow::on_pushButton_clicked()
{
    QString test = ui->lineEdit->text()+" "+ui->lineEdit_2->text();
    try {
        throw test;
    }
    catch (QString exeption) {
        if(ui->bin->isChecked()){
            QRegularExpression re("^([01]+ [01]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.convertBinToDec(ui->lineEdit->text());
                b.convertBinToDec(ui->lineEdit_2->text());
                temp.value = a.value + b.value;
                qDebug()<<temp.value;
                ui->result->setText(temp.convert(2));
                if(ui->bin_3->isChecked()){
                    temp.value = a.value + b.value;
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    temp.value = a.value + b.value;
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    temp.value = a.value + b.value;
                    ui->result_int->setText(temp.convert(16));
                }

            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else if(ui->dec->isChecked()){
            QRegularExpression re("^^([0123456789]+ [0123456789]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.value = ui->lineEdit->text().toInt();
                b.value = ui->lineEdit_2->text().toInt();
                temp.value = a.value + b.value;
                ui->result->setText(temp.convert(10));
                if(ui->bin_3->isChecked()){
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    ui->result_int->setText(temp.convert(16));
                }
            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";   
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else if(ui->twe->isChecked()){
            QRegularExpression re("^^([0123456789ABCDEF]+ [0123456789ABCDEF]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.convertHexaToDec(ui->lineEdit->text());
                b.convertHexaToDec(ui->lineEdit_2->text());
                temp.value = a.value + b.value;
                ui->result->setText(temp.convert(16));
                if(ui->bin_3->isChecked()){
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    ui->result_int->setText(temp.convert(16));
                }
            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else{
            ui->result->setText("Choose format");
            ui->result_int->setText(" ");
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString test = ui->lineEdit->text()+" "+ui->lineEdit_2->text();
    try {
        throw test;
    }
    catch (QString exeption) {
        if(ui->bin->isChecked()){
            QRegularExpression re("^([01]+ [01]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.convertBinToDec(ui->lineEdit->text());
                b.convertBinToDec(ui->lineEdit_2->text());
                temp.value = a.value - b.value;
                ui->result->setText(temp.convert(2));
                if(ui->bin_3->isChecked()){
                    temp.value = a.value - b.value;
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    temp.value = a.value - b.value;
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    temp.value = a.value - b.value;
                    ui->result_int->setText(temp.convert(16));
                }
            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else if(ui->dec->isChecked()){
            QRegularExpression re("^([0123456789]+ [0123456789]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.value = ui->lineEdit->text().toInt();
                b.value = ui->lineEdit_2->text().toInt();
                temp.value = a.value - b.value;
                ui->result->setText(temp.convert(10));
                if(ui->bin_3->isChecked()){
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    ui->result_int->setText(temp.convert(16));
                }
            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else if(ui->twe->isChecked()){
            QRegularExpression re("^^([0123456789ABCDEF]+ [0123456789ABCDEF]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.convertHexaToDec(ui->lineEdit->text());
                b.convertHexaToDec(ui->lineEdit_2->text());
                temp.value = a.value - b.value;
                ui->result->setText(temp.convert(16));
                if(ui->bin_3->isChecked()){
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    ui->result_int->setText(temp.convert(16));
                }
            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else{
            ui->result->setText("Choose format");
            ui->result_int->setText(" ");
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString test = ui->lineEdit->text()+" "+ui->lineEdit_2->text();
    try {
        throw test;
    }
    catch (QString exeption) {
        if(ui->bin->isChecked()){
            QRegularExpression re("^([01]+ [01]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.convertBinToDec(ui->lineEdit->text());
                b.convertBinToDec(ui->lineEdit_2->text());
                temp.value = a.value * b.value;
                ui->result->setText(temp.convert(2));
                if(ui->bin_3->isChecked()){
                    temp.value = a.value * b.value;
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    temp.value = a.value * b.value;
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    temp.value = a.value * b.value;
                    ui->result_int->setText(temp.convert(16));
                }
            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else if(ui->dec->isChecked()){
            QRegularExpression re("^([0123456789]+ [0123456789]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.value = ui->lineEdit->text().toInt();
                b.value = ui->lineEdit_2->text().toInt();
                temp.value = a.value * b.value;
                ui->result->setText(temp.convert(10));
                if(ui->bin_3->isChecked()){
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    ui->result_int->setText(temp.convert(16));
                }
            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else if(ui->twe->isChecked()){
            QRegularExpression re("^^([0123456789ABCDEF]+ [0123456789ABCDEF]+$)");
            QRegularExpressionMatch match = re.match(exeption);
            if(match.hasMatch()){
                a.convertHexaToDec(ui->lineEdit->text());
                b.convertHexaToDec(ui->lineEdit_2->text());
                temp.value = a.value * b.value;
                ui->result->setText(temp.convert(16));
                if(ui->bin_3->isChecked()){
                    ui->result_int->setText(temp.convert(2));
                }else if(ui->dec_3->isChecked()){
                    ui->result_int->setText(temp.convert(10));
                }else if(ui->twe_3->isChecked()){
                    ui->result_int->setText(temp.convert(16));
                }
            }else{
                ui->result->setText("Wrong format");
                ui->result_int->setText(" ");
                qDebug()<<"Wrong format";
            }
            if(exeption == " "){
                ui->result->setText("Enter val");
                ui->result_int->setText(" ");
                qDebug()<<"Enter val";
            }
        }else{
            ui->result->setText("Choose format");
            ui->result_int->setText(" ");
        }
    }
}



