#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QList>
#include <QSet>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Deque"<< "Deque copy" << "MultiSet"<< "mset + dec");
    qDebug()<<"\n1. Створити об’єкт-контейнер (1) у відповідності до індивідуального варіанту і заповнити його даними користувацього типу, згідно варіанту.\n2. Вивести контейнер.\n3. Змінити контейнер, видаливши з нього одні елементи і замінивши інші.\n4. Проглянути контейнер, використовуючи для доступу до його елементів ітератори.\n5. Створити другий контейнер цього ж класу і заповнити його даними того ж типу, що і перший контейнер.\n6. Змінити перший контейнер, видаливши з нього n елементів після заданого і добавивши опісля в нього всі елементи із другого контейнера.\n7. Вивести перший і другий контейнери.\n8. Відсортувати контейнер по спаданню елементів та вивести результати.\n9. Використовуючи необхідний алгоритм, знайти в контейнері елемент, який задовільняє заданій умові.\n10. Перемістити елементи, що задовільняють умові в інший, попередньо пустий контейнер (2). Тип цього контейнера визначається згідно варіанту.\n11. Проглянути другий контейнер.\n13. Відсортувати перший і другий контейнери по зростанню елементів, вивести результати.\n15. Отримати третій контейнер шляхом злиття перших двох.\n16. Вивести на екран третій контейнер.\n17. Підрахувати, скільки елементів, що задовільянють заданій умові, містить третій контейнер.";
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVector<char> vect;
QVector<char> vect_copy;
QVector<char>::iterator it_v = vect.begin();
QVector<char>::iterator it_v_copy = vect.begin();

QList<char> list;
QList<char> temp;
QList<char>::iterator it_l = temp.begin();


QSet<char> set;
QSet<char>::iterator it_s = set.begin();

void MainWindow::on_pushButton_clicked()
{
    //qDebug()<<" ";
    it_v = vect.begin();

    for(int j = 0; j < ui->tableWidget->rowCount(); j++){
        QTableWidgetItem *item = new QTableWidgetItem(0);
        ui->tableWidget->setItem(j+1,0,item);
    }
    for(int i = 0; it_v != vect.end(); i++, it_v++){
        //qDebug()<<*it_v << " " << i;
        QString val = QChar(*it_v);
        QTableWidgetItem *item = new QTableWidgetItem(val);
        ui->tableWidget->setItem(i,0,item);

    }
}

void MainWindow::on_add_clicked()
{
    vect.push_back(*(ui->add_input->text().toUtf8().constData()));
}

void MainWindow::on_del_clicked()
{
    int position = ui->delete_position->text().toInt();
    int ammount = ui->delete_count->text().toInt();
    it_v = vect.begin();
    it_v_copy = vect_copy.begin();
    vect.remove(position - 1,ammount);
    for(int i = position - 1; it_v_copy != vect_copy.end(); i++){
        vect.insert(i, *it_v_copy);
        it_v_copy++;
    }

}

void MainWindow::on_copy_clicked()
{
    it_v = vect.begin();
    for (int i = 0; it_v != vect.end(); i++, it_v++) {
        vect_copy.push_back(*it_v);
        QString val = QChar(*it_v);
        QTableWidgetItem *item = new QTableWidgetItem(val);
        ui->tableWidget->setItem(i,1,item);
    }
}

void MainWindow::on_change_clicked()
{
    int position = ui->change_pos->text().toInt();
    char val = ui->change_val->text()[0].toLatin1();
    vect.remove(position-1);
    vect.insert(position-1, val);
    //vect[position-1] = val;
}

void MainWindow::on_sort_clicked()
{
   // qDebug()<< "\nSorting";
   char temp;
   for(int i = 0; i < vect.size(); i++){
       it_v = vect.begin();
       for(int j = 0; j < vect.size() - i; j++, it_v++){

           if(*it_v > *(it_v+1)){
              //qDebug()<<*it_v << "is bigger then "<<*(it_v+1);
              temp = *(it_v+1);
              *(it_v + 1) = *it_v;
              *it_v = temp;
           }
       }
   }
}

void MainWindow::on_find_clicked()
{
    if(vect.contains(ui->find_el->text()[0].toLatin1())){
        ui->result->setText("exists");
        set.insert(ui->find_el->text()[0].toLatin1());
    }else{
        ui->result->setText("missing");
    }

}

void MainWindow::on_show_set_clicked()
{
    it_s = set.begin();
    for(int j = 0; j < ui->tableWidget->rowCount(); j++){
        QTableWidgetItem *item = new QTableWidgetItem(0);
        ui->tableWidget->setItem(j+1,2,item);
    }
    for (int i = 0; it_s != set.end(); i++, it_s++) {
        vect_copy.push_back(*it_s);
        QString val = QChar(*it_s);
        QTableWidgetItem *item = new QTableWidgetItem(val);
        ui->tableWidget->setItem(i,2,item);
    }
}

void MainWindow::on_show_set_2_clicked()
{
    list = vect.toList();
    temp = set.toList();
    it_l = temp.begin();
    for(;it_l != temp.end(); it_l++){
        list.push_back(*it_l);
    }
    for(int j = 0; j < ui->tableWidget->rowCount(); j++){
        QTableWidgetItem *item = new QTableWidgetItem(0);
        ui->tableWidget->setItem(j,3,item);
    }
    for (int i = 0; i < list.size(); i++) {
        QString val = QChar(list[i]);
        QTableWidgetItem *item = new QTableWidgetItem(val);
        ui->tableWidget->setItem(i,3,item);
    }
}

void MainWindow::on_find_2_clicked()
{
    int val = 0;
    it_l = list.begin();
    //qDebug()<<"\n "<<ui->find_el_2->text()[0].toLatin1();
    for(;it_l != list.end(); it_l++){

        if(*it_l == ui->find_el_2->text()[0].toLatin1()){
            val++;
            //qDebug()<<"match "<<val;
        }
    }
    ui->result_2->setText(QString::number(val));
}


void MainWindow::on_sort_2_clicked()
{
    // qDebug()<< "\nSorting";
    char temp;
    for(int i = 0; i < vect.size(); i++){
        it_v = vect.begin();
        for(int j = 0; j < vect.size() - i; j++, it_v++){

            if(*it_v < *(it_v+1)){
               //qDebug()<<*it_v << "is bigger then "<<*(it_v+1);
               temp = *(it_v+1);
               *(it_v + 1) = *it_v;
               *it_v = temp;
            }
        }
    }
}


void MainWindow::on_add_3_clicked()
{

}void MainWindow::on_add_2_clicked()
{

}void MainWindow::on_pushButton_2_clicked()
{

}






