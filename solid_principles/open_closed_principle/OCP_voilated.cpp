#include<bits/stdc++.h>

using namespace std;

class Product{
    private:
    string name;
    double price;

    public:
    Product(string n, double p) : name(n), price(p) {}

    const string& getName() const { return name; }
    double getPrice() const { return price; }
};

class shoppingCart{
    private:
    vector<Product> products;

    public:
    void addProduct(const Product& product){
        products.push_back(product);
    }
    const vector<Product>& getProducts(){
        return products;
    }
};

class shopingCartCalculator{
    private:
    shoppingCart& cart;

    public:
    shopingCartCalculator(shoppingCart& c) : cart(c) {}

    double calculateTotalPrice(){
        double total = 0;
        for(const auto &product : cart.getProducts()){
            total += product.getPrice();
        }
        return total;
    }
};

class shoopingCartInvoice{
    private:
    shoppingCart& cart;

    public:
    shoopingCartInvoice(shoppingCart& c) : cart(c) {}

    void printInvoice(){
        cout << "Invoice:" << endl;
        for(const auto& product : cart.getProducts()){
            cout << product.getName() << " - $" << product.getPrice() << endl;
        }
        shopingCartCalculator calc(cart);
        cout << "Total: $" << calc.calculateTotalPrice() << endl;
    }
};

class shoppingCartDb{
    private:
    shoppingCart& cart;

    public:
    shoppingCartDb(shoppingCart& c) : cart(c) {}

    // now this violates the open closed principle because we are adding new functionality to the class without modifying it.
    // so we need to modify the class to add new functionality without modifying it.
    void saveToDb(){
        cout << "Saving shopping cart to database..." << endl;
    }

    void saveToFile(){
        cout << "Saving shopping cart to file..." << endl;
    }

    void saveToMongoDb(){
        cout << "Saving shopping cart to MongoDB..." << endl;
    }

    void saveToSqlDb(){
        cout << "Saving shopping cart to SQL Database..." << endl;
    }
    
};

int main(){
    shoppingCart* cart = new shoppingCart();
    Product* p1 = new Product("Laptop", 999.99);
    Product* p2 = new Product("Mouse", 49.99);

    cart->addProduct(*p1);
    cart->addProduct(*p2);

    shopingCartCalculator calculator(*cart);
    cout << "Total price: " << calculator.calculateTotalPrice() << endl;

    shoopingCartInvoice invoice(*cart);
    invoice.printInvoice();

    shoppingCartDb db(*cart);
    db.saveToDb();
    db.saveToFile();
    db.saveToMongoDb();
    db.saveToSqlDb();

    delete cart;
    delete p1;
    delete p2;
    return 0;
}