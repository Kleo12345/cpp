#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Utente{
    protected:
    string name;
    static int id; 
    int prenotati;
    int tornati;
    bool check;
    public:
    int getid(){
        return id;
    }
    Utente (string n, int p, int t, bool c) : name(n), prenotati(p), tornati(t), check(c) {id++;}
    friend ostream& operator<<(ostream& o , Utente &u){
        o << "Nome: " << u.name << ", ID: " << u.getid() << ", Prenotati: " << u.prenotati << ", Tornati: " << u.tornati << endl;
        return o;
    }
    friend istream& operator>>(istream& o2 , Utente &u){
        cout << "Inserisci nome: ";
        o2 >> u.name;
        while(u.check){
        cout << "Inserisci numero prenotati: ";
            o2 >> u.prenotati;
            if(u.prenotati > 3){
                cout << "Numero prenotati non valido. Inserisci un numero inferiore o uguale a 3: ";
        }else{
            u.check = false;
        }
    }
    return o2;
}
    string getName() const {
        return name;
    }
    int getprenotati(){
        return prenotati; 
    }
    int gettornati(){
        return tornati; 
    }
};

int Utente::id=0;

class Bibliotecari : public Utente{
    private: 
    string biblioteca; 
    public:
    Bibliotecari (string n, int p, int t, bool ch, string b) : Utente(n, p, t, ch) , biblioteca(b) {}
    friend ostream& operator<<(ostream& os, Bibliotecari &b) {
        os << "Nome: " << b.getName() << endl ;
        os << "Biblioteca: " << b.biblioteca << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Bibliotecari &b){
        cout << "Inserisci nome: ";
        is >> b.Utente::name;
        cout << "Inserisci nome biblioteca: ";
        is >> b.biblioteca;
        return is;
    }
    void visualizzaPrenotati(Utente& u) const {
    cout << "L'utente " << u.getName() << " ha prenotato " << u.getprenotati() << " libri." << endl;
    }
};
class Libri{
    private:
    string titolo;
    int pages;
    string author;
    public:
    Libri (string t, int p, string a) : titolo(t), pages(p), author(a) {}
    friend ostream& operator<<(ostream& o, const Libri &l){
        cout << "Titolo: " << l.titolo << ", Pagine: " << l.pages << ", Autore: " << l.author << endl;
        return o;
    }
    friend istream& operator>>(istream& o2, Libri &l){
        cout << "Inserisci titolo: ";
        o2 >> l.titolo;
        cout << "Inserisci numero di pagine: ";
        o2 >> l.pages;
        cout << "Inserisci autore: ";
        o2 >> l.author;
        return o2;
    }
};
int main(){
    Utente u("", 0, 0, true);
    Bibliotecari b( "", 0, 0, true, "bibliotecari");
    Libri lib("",0,"" );
    cin >> u;
    cout << u << endl;
    cin >> lib;
    cout << lib << endl;
    cin >> b;
    cout << b << endl;
    b.visualizzaPrenotati(u);
    return 0;
}