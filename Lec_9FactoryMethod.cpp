#include<iostream>
#include<string>
#include<stdexcept>
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

class BasicWheatBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};

class StandardWheatBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};

class PremiumWheatBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

class BurgerFactory{
    public:
    virtual Burger* createBurger(string type) = 0;
    virtual ~BurgerFactory() = default;
};

class SinghBurgerFactory : public BurgerFactory{
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

class KingBurgerFactory : public BurgerFactory{
    public:
    Burger* createBurger(string type) override{
        if(type == "Basic"){
            return new BasicWheatBurger();
        }
        else if(type == "Standard"){
            return new StandardWheatBurger();
        }
        else if(type == "Premium"){
            return new PremiumWheatBurger();
        }
        else{
            throw invalid_argument("Invalid burger type");
        }
    }
};


int main(){
   BurgerFactory* nonwheatBurgerFactory =  new SinghBurgerFactory();
   BurgerFactory* wheatBurgerFactory =  new KingBurgerFactory();

   Burger* nonWheatBurger = nonwheatBurgerFactory->createBurger("Premium");
   nonWheatBurger->prepare();

   nonWheatBurger = nonwheatBurgerFactory->createBurger("Standard");
   nonWheatBurger->prepare();

   nonWheatBurger = nonwheatBurgerFactory->createBurger("Basic");
   nonWheatBurger->prepare();

   Burger* wheatBurger = wheatBurgerFactory->createBurger("Premium");
   wheatBurger->prepare();
   
   wheatBurger = wheatBurgerFactory->createBurger("Standard");
   wheatBurger->prepare();

   wheatBurger = wheatBurgerFactory->createBurger("Basic");
   wheatBurger->prepare();

   // Clean up memory
   delete nonWheatBurger;
   delete wheatBurger;
   delete nonwheatBurgerFactory;
   delete wheatBurgerFactory;

    return 0;
}