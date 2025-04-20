#include <iostream>
#include <string>

using namespace std;

class Events{
    protected:
    string name;
    int reservations_made; 
    int reservations;
    public:
    Events(string n, int rmax, int r): name(n), reservations(rmax), reservations_made(r) {}
    
    int get_reservations_made(){
        return reservations_made;
    }

    int get_reservations(){
        return reservations;
    }
    string get_name(){
        return name;
    }
    void display(){
        if (get_reservations_made() == get_reservations()){
            cout << "The event " << get_name() << " has reached " << get_reservations_made() << " out of " << get_reservations();        
            cout << "The event is sold out." << endl;
        }else if (get_reservations_made() > get_reservations()){
            cout << "Error the number of reservations is higher than the capacity!" << endl;
        }else {
            cout << "The event is not sold out." << endl;
            cout << "The event " << get_name() << " has reached " << get_reservations_made() << " out of " << get_reservations();
        
        }
    }
};

class Concerts : public Events{
    protected:
    string band_name;
    public:
    Concerts(string n2, int rmax2, int r2, string b_n): band_name(b_n) , Events(n2,rmax2,r2) {}
    friend istream& operator>>(istream& o2, Concerts &c){
        cout << "Enter the name of the concert: " << endl;
        o2 >> c.name;
        cout << "Enter the maxium capacity of the location: " << endl;
        o2 >> c.reservations;
        cout << "Enter the name of the band: " << endl;
        o2 >> c.band_name;
        cout << "Enter the reservations number: " << endl;
        o2 >> c.reservations_made;
        return o2;
    }
};

class Private_events : public Events{
    protected:
    int access_code;
    public:
    Private_events(int a_c , string n3, int rmax3, int r3): access_code(a_c), Events(n3,rmax3,r3) {}
    friend istream& operator>>(istream& o2, Private_events &p){
        int a_c2 = 1234;
        cout << "Enter the access code: " << endl;
        o2 >> p.access_code;
        if (p.access_code == a_c2){
            cout << "Access granted." << endl;
        cout << "Enter the name of the private event: " << endl;
        o2 >> p.name;
        cout << "Enter the maxium capacity of the location: " << endl;
        o2 >> p.reservations;
        cout << "Enter the reservations number: " << endl;
        o2 >> p.reservations_made;
        }else {
            cout << "Access denied." << endl;
            return o2;
        };
        return o2;
    }
};

int main(){
    char check;
    Concerts c1("", 0, 0 ,"");
    Private_events p1(0, "", 0 , 0);
    cout << "Is your event a privat event?" << endl;
    cout << "(y for yes and n for no)" << endl;
    cin >> check;
    if (check == 'y'){
        cin >> p1;
        p1.display();
    }else{
        cin >> c1;
        c1.display();
    }
    return 0;
}