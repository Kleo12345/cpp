#include <iostream>

using namespace std;

class rettangolo{
    public:
    double perimetro;
    double area;
    double area_quadrato;
    double base;
    double altezza;
    double lato;
    rettangolo(double x, double y){
        base = x;
        altezza = y;
        perimetro = 2 * (base + altezza);
        area = base * altezza;
    }
    rettangolo(double x){
        lato = x;
        area_quadrato = lato * lato;
    }
};

int main() {
    rettangolo r1(5, 3);
    cout << "Perimetro: " << r1.perimetro << endl;
    cout << "Area: " << r1.area << endl;

    rettangolo r2(7);
    cout << "Area quadrato: " << r2.area_quadrato << endl;
    if (r1.area_quadrato)
    if (r1.area > r2.area_quadrato){
        cout << "L'area del rettangolo è maggiore dell'area dell quadrati" << endl;
    }else if(r1.area < r2.area_quadrato){
        cout << "L'area del quadratti è maggiore dell'area dell rettangolo" << endl;
    }else{
        cout << "Le due aree sono uguali" << endl;
    }
    
    return 0;
}