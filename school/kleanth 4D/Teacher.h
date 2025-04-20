#ifndef TEACHER
#define TEACHER
#include <iostream>
#include <string>
#include "Worker.h"
#include "Class.h"


using namespace std; 
class Teacher: public Worker{
    private:
    string ruole;
    string subject;
    vector <SchoolClass> classes;
    public:
    friend ostream& operator<<(ostream& os, Teacher& t);
    Teacher(string name, string surname, double salary, string address, string ruole, string subject): Worker(name, surname, salary, address), ruole(ruole), subject(subject) {}
    void printInfo(Teacher& t){
        cout << t;
    }
};

ostream& operator<<(ostream& os, Teacher& t){
    os << "Name: " << t.name << ", Surname: " << t.surname << ", Salary: " << t.salary << ", Address: " << t.address << ", Role: " << t.ruole << ", Subject: " << t.subject << endl;
    return os;
}

#endif 