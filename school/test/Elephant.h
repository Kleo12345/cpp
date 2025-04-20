#ifndef ELEPHANT
#define ELEPHANT
#include <iostream>
#include <string>
#include <vector>

#include "Animal.h"
using namespace std;

class Elephant : public Animal{
    private:
    int fang;
    public:
    Elephant(int f, string name , int age) : fang(f) , Animal(name, age) {}
    friend ostream& operator<<(ostream& os, Elephant el);
    void printInfo(Elephant& e){
        cout << e << endl; 
    }
};  

ostream& operator<<(ostream& os,Elephant ep){
    cout << "Name: " << ep.name << endl;
    cout << "Age: " << ep.age << endl;
    cout << "Fang length is: " << ep.fang <<" 5cm" << endl;
    return os;
}

#endif