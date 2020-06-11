#ifndef CHYSLO_H
#define CHYSLO_H
#include <iostream>
#include <QString>
#include <QDebug>
#include <string>
using namespace std;


class Chyslo{
public:
    int value;

    Chyslo(){

    }

    Chyslo(int val){
        value = val;
    }
    
    int Add(Chyslo val){
        return value+val.value;
    }

    int Sub(Chyslo val){
        return value-val.value;
    }

    int Multi(Chyslo val){
        return value*val.value;
    }

    QString convertToBin(){
       char const* msg = "Overflow";
       if(value > 255)
            throw msg;

       long long binaryNumber = 0;
       int remainder, i = 1;
       while (value!=0)
       {
           remainder = value%2;
           value /= 2;
           binaryNumber += remainder*i;
           i *= 10;
       }
       return QString::number(binaryNumber);
    }

    QString convertToHexa()
    {
        char const* msg = "To big value";
        if(value > 1000000 || value < -1000000)
            throw msg;
        char val_in_hex[20];
        sprintf(val_in_hex, "%X", value);
        return val_in_hex;
    }

    QString convertToDec(){
        char const* msg = "To big value";
        if(value > 1000000 || value < -1000000)
            throw msg;
        return QString::number(value);
    }


    QString convert(int mode){
        try {
            QString a;
            if(mode == 2){
                a = convertToBin();
                return a;
            }else if(mode == 10){
                 a = convertToDec();
                 return a;
            }else if(mode == 16){
                 a = convertToHexa();
                 return a;
            }
        } catch (char const* msg) {
            return msg;
        }

    }

    void convertBinToDec(QString str)
    {
        qDebug()<<value;
        long long int n = str.toInt();
        int decimalNumber = 0, i = 0, remainder;
        while (n!=0)
        {
            remainder = n%10;
            n /= 10;
            decimalNumber += remainder*pow(2,i);
            ++i;
        }
        value = decimalNumber;

    }

    void convertHexaToDec(QString str)
    {
        string temp = str.toUtf8().constData();
        int decimalNumber = stoi(temp, 0, 16);
        value = decimalNumber;
    }

};

#endif // CHYSLO_H
