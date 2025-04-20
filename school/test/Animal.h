#ifndef ANIMAL
#define ANIMAL
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
    protected:
    string name;
    int age;
    static int count;
    public:
    Animal(string n, int a) : name(n), age(a) {count++;}
    friend ostream& operator<<(ostream& os , Animal an);
    void printInfo(Animal& an) {
        cout << an; 
    }
};
int Animal::count = 0;

ostream& operator<<(ostream& os, Animal an){
    os << "The animal name is: "<< an.name << endl;
    os << "The animal age is: "<< an.age << endl;
    return os;
}

#endif 