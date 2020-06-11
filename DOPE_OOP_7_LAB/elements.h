#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <cstdlib>
#include <QDebug>

class Object{
public:
    int value;

    Object();
    Object(int);
    Object(Object &);

    bool isNextNull();
};

class Queue {
public:
   Object *data;
   int size;

   Queue();
   ~Queue();

   void Add(Object);
   void DeleteLast();
   void Multiply(int);

   int Size();
   int Max();
   int Min();
   double Avg();
   void Clear();
   bool isEmpty();

   void operator +(Object obj){
        Add(obj);
   }
   void operator -(int ammount){
       if(ammount <= size){
            for(int i = 0; i < ammount; i++){
                DeleteLast();
            }
       }else{
           qDebug()<<"Tooo biiiggggg!!!!";
       }
   }
   void operator *(int val){
       Multiply(val);
   }
};

#endif // ELEMENTS_H
