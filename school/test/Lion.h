#ifndef LION
#define LION
#include "Animal.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lion : public Animal{
    private:
    int killsMade;
    public:
    friend ostream& operator<<(ostream& os, Lion& lion);
    Lion (int kd, string name, int age) : killsMade(kd), Animal(name, age){}
    void printInfo(Lion& l){
        cout << l << endl; 
    }
};

ostream& operator<<(ostream& os , Lion& lion){
    cout << "Name: " << lion.name << endl;
    cout << "Age: " << lion.age << endl;
    cout << "The number of animals it has killed is: " << lion.killsMade << endl;
    return os;
}

#endif 