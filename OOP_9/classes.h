#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <QString>
#include <QDebug>

using namespace std;

class Base{
public:
    int time;
    double final_price;
};

class WPSubscription: virtual public Base {
public:

    virtual QString Price() = 0;
    virtual QString Zone() = 0;
    virtual QString Type() = 0;
    virtual ~WPSubscription(){
        qDebug("account is deleted\n");
    }
};

class SingleWPSubscription: public WPSubscription{
public:
    QString Price() override{
        return "time*10";
    }
    QString Zone() override{
        return "Public space, waterslides";
    }
    QString Type() override{
        return "Single";
    }
    ~SingleWPSubscription(){
       qDebug("single account is deleted\n");
    }
};

class GroupWPSubscription: public WPSubscription{
public:
    QString Price() override{
        return "time*17";
    }
    QString Zone() override{
        return "Public space, waterslides, kaffe";
    }
    QString Type() override{
        return "Group";
    }
    ~GroupWPSubscription(){
        qDebug("group account is deleted\n");
    }
};

class FamilyWPSubscription: public WPSubscription{
public:
    QString Price() override{
        return "time*30";
    }
    QString Zone() override{
        return "Public space, waterslides, kaffe, hotel";
    }
    QString Type() override{
        return "Family";
    }
    ~FamilyWPSubscription(){
        qDebug("family account is deleted\n");
    }
};

#endif // CLASSES_H
