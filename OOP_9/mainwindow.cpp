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

SingleWPSubscription *SWPS = new SingleWPSubscription;
GroupWPSubscription  *GWPS = new GroupWPSubscription;
FamilyWPSubscription *FWPS = new FamilyWPSubscription;

Base Subs[3] = {*SWPS, *GWPS, *FWPS};

void MainWindow::on_pushButton_clicked()
{
    SWPS->time = 10;
    GWPS->time = 20;
    FWPS->time = 30;

    ui->ptp_1->setText(SWPS->Price());
    ui->time_1->setText(QString::number(SWPS->time));
    ui->sub_1->setText(SWPS->Type());
    ui->zones_1->setText(SWPS->Zone());

    ui->ptp_2->setText(GWPS->Price());
    ui->time_2->setText(QString::number(GWPS->time));
    ui->sub_2->setText(GWPS->Type());
    ui->zones_2->setText(GWPS->Zone());

    ui->ptp_3->setText(FWPS->Price());
    ui->time_3->setText(QString::number(FWPS->time));
    ui->sub_3->setText(FWPS->Type());
    ui->zones_3->setText(FWPS->Zone());

    delete SWPS;
    delete GWPS;
    delete FWPS;
}

