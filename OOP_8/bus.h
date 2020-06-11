#ifndef BUS_H
#define BUS_H
#include "car.h"

class Bus: public Car
{
public:
    int MinPrice;
    int PPK;
    Bus();
    Bus(int id, QString n, QString sn, int min, int ppk){
        SetID(id); SetName(n); SetSname(sn);
        MinPrice = min;
        PPK  = ppk;
    }


    int print(){
        return 3;
    }
};

#endif // BUS_H
