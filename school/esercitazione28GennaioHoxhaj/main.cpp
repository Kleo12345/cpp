#include <iostream>
#include <string>
#include <vector>
#include "Bike.h"
#include "MountainBike.h"
using namespace std;

int main(){
    Bike b(10, 15);
    MountainBike mb(12, 20, "Trek", 4);
    b.print();
    mb.print();
    return 0;
}

