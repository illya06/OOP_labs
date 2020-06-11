#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <QString>
#include <math.h>

class Vector{
public:
    double x;
    double y;

    Vector(){
    }

    Vector(double X, double Y){
        x = X;
        y = Y;
    }

    double Length(){
        return sqrt(x*x+y*y);
    }
    QString tell(){
        return "P ( " + QString::number(x) + " , " + QString::number(y) + " ) ";
    }

};

template <typename T>
class Array{
public:
    T* data;
    size_t Size;

    Array(size_t size){
        Size = size;
        data = (T*)std::malloc(sizeof(T)*size);
    }

    T& operator[] (int index){
        return data[index];
    }
    QString print(){
        QString temp;
        for(int i = 0; i<Size; i++){
            temp+= data[i].tell();
        }
        return temp;
    }
    QString max(){
        double max = data[0].Length();
        for(int i = 0; i<Size; i++){
            if(data[i].Length() > max)
                max = data[i].Length();
        }
        return "Max: "+QString::number(max);
    }
    QString sum(){
        double sum = 0;
        for(int i = 0; i<Size; i++){
                sum += data[i].Length();
        }
        return "Sum: "+QString::number(sum);
    }
};

#endif // TEMPLATE_H
