#include <iostream>
#include <string>
#include <Vehicle.h>

using namespace std;

class Car : public Vehicle{
    private: 
    int doors;
    static int count;
    public: 
    Car(string b, int y, int d) : Vehicle(b, y) , doors(d) {count++;}
    friend istream& operator>>(istream& is, Car t){
        cout << "Give me the vehicle brand: " << endl;
        is >> t.brand;
        cout << "Give me the vehicle year of registration: " << endl;
        is >> t.year;
        cout << "Give me how many doors this car has: " << endl;
        is >> t.doors;
        return is;
    }
    friend ostream& operator<<(ostream& os, Car v){
        cout << "The car brand: " << endl;
        os << v.brand;
        cout << "The car year of registration: " << endl;
        os << v.year;
        cout << "The car number of doors: " << endl;
        os << v.doors;
        return os;  
    }
};
int count::Car = 0;