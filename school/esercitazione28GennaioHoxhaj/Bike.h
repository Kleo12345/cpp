#ifndef BIKE_H
#define BIKE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Bike{
    protected:
    int size;
    int speed;
    public:
    Bike(int s, int sp): size(s), speed(sp){}
    virtual ~Bike() {}  // Virtual Destructor
    virtual void print();
    int goFaster(int s);
    int goSlow(Bike& b, int s);
};

#endif