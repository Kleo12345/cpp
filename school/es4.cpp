#include <iostream>
#include <cstdlib>

using namespace std;

int main (){
    srand(time(NULL));
    int money; 
    int img = rand();
    int img2 = rand();
    int img3 = rand();
    cout << "How much money do you want to play?" << endl;
    cin >> money;
    if (img == img2 && img3 == img) {
        money = money *3;
    }else if(img == img2 && img3 != img) {
        money = money *2;
    }else {
        money = 0;
    }
    cout << img << " "<< img2 << " " << img3 <<endl;
    cout << "Here is how much you have won " << money << endl;
    return money;
}