#include <iostream>
#include <string> 
#include "MountainBike.h"
#include "Bike.h"

using namespace std;

MountainBike::MountainBike(int s, int sp, string b, int sec) : Bike(s, sp), brand(b), selector(sec){}


    void MountainBike::print (){
        cout << "Size: " << size << ", Speed: " << speed << " km/h" << ", Brand: " << brand << ", Marce Selector: " << selector << endl;
    }