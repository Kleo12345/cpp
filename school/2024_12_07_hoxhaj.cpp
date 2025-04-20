#include <iostream>
#include <string>

using namespace std;

class Employee{
    private:  
    string name;
    string surname;
    string id;
    public:
    Employee(string n, string s, string id) : name(n), surname(s), id(id) {}
    friend ostream& operator<<(ostream& os, Employee &e) { 
        cout << endl;
        os << "Name: " << e.name << endl;
        os << "Surname: " << e.surname << endl;
        os << "ID: " << e.id << endl;
        return os; 
    }
    friend istream& operator>>(istream& is, Employee &e){
        cout << endl;
        cout << "Give me the name: " << endl;
        is >> e.name;
        cout << "Give me the surname: " << endl;
        is >> e.surname;
        cout << "Give me the ID: " << endl;
        is >> e.id;
        return is;
    }
};

class Manager : public Employee{
    private:
    char department;
    public:
    Manager(string n, string s, string id, char d) : Employee(n, s, id), department(d) {}
    friend ostream& operator<<(ostream& os, Manager &m) {
        os << (Employee&)m;
        os << "Department: " << m.department << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Manager &m){
        is >> (Employee&)m;
        cout << "Give me the department: " << endl;
        is >> m.department;
        return is;
    }
    void sameDepartment(Manager m1, Manager m2){
        if (m1.department == m2.department){
            cout << "Managers are in the same department" << endl;
        }
        else{
            cout << "Manager are not in the same department" << endl;
        }
    }
};

int main(){
    Employee e1("", "", "");
    Manager m1("", "", "", 'a');
    Manager m2("", "", "", 'a');
    cout << "Give me your employee details" << endl;
    cin >> e1;
    cout << e1 << endl;
    cout << "Give me your manager details" << endl;
    cin >> m1;
    cout << m1 << endl;
    cout << "Give me your other manager details" << endl;
    cin >> m2;
    cout << m2 << endl;
    m1.sameDepartment(m1, m2);
    return 0;
}