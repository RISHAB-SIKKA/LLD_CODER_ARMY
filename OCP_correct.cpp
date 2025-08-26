#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string n, double p) : name(n), price(p) {}
};

// shoppingCart only handles cart operations
class shoppingCart {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    const vector<Product>& getProducts() const {
        return products;
    }

    double calculateTotalPrice() const {
        double total = 0;
        for (const auto& product : products) {
            total += product.price;
        }
        return total;
    }
};

// Handles printing invoices
class shoppingCartPrinter {
private:
    shoppingCart& cart;

public:
    shoppingCartPrinter(shoppingCart& c) : cart(c) {}

    void printInvoice() {
        cout << "Invoice:" << endl;
        for (const auto& product : cart.getProducts()) {
            cout << product.name << " - $" << product.price << endl;
        }
        cout << "Total: $" << cart.calculateTotalPrice() << endl;
    }
};

// Persisters only care about saving cart
class DbPersister {
public:
    virtual void save(shoppingCart* c) = 0;
    virtual ~DbPersister() = default; // ✅ virtual destructor
};

class SQLDbPersister : public DbPersister {
public:
    void save(shoppingCart* c) override {
        cout << "Saving shopping cart to SQL Database." << endl;
    }
};

class MongoDbPersister : public DbPersister {
public:
    void save(shoppingCart* c) override {
        cout << "Saving shopping cart to MongoDB." << endl;
    }
};

class FilePersister : public DbPersister {
public:
    void save(shoppingCart* c) override {
        cout << "Saving shopping cart to File." << endl;
    }
};

int main() {
    // Use smart pointer
    auto cart = make_unique<shoppingCart>();

    cart->addProduct(Product("Laptop", 999.99));
    cart->addProduct(Product("Mouse", 49.99));

    shoppingCartPrinter printer(*cart);
    printer.printInvoice();

    // Polymorphism via smart pointers
    unique_ptr<DbPersister> sqlPersister = make_unique<SQLDbPersister>();
    unique_ptr<DbPersister> mongoPersister = make_unique<MongoDbPersister>();
    unique_ptr<DbPersister> filePersister = make_unique<FilePersister>();

    sqlPersister->save(cart.get());
    mongoPersister->save(cart.get());
    filePersister->save(cart.get());

    return 0; // no delete needed, smart pointers clean up
}
