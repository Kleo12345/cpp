#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

class Acquisto{
    private:
    string codice;
    int nr;
    double prezzo_tot;
    public:
    Acquisto(string codice, int n, double prezzo_tot){
        codice = "";
        nr = 0;
        prezzo_tot = 0.0;
    }
    double get_price(){
        return prezzo_tot;
    }
};
class cassa{
    private:
    double balance;
    vector <Acquisto> memory;
    double initial_balance;
    bool fondo_cassa;
    public:
    cassa(double initial_balance, bool fondo_cassa){
        initial_balance = 0.0;
        fondo_cassa = false;
    }
    void aggiungi_prodotto(Acquisto a){
        memory.push_back(a);
        balance += a.get_price();
    }
    double close (){
        double result = balance-initial_balance;
        double sum =0;
        for (int i = 0; i < result; i ++){
            sum += memory[i].get_price();
        }
        if (sum!=result){
            cout << "Error: Total price of products does not match balance" << endl;
            return -1; 
        }
        cout << "Your net profit is:" << result << endl;
        balance = 0.0;
        for(int i = 0; i < memory.size(); i ++){
            memory.pop_back();
        }
        return result;
    }
};

int main(){
    cassa c(100.0, true);
    Acquisto a1("A123", 2, 10.0);
    Acquisto a2("B456", 1, 20.0);
    c.aggiungi_prodotto(a1);
    c.aggiungi_prodotto(a2);
    c.close();
    return 0;
}