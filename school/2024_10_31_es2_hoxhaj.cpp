#include <iostream>
using namespace std;
class Treno {
    private:
    int numVagoni;
    int maxViaggiatoriPerVagone;
    int numViaggiatori[5];
    public:
    Treno(int numVagoni, int maxViaggiatoriPerVagone) {
        this->numVagoni = numVagoni;
        this->maxViaggiatoriPerVagone = maxViaggiatoriPerVagone;
    }
    void aggiungiViaggiatori(int numViaggiatori, int posizione) {
        if (posizione >= 0 && posizione < 5) {
            this->numViaggiatori[posizione] += numViaggiatori;
        }
    }
    void stampaTotaleViaggiatori() {
        int totale = 0;
        for (int i = 0; i < 5; i++) {
            totale += numViaggiatori[i];
        }
        cout << "Numero totale di viaggiatori: " << totale << endl;
    }
    void stampaMediaViaggiatori() {
        int totale = 0;
        for (int i = 0; i < 5; i++) {
            totale += numViaggiatori[i];
        }
    }
};
int main() {
    int numVagoni, maxViaggiatoriPerVagone;
    cout << "Inserisci il numero di vagoni: ";
    cin >> numVagoni;
    cout << "Inserisci il numero massimo di viaggiatori per vagone: ";
    cin >> maxViaggiatoriPerVagone;
    Treno treno(numVagoni, maxViaggiatoriPerVagone);
    for (int i = 0; i < 5; i++) {
        int numViaggiatori;
        cout << "Inserisci il numero di viaggiatori per la " << (i + 1) << "ª volta: ";
        cin >> numViaggiatori;
        treno.aggiungiViaggiatori(numViaggiatori, i);
    }
    treno.stampaTotaleViaggiatori();
}