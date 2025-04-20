#include <iostream>
#include <string>

using namespace std;

class Libri{
    private:
    string name;
    Libri (string n){
        name = n;
    }
    public:
}

class Lend : public Libri{
    private:
    char prest;
    Lend (char p): Libri(name) name(n), prest(p) {}
    public:
    getprest(){ return prest;}
    if (getprest()== 'p'){
        cout << "Book is present to lend" << endl;
    }else{
        cout << "Book is not present to lend" << end;
    }
}

int main (){
    Libro first_book()
}