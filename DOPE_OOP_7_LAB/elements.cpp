#include "elements.h"


    Object::Object(){
        value = 0;
    }
    Object::Object(int val){
        value = val;
    }
    Object::Object(Object &obj){
        value = obj.value;
    }

   //Queue declaration -----------------------------------------

    Queue::Queue(){
        data = (Object*)malloc(sizeof(Object));
        size = 0;
    }

    Queue::~Queue(){

    }

    void Queue::Add(Object obj){
        Object temp(obj);

        realloc(data, sizeof (int)*1);

        size = size + 1;
        data[size-1] = temp;
    }

    void Queue::DeleteLast(){
        if(size != 0){
            size -= 1;
            free(&data[size-1]);
        }
    }

    void Queue::Multiply(int val){
        for(int i = 0; i < size; i++){
            data[i].value *= val;
        }
    }

    int Queue::Size(){
        return size;
    }

    int Queue::Max(){
        int max = data[0].value;
        for(int i = 0; i < size; i++){
            if(data[i].value > max)
                max = data[i].value;
        }
        return max;
    }

    int Queue::Min(){
        int min = data[0].value;
        for(int i = 0; i < size; i++){
            if(data[i].value < min)
                min = data[i].value;
        }
        return min;
    }

    double Queue::Avg(){
        double sum = 0;
        for(int i = 0; i < size; i++){
            sum += data[i].value;
        }
        return sum/size;
    }

    void Queue::Clear(){
        size = 0;
        free(data);
        data = (Object*)malloc(sizeof(Object));
    }

    bool Queue::isEmpty(){
        if(size == 0){
            return true;
        }else{
            return false;
        }
    }


