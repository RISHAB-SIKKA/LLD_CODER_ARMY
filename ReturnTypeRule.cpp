#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Animal {
public:
    virtual ~Animal() = default; // important for polymorphic delete
};

class Dog : public Animal {

};

class Parent {
public:
    virtual ~Parent() = default;

    // Base version returns Animal*
    virtual Animal* getAnimal() {
        cout << "Parent: getAnimal()" << endl;
        return new Animal(); // caller responsible for delete
    }
};

class Child : public Parent {
public:
    // 🔑 Covariant Return Type:
    // Here we override getAnimal(), but instead of returning Animal*,
    // we return Dog* (a derived type). This is allowed in C++ and is
    // called covariance.
    Dog* getAnimal() override {
        cout << "Child: getAnimal()" << endl;
        return new Dog();
    }
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) : p(p) {}

    void display() {
        Animal* a = p->getAnimal();
        // Do something with a...
        delete a; // ✅ free the returned object
    }
};

int main() {
    Parent* c = new Child();   // Using Parent* to Child (polymorphism)
    Client client(c);

    client.display();

    delete c; // ✅ safe because Parent has virtual destructor
    return 0;
}
