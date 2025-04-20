#include <iostream>
#include <vector>

using namespace std;

class Vehicle{
    protected: 
    int id;
    double dailyRentalPrice;
    static int count;
    int days;
    public:
    Vehicle(int i, double dR, int d) : id(i), dailyRentalPrice(dR), days(d){count++;}
    double calculateDailyRentalPrice(Vehicle &v){
        return v.dailyRentalPrice * v.days;
    } 
};

int Vehicle::count=0;

class Car : public Vehicle{
    private:
    int doors;
    bool check; 
    public:
    Car(int doors,bool check ,int id, double dailyRentalPrice, int days) : doors(doors),check(check), Vehicle(id, dailyRentalPrice, days) {}
    
    bool isLuxury(bool check){
        return check;
    }
    double calculateLuxuryDailyPrice(Car& c){
        return ((c.dailyRentalPrice*c.days)+((c.dailyRentalPrice * c.days)/2)); 
    }
    void luxuryCalc(Car& c){
        if (c.isLuxury(c.check) == false){
            c.calculateDailyRentalPrice(c);
        }else{
            c.calculateLuxuryDailyPrice(c);
        }
    }
};

class Moto : public Vehicle{
    private: 
    int cc;
    public: 
    Moto (int c , int i, double d,int d2) : cc(c), Vehicle(i, d, d2){}

    double calculateHighDisplacamentalPrice(Moto& m){
        return (m.dailyRentalPrice*m.days+((m.dailyRentalPrice * m.days)/(30.0/100.0)));
    }
    void calculateMoto(Moto& m){
        if (m.cc >= 1000){
            m.calculateHighDisplacamentalPrice(m); 
        }else{
            m.calculateDailyRentalPrice(m);
        }
    }
};

class Truck : public Vehicle{
    private : 
    int tons; 
    public: 
    Truck (int t , int i, double d,int d2) : tons(t), Vehicle(i,d,d2){}
    double calculateHighTonPrice(Truck& t) {
        return(t.dailyRentalPrice * t.days+((t.dailyRentalPrice*t.days)/(20.0/100.0)));
    }
    void calculateTruckPrice(Truck& t) {
        if(t.tons>=5){
            t.calculateHighTonPrice(t); 
        }else{
            t.calculateDailyRentalPrice(t);
        }
    }
};

int main(){
    Car c(4, true, 1, 20.0, 5);
    Moto m(1200, 2, 15.0, 10);
    Truck t(6, 3, 30.0, 15);

    c.luxuryCalc(c);
    m.calculateMoto(m);
    t.calculateTruckPrice(t);

    cout << "Car: " << c.calculateDailyRentalPrice(c) << endl;
    cout << "Motorbike: " << m.calculateHighDisplacamentalPrice(m) << endl;
    cout << "Truck: " << t.calculateHighTonPrice(t) << endl;

    return 0;
}