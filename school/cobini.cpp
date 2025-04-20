#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {}
    virtual void sound() = 0; // Pure virtual function
    virtual void info() = 0;  // Pure virtual function
    virtual ~Animal() {}      // Virtual destructor
};

class Lion : public Animal {
protected:
    string roar;
public:
    Lion(string n, int a) : Animal(n, a), roar("ROAR") {}
    virtual void sound() override {
        cout << roar << endl;
    }
    virtual void info() override {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Elephant : public Animal {
protected:
    int tusk_length;
    string trumpeting;
public:
    Elephant(string n, int a, int t) : Animal(n, a), trumpeting("IIIIHH"), tusk_length(t) {}
    virtual void sound() override {
        cout << trumpeting << endl;
    }
    virtual void info() override {
        cout << "Name: " << name << ", Age: " << age << ", Tusk Length: " << tusk_length << " cm" << endl;
    }
};

int main() {
    Lion Leone("Mario", 25);
    Leone.sound();
    Leone.info();
    
    Elephant Elefante("Filippo", 35, 15);
    Elefante.sound();
    Elefante.info();

    return 0;
}
