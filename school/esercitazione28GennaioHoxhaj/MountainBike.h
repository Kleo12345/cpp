#ifndef MOUNTAINBIKE
#define MOUNTAINBIKE
#include <iostream>
#include <string>
#include <vector>
#include "Bike.h"

using namespace std;

class MountainBike : public Bike{
    private:
    string brand;
    int selector;
    public:
    MountainBike(int s, int sp, string b, int sec) : Bike(s, sp), brand(b), selector(sec){}
    void print ()override{}
};

#endif