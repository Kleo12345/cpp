#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
private:
    string name;
    double price;
    int discount;
    static int count;

public:
    Product(string n, double p, int d) : name(n), price(p), discount(d) {
        count++;
    }

    double getprice() const {
        return price;
    }

    int getdiscount() const {
        return discount;
    }

    string getname() const {
        return name;
    }

    static int getCount() {
        return count;
    }

    friend ostream& operator<<(ostream& os, const Product& p) {
        os << "Product details:" << endl;
        os << "Name: " << p.name << endl;
        os << "Original price: " << p.price << endl;
        os << "Discount: " << p.discount << "%" << endl;
        os << "Price after discount: " << p.price * (1 - p.discount / 100.0) << endl;
        return os;
    }
};

int Product::count = 0;

double applieddiscount(double price, int discount) {
    return price * (1 - discount / 100.0);
}

class Tech : public Product {
private:
    int garanzia;

public:
    Tech(int gar, string n2, double p2, int d2) : garanzia(gar), Product(n2, p2, d2) {}

    friend ostream& operator<<(ostream& os, const Tech& t) {
        os << "Tech product details:" << endl;
        os << "Name: " << t.getname() << endl;
        os << "Original price: " << t.getprice() << endl;
        os << "Discount: " << t.getdiscount() << "%" << endl;
        os << "Warranty: " << t.garanzia << " months" << endl;
        os << "Price after discount: " << applieddiscount(t.getprice(), t.getdiscount()) << endl;
        return os;
    }
};

int main() {
    int category = 0;
    char yn;
    
    cout << "Is your product a tech product or a normal one?" << endl;
    cout << "Press 1 for tech or 0 for normal: ";
    cin >> category;

    cout << "Does your product have any discount?" << endl;
    cout << "Press y for yes, n for no: ";
    cin >> yn;

    if (category == 0) {
        if (yn == 'y') {
            Product p("Potato", 2.0, 20);
            cout << p;
        } else {
            Product p("Potato", 2.0, 0);
            cout << p;
        }
    } else {
        if (yn == 'y') {
            Tech p(24, "Mac", 22.0, 20);
            cout << p;
        } else {
            Tech p(24, "Mac", 22.0, 0);
            cout << p;
        }
    }

    cout << "Total products created: " << Product::getCount() << endl;

    return 0;
}
