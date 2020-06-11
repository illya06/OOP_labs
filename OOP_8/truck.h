#ifndef TRUCK_H
#define TRUCK_H
#include "car.h"

class Truck: protected Car
{
public:
    int Tonn;
    int PPT;
    Truck();
    Truck(int id, QString n, QString sn, int tonn, int ppt){
        SetID(id); SetName(n); SetSname(sn);
        Tonn = tonn;
        PPT  = ppt;
    }

    int print(){
        return 2;
    }
};
#endif // TRUCK_H
