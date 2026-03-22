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

    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class BasicBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandardBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Premium Burger" << endl;
    }
};

class BurgerFactory{
    public:
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
            throw invalid_argument("Invalid burger type");
        }
    }
};

int main(){
    BurgerFactory factory;
    Burger* burger = factory.createBurger("Basic");
    burger->prepare();
    delete burger;
    return 0;
}
