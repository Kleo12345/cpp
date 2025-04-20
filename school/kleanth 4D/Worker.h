#ifndef WORKER
#define WORKER

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Worker{
    protected: 
    string name;
    string surname;
    double salary;
    string address;
    public:
    friend ostream& operator<<(ostream& os, Worker& w);
    Worker(string name, string surname, double salary, string address): name(name), surname(surname), salary(salary), address(address) {}
    void printInfo(Worker& w){
        cout << w;   
    }
};

ostream& operator<<(ostream& os, Worker& w){
    os << "Name: " << w.name << ", Surname: " << w.surname << ", Salary: " << w.salary << ", Address: " << w.address << endl;
    return os;
}

#endif 