#include <iostream>
#include <vector>

using namespace std;

struct house{
    double metri;
    char energy_class;
    double price;
};

int main(){
    house arr[3];
    for(int i = 0; i < 3; i++){
        cout << "Enter your house metri quadri: " << endl;
        cin >> arr[i].metri;
        while (true)
        {
            cout << "Enter your house energy class: " << endl;
            cin >> arr[i].energy_class;
            if (arr[i].energy_class == 'A' || arr[i].energy_class == 'B' || arr[i].energy_class == 'C' || arr[i].energy_class == 'D' || arr[i].energy_class == 'E' || arr[i].energy_class == 'F') {
                break;
            }else{
                cout << "Invalid energy class. Please enter a valid one (A, B, C, D, E, F)." << endl;
            }
        }
        cout << "Enter your house price: " << endl;
        cin >> arr[i].price;
    }

    double lowest_price = 0 ;
    char lowest_energy_class = 0; 

    for(int i = 0; i < 3; i++){
        if(lowest_price == 0){
            lowest_price = arr[i].price;
            lowest_energy_class = arr[i].energy_class;
        }
        else if(arr[i].price < lowest_price){
            lowest_price = arr[i].price;
            lowest_energy_class = arr[i].energy_class;
        }
        else if(arr[i].price == lowest_price && arr[i].energy_class < lowest_energy_class){
            lowest_energy_class = arr[i].energy_class;
        }
    }
    cout << "The cheapest house is: " << lowest_energy_class << " energy class with a price of " << lowest_price << " EUR." << endl;

    return 0;
}
