#include <iostream>
#include <string>

using namespace std;

class Vehicle{
    protected: 
    string brand;
    int year;
    public:
    Vehicle(string b, int y) : brand(b) , year(y){}
};
