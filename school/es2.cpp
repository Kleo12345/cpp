#include <iostream>

using namespace std;

int main(){
    int pay = 1;
    int days; 
    cin >> days ;
    for (int i = 0; i < days -1; i++){
        pay = pay * 2;
    }
    cout << pay << endl;
}