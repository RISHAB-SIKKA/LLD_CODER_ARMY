// #include<iostream>
// #include<string>
// // #include<bits/stdc++.h>
// #include<vector>

// using namespace std;

// class Product{
//     string name;
//     double price;

//     public:
//     Product(string n, double p){
//         this -> name = n;
//         this -> price = p;
//     }
// };

// // violation of single responsibility principle
// // single class handling multiple responsibilities
// class shoppingCart{
//     private:
//     vector<Product> products;

//     public:
//     void addProduct(const Product& product){
//         products.push_back(product);
//     }

//     const vector<Product*>& getProducts(){
//         return Products;
//     }

//     double calculateTotalPrice(){
//         double total = 0;
//         for(const auto& product : products){
//             total += product.price;
//         }
//         return total;
//     }

//     void printInovice(){
//         cout << "Invoice:" << endl;
//         for(const auto& product : products){
//             cout << product.name << " - $" << product.price << endl;
//         }
//         cout << "Total: $" << calculateTotalPrice() << endl;
//     }

//     void saveToDb(){
//         cout<<"Saving invoice to database..." << endl;
//         // Database saving logic
//     }
// };

// int main(){
//     shoppingCart* cart = new shoppingCart();

//     Product* p1 = new Product("Laptop", 999.99);
//     Product* p2 = new Product("Mouse", 49.99);

//     cart->addProduct(*p1);
//     cart->addProduct(*p2);
//     cart->printInovice();
//     cart->saveToDb();
    
//     delete cart;
// }



// Solution: 

#include<iostream>
#include<string>
// #include<bits/stdc++.h>
#include<vector>

using namespace std;

class Product{
    public:
    string name;
    double price;

    public:
    Product(string n, double p){
        this -> name = n;
        this -> price = p;
    }
};

// Every class should have a single responsibility
// shoppingCart class only handles cart related operations
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
    shoppingCartPrinter(shoppingCart& c){
        this -> cart = c;
    }

    void printInovice(){
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
    shoppingCartDb(shoppingCart& c){
        this -> cart = c;
    }

    void saveToDb(){
        cout<<"Saving invoice to database..." << endl;
        // Database saving logic
    }
};

int main(){
    shoppingCart* cart = new shoppingCart();

    Product* p1 = new Product("Laptop", 999.99);
    Product* p2 = new Product("Mouse", 49.99);

    cart->addProduct(*p1);
    cart->addProduct(*p2);
   
    shoppingCartPrinter printer(*cart);
    printer.printInovice(); 
    shoppingCartDb db(*cart);
    db.saveToDb();
    
    delete cart;
}