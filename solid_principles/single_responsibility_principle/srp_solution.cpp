//Solution:c
#include<bits/stdc++.h>

using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string n, double p){
        this->name = n;
        this->price = p;
    }
};

class shoppingCart{
    public:
    vector<Product> products;

    void addProduct(const Product& product){
        products.push_back(product);
    }

    const vector<Product>& getProducts(){
        return products;
    }

    double calculateTotalPrice(){
        double total = 0;
        for(const auto& product : products){
            total += product.price;
        }
        return total;
    }

};

class shoppingCartPrinter{
    private:
    shoppingCart& cart;

    public:
    shoppingCartPrinter(shoppingCart& c) : cart(c) {}

    void printInvoice(){
        cout << "Invoice:" << endl;
        for(const auto& product : cart.getProducts()){
            cout << product.name << " - $" << product.price << endl;
        }
        cout << "Total: $" << cart.calculateTotalPrice() << endl;
    }
};

class shoppingCartDb{
    private:
    shoppingCart& cart;
    public:

    shoppingCartDb(shoppingCart& c) : cart(c) {}

    void saveToDb(){
        cout << "Saving invoice to database..." << endl;
    }
};

int main(){
    shoppingCart * cart = new shoppingCart();
    Product * p1 = new Product("Laptop", 999.99);
    Product * p2 = new Product("Mouse", 49.99);

    cart->addProduct(*p1);
    cart->addProduct(*p2);

    shoppingCartPrinter printer(*cart);
    printer.printInvoice();
    shoppingCartDb db(*cart);
    db.saveToDb();
    
    delete cart;
    delete p1;
    delete p2;
    return 0;

}