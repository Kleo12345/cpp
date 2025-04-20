#include <iostream> 
#include <vector>
#include <cctype>
#include <ctime>
#include <fstream>

using namespace std;

//Definire una struct data che memorizzi giorno, mese e anno.
//Leggere da un file input.txt 10 date di nascita (in ogni riga del file ci saranno giorno, mese e anno separati da spazi) far inserire all’utente la data odierna e verificare quante date di nascita corrispondono a maggiorenni.
struct Data {
    int giorno;
    int mese;
    int anno;
};

bool isMaggiorenne(const Data& data);
int getCurrentYear();


int main() {
    vector<Data> dateNascita;
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Impossibile aprire il file input.txt." << endl;
        return 1;
    }

    int numDateNascita;
    cout << "Inserisci il numero di date di nascita: ";
    cin >> numDateNascita;

    for (int i = 0; i < numDateNascita; ++i) {
        int giorno, mese, anno;
        cout << "Inserisci la data di nascita " << (i + 1) << " (gg/mm/aaaa): ";
        cin >> giorno >> mese >> anno;
        Data data = {giorno, mese, anno};
        dateNascita.push_back(data);
    }

    inputFile.close();
    int numMaggiorenni = 0;
    for (const auto& data : dateNascita) {
        if (isMaggiorenne(data)) {
            ++numMaggiorenni;
        }
    }

    cout << "Ci sono " << numMaggiorenni << " date di nascita maggiorenni." << endl;
    return 0;
}


bool isMaggiorenne(const Data& data) {
    int annoCorrente = getCurrentYear();
    return data.anno < annoCorrente;
}

int getCurrentYear() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    return 1900 + localTime->tm_year;
}
