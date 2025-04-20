#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Books;
class Fiction ;
class NonFiction;
void transfer(Fiction& f, NonFiction& n);

class Books{
    private:
    string title;
    string author;
    string ISBN;
    public: 
    friend void transfer(Fiction& f, NonFiction& n);
    Books(string title, string author, string ISBN): title(title), author(author), ISBN(ISBN){}
    void printDetails(Books& books) {
        cout << "The book title: "<<books.title << ", " <<"The book author: "<< books.author << "The book ISBN code: "<< books.ISBN << endl;
    }
};

class Fiction : public Books{
    private : 
    string genre; 
    public: 
    Fiction(string genre, string title, string author, string ISBN): genre(genre), Books(title, author, ISBN){}
    void printDetails2(Fiction& f) {
        f.printDetails(f) ;
        cout << f.genre << endl;
}
    string getGenre() { return genre; }
    void setGenre(string newgenre) { genre = newgenre;}
};

class NonFiction : public Books{
    private : 
    string subject;
    public: 
    NonFiction(string subject, string title, string author, string ISBN) : subject(subject), Books(title, author, ISBN){}
    void printDetails3(NonFiction& n){
        n.printDetails(n); 
        cout << n.subject << endl;
    }
    string getSubject(){
        return subject;
    }
    void setSubject (string newsubject){subject = newsubject;}
};

void transfer(Fiction& f, NonFiction& n){
    char choice; 
    string temp;
    string temp2;
    cout << "What book do you want to transfer? " << endl;
    cout << "Press f for transfering fiction to non-fiction and press n for transfering nonfiction to fiction: " << endl;
    cin >> choice;
    if (choice == 'f'){
        temp = f.getGenre();
        temp2= n.getSubject();
        f.setGenre(temp2);
        n.setSubject(temp);
    }else if (choice == 'n'){
        temp= n.getSubject();
        temp2= f.getGenre();
        n.setSubject(temp2);
        f.setGenre(temp);
    }else{
        cout << "ERROR!!" << endl;
    }
};

int main(){
    Fiction f("Fantasy", "Games Of Thrones", "IDK", "HDI2K");
    NonFiction n("Science", "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "HDI123");
    f.printDetails2(f);
    n.printDetails3(n);
    transfer(f, n);
    f.printDetails2(f);
    n.printDetails3(n);
    return 0;
}