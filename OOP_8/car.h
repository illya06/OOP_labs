#ifndef CAR_H
#define CAR_H
#include <QString>
#include <QDebug>
#include <QLabel>

class Car
{
private:
    int ID;
    QString Name;
    QString Sname;
public:
    Car(){};
    Car(int id, QString n, QString sn){
        ID = id; Name = n; Sname = sn;
    }


    int print(){
        return 1;
    }

    int GetID(){
        return ID;
    }
    QString GetName(){
        return Name;
    }
    QString GetSname(){
        return Sname;
    }

    void SetID(int id){
        ID = id;
    }
    void SetName(QString name){
        Name = name;
    }
    void SetSname(QString sname){
        Sname = sname;
    }
};

#endif // CAR_H
