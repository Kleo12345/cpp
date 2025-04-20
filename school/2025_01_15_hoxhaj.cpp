#include <iostream>
#include <vector>

using namespace std;

class Participant;

class Course {
    private:
    string title;
    vector<Participant> participants;
    friend ostream& operator<<(ostream& os, Course& p);
    public:
    Course(string t): title(t) {}
    void addParticipant(Participant& p) { participants.push_back(p); }
    int getEarnings() const { 
        return participants.size() * 50;
    }
};

class Participant {
    protected:
    string name;
    string surname;
    string taxCode;
    static int count;
    public:
    Participant(string n, string s, string tc): name(n), surname(s), taxCode(tc) { count++; }
    string getSurname() { return surname; }
    int getCount() { return count; }
    virtual void displayRole() {
        cout << "Dynamic Binding: General Participant" << endl;
    }
};
ostream& operator<<(ostream& os, Course& c) {
    os << c.title << endl;
    for (auto& p : c.participants) os << " " << p.getSurname();
    return os;
}
int Participant::count = 0;

class Student : public Participant {
    private:
    string school;
    public:
    Student(string sc, string n, string s, string tc): school(sc), Participant(n, s, tc) {}
    void printInfo() {
        cout << "Name: " << name << ", Surname: " << surname << ", Tax Code: " << taxCode << ", School: " << school << endl;
    }
};

class Worker : public Participant {
    private:
    string role;
    public:
    Worker(string r, string n, string s, string tc): role(r), Participant(n, s, tc) {}
    void printInfo() {
        cout << "Name: " << name << ", Surname: " << surname << ", Tax Code: " << taxCode << ", Role: " << role << endl;
    }
};

int main() {
    Course course("Programming Course");
    Participant p1("Giuseppe", "Rossi", "GROSS123");
    p1.displayRole(); // Dynamic
    Student s1("High school", "Alice", "Smith", "ASMIT123");
    Student s2("Elementary", "Leo", "Gill", "HSK378KO");
    cout << "Static Binding: " << p1.getSurname() << endl; 
    Worker w1("Teacher", "Bob", "Johnson", "BJON123");
    course.addParticipant(s1);
    course.addParticipant(s2);
    cout << course << endl;
    cout << "The revenue of courses: " << course.getEarnings() << "$" << endl;
}
