#include <iostream>
#include <vector>
#include "Teacher.h"
#include "Worker.h"
#include "OfficeWorker.h"
#include "Class.h"
#include <string> 

using namespace std;

int main() {
    Teacher t1("John", "Doe", 5000, "123 Main St", "Professor", "Math");
    t1.printInfo(t1);
    cout << t1 << endl;
    OfficeWorker ow1("Jane", "Smith", 4000, "456 Elm St", "Head Office");
    ow1.printInfo(ow1);
    cout << ow1 << endl;
    Worker w1("Alice", "Johnson", 3000, "789 Oak St");
    w1.printInfo(w1);
    cout << w1 << endl;
    return 0;
}