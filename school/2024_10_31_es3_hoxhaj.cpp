#include <iostream>
using namespace std;

class Team {
private:
    int wins;
    int losses;
    int draws;

public:
    Team() : wins(0), losses(0), draws(0) {}

    void setWins(int w) {
         wins = w; 
    }
    void setLosses(int l) { 
        losses = l; 
    }
    void setDraws(int d) { 
        draws = d; 
    }

    int points() const { 
        return 3 * wins + 1 * draws; 
    }

    void seasonStart() {
        wins = losses = draws = 0;
    }
};

int main() {
    Team Bar, Foo;
    int w, l, d;
    cout << "Inserisci il numero di partite vinte per Bar: ";
    cin >> w;
    Bar.setWins(w);
    cout << "Inserisci il numero di partite perse per Bar: ";
    cin >> l;
    Bar.setLosses(l);
    cout << "Inserisci il numero di partite pareggiate per Bar: ";
    cin >> d;
    Bar.setDraws(d);
    Bar.seasonStart();
    cout << "Inserisci il numero di partite vinte per Foo: ";
    cin >> w;
    Foo.setWins(w);
    cout << "Inserisci il numero di partite perse per Foo: ";
    cin >> l;
    Foo.setLosses(l);
    cout << "Inserisci il numero di partite pareggiate per Foo: ";
    cin >> d;
    Foo.setDraws(d);
    Foo.seasonStart();
    if (Bar.points() > Foo.points())
    cout << "Bar ha più punti di Foo.";
    else if (Bar.points() < Foo.points())
    cout << "Foo ha più punti di Bar.";
    else
    cout << "Bar e Foo hanno lo stesso numero di punti.";
    return 0;
}