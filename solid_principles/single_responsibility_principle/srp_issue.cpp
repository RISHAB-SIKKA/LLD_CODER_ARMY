#include<iostream>
#include<string>
#include<vector>

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
    private:
    vector<Product> products;

    public:
    void addProducts(const Product& product){
        products.push_back(product);
    }

    const vector<Product>& getProducts(){
        return products;
    }

    double calculatePrice(){
        double total = 0;
        for(auto &product: products){
            total += product.price;
        }
        return total;
    }

    void printInvoice(){
        cout << "Invoice:" << endl;
        for(auto &product: products){
            cout << product.name << " - $" << product.price << endl;
        }
        cout << "Total: $" << calculatePrice() << endl;
    }

    void saveToDb(){
        cout << "Saving invoice to database..." << endl;
        // Database saving logic
    }
};

int main(){
    Product* p1 = new Product("Laptop", 1000);
    Product* p2 = new Product("Mouse", 100);

    cout << "Product 1: " << p1->name << " - $" << p1->price << endl;
    cout << "Product 2: " << p2->name << " - $" << p2->price << endl;

    shoppingCart* cart = new shoppingCart();

    cart->addProducts(*p1);
    cart->addProducts(*p2);
    cart->getProducts();
    cart->calculatePrice();
    cout << "Total: $" << cart->calculatePrice() << endl;
    cart->printInvoice();
    cart->saveToDb();


    delete p1;
    delete p2;
    delete cart;

    return 0;
}