#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

/*
 * SIMPLE FACTORY PATTERN
 * 
 * The Simple Factory Pattern is a creational design pattern that provides 
 * a centralized way to create objects without exposing the instantiation logic 
 * to the client. It encapsulates object creation in a single factory class.
 * 
 * Benefits:
 * - Centralizes object creation logic
 * - Reduces coupling between client and concrete classes
 * - Makes code easier to maintain and extend
 */

// Abstract base class (Product Interface)
// Defines the interface that all burger types must implement
class Burger{
    public:
    virtual void prepare() = 0;  // Pure virtual function - must be implemented by derived classes
    virtual ~Burger() = default; // Virtual destructor for proper cleanup
};

// Concrete Product Classes
// These are the actual burger types that implement the Burger interface

class BasicBurger: public Burger{
    public: 
    void prepare() override{
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandardBurger: public Burger{
    public:
    void prepare() override{
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger: public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Premium Burger" << endl;
    }
};

// Factory Class (Simple Factory)
// This class encapsulates the object creation logic
// Client code doesn't need to know about concrete burger classes
class BurgerFactory{
    public:
    // Factory method that creates and returns appropriate burger based on type
    // Returns a pointer to Burger (base class) - demonstrates polymorphism
    Burger* createBurger(string type){
        if(type == "Basic"){
            return new BasicBurger();
        }
        else if(type == "Standard"){
            return new StandardBurger();
        }
        else if(type == "Premium"){
            return new PremiumBurger();
        }
        else{
            // Handle invalid burger type
            throw invalid_argument("Invalid burger type");
        }
    }
};

// Client Code
// Demonstrates how to use the Simple Factory pattern
int main (){
    // Create factory instance
    BurgerFactory* burgerFactory = new BurgerFactory();
    
    // Create different types of burgers using the factory
    // Client doesn't need to know about concrete classes (BasicBurger, StandardBurger, etc.)
    
    // Create and prepare Basic Burger
    Burger* burger = burgerFactory->createBurger("Basic");
    burger->prepare();
    delete burger;
    
    // Create and prepare Standard Burger
    burger = burgerFactory->createBurger("Standard");
    burger->prepare();
    delete burger;
    
    // Create and prepare Premium Burger
    burger = burgerFactory->createBurger("Premium");
    burger->prepare();
    delete burger;
    
    // Clean up factory
    delete burgerFactory;

    return 0;
}



