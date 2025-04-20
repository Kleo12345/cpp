#ifndef OFFICEWORKER
#define OFFICEWORKER
#include <iostream>
#include <string>
#include "Worker.h"

using namespace std;

class OfficeWorker: public Worker{
    private:
    string office;
    public:
    OfficeWorker(string name, string surname, double salary, string address, string office): Worker(name, surname, salary, address), office(office) {}
    friend ostream& operator<<(ostream& os, OfficeWorker& ow);
    void printInfo(OfficeWorker& ow){
        cout << ow;
    }
};

ostream& operator<<(ostream& os, OfficeWorker& ow){
    os << "Name: " << ow.name << ", Surname: " << ow.surname << ", Salary: " << ow.salary << ", Address: " << ow.address << ", Office: " << ow.office << endl;
    return os;
}

#endif 