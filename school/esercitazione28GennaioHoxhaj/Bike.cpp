#include <iostream> 
#include "Bike.h"

using namespace std;

Bike::Bike(int s, int sp): size(s), speed(sp){}

    void Bike::print(){
        cout << "Size: " << size << ", Speed: " << speed << endl;
    }
    int Bike::goFaster(int s) {
        this->speed += s;
        return this->speed;
    }

    int Bike::goSlow(Bike& b,int s){
        if(s>b.speed){
            cout << "The slowing is bigger than the speed. ERROR!" << endl;
            return 0;
        }
        else{
            b.speed -= s;
            return b.speed;
        }
    }
