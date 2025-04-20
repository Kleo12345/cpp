#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Elephant.h"

using namespace std;

int main(){
    Animal a1("John",12);
    a1.printInfo(a1);
    Lion l1(5, "John2", 13);
    l1.printInfo(l1);
    Elephant el(5 , "John3", 14);
    el.printInfo(el);
    cout << "Operator overloading for lion " << endl;
    cout << l1 << endl;
    cout << "Operator overloading for elephant " << endl;
    cout << el << endl;
    cout << "Operator overloading for Animal " << endl;
    cout << a1 << endl;
}

