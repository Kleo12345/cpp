#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product;
class ElectronicProduct;

double applyDiscount(Product& p);

class Product {
    protected:
        string name;
        double price;
        int quantity;
        static int count;
        vector<string> productsSold;
        int discountPercentage; 
        bool hasDiscount;

    public:
        Product(string n, double p, int q, int d, bool ch) : name(n), price(p), quantity(q), discountPercentage(d), hasDiscount(ch) {count++;}
        friend ostream& operator<<(ostream& os, const Product& p);
        friend double applyDiscount(Product& p);

        void sellProduct(int q) {
            if (q <= quantity) {
                quantity -= q;
                productsSold.push_back(name);
                cout << "Product sold successfully!" << endl;
            } else {
                cout << "Not enough quantity in stock!" << endl;
            }
        }

        static int getProductCount() {
            return count;
        }
    };

int Product::count = 0;

class ElectronicProduct : public Product {
    private:
        int warrantyPeriod;
    public:
        ElectronicProduct(string n, double p, int q, int d, bool ch, int w) : Product(n, p, q, d, ch), warrantyPeriod(w) {}
        friend ostream& operator<<(ostream& os, const ElectronicProduct& ep);
    };

double applyDiscount(Product& p) {
    if (p.hasDiscount) {
        return p.price * (1 - (p.discountPercentage / 100.0));
    }
    return p.price;
}

ostream& operator<<(ostream& os, const Product& p) {
    os << "Product Name: " << p.name;
    if (p.hasDiscount) {
        os << ", Price with Discount: " << applyDiscount(const_cast<Product&>(p));
    } else {
        os << ", Price: " << p.price;
    }
    os << ", Quantity: " << p.quantity;
    return os;
}

ostream& operator<<(ostream& os, const ElectronicProduct& ep) {
    os << static_cast<const Product&>(ep);
    os << ", Warranty: " << ep.warrantyPeriod << " months";
    return os;
}

int main() {
    ElectronicProduct ep("Phone", 1000, 5, 10, true, 24);
    cout << ep << endl;

    ep.sellProduct(3);
    cout << ep << endl;

    Product p("Laptop", 1500, 3, 0, false);
    p.sellProduct(2);
    cout << p << endl;

    cout << "Total number of products created: " << Product::getProductCount() << endl;

    return 0;
}
