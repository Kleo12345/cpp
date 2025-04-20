#include <iostream>
#include <vector> 

using namespace std;

int main(){
    double spent = 0;
    int points = 0;
    cin >> spent;
    if(spent < 50.0){
        points = 0;
            cout << "points: " << points << endl;
    }else if(spent > 50.0 && spent < 99.9){
            points = 10;
                cout << "points: " << points << endl;
    }else if (spent > 100.0 && spent < 149.99){
        points = 25;
            cout << "points: " << points << endl;
    }else if (spent>150){
        points = 50;
            cout << "points: " << points << endl;
    }else {
        cout << "ERROR!" << endl;
    }
}