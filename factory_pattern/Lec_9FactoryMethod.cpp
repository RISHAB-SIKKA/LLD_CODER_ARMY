#include<bits/stdc++.h>

using namespace std;

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

class WheatBasicBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Wheat Basic Burger" << endl;
    }
};

class WheatStandardBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Wheat Standard Burger" << endl;
    }
};

class WheatPremiumBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Wheat Premium Burger" << endl;
    }
};

class BurgerFactory{
    public:
    virtual Burger* createBurger(string type) = 0;
    virtual ~BurgerFactory() = default;
};

class BasicBurgerFactory : public BurgerFactory{
    public:
    Burger* createBurger(string type) override{
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

class WheatBurgerFactory : public BurgerFactory{
    public:
    Burger* createBurger(string type) override{
        if(type == "Basic"){
            return new WheatBasicBurger();
        }
        else if(type == "Standard"){
            return new WheatStandardBurger();
        }
        else if(type == "Premium"){
            return new WheatPremiumBurger();
        }
        else{
            throw invalid_argument("Invalid burger type");
        }
    }
};

int main(){
    BurgerFactory* burgerFactory = new BasicBurgerFactory();
    BurgerFactory* wheatBurgerFactory = new WheatBurgerFactory();

    Burger* burger = burgerFactory->createBurger("Basic");
    burger->prepare();
    delete burger;

    burger = burgerFactory->createBurger("Standard");
    burger->prepare();
    delete burger;
    
    burger = wheatBurgerFactory->createBurger("Basic");
    burger->prepare();
    delete burger;

    burger = wheatBurgerFactory->createBurger("Standard");
    burger->prepare();
    delete burger;

    delete burgerFactory;
    delete wheatBurgerFactory;

    return 0;
}