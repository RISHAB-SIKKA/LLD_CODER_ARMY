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

class GarlicBread{
    public:
    virtual void prepare() =0;
    ~GarlicBread() = default;
};

class BasicGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout << "Preparing Basic Garlic Bread" << endl;
    }
};

class StandardGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout << "Preparing Standard Garlic Bread" << endl;
    }
};

class PremiumGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout << "Preparing Premium Garlic Bread" << endl;
    }
};

class WheatBasicGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout << "Preparing Wheat Basic Garlic Bread" << endl;
    }
};

class WheatStandardGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout << "Preparing Wheat Standard Garlic Bread" << endl;
    }
};

class WheatPremiumGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout << "Preparing Wheat Premium Garlic Bread" << endl;
    }
};

class BurgerFactory{
    public:
    virtual Burger* createBurger(string type) = 0;
    virtual GarlicBread* createGarlicBread(string type) = 0;
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
    GarlicBread* createGarlicBread(string type) override{
        if(type == "Basic"){
            return new BasicGarlicBread();
        }
        else if(type == "Standard"){
            return new StandardGarlicBread();
        }
        else if(type == "Premium"){
            return new PremiumGarlicBread();
        }
        else{
            throw invalid_argument("Invalid garlic bread type");
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
    GarlicBread* createGarlicBread(string type) override{
        if(type == "Basic"){
            return new WheatBasicGarlicBread();
        }
        else if(type == "Standard"){
            return new WheatStandardGarlicBread();
        }
        else if(type == "Premium"){
            return new WheatPremiumGarlicBread();
        }
        else{
            throw invalid_argument("Invalid garlic bread type");
        }
    }
};


int main(){
   BurgerFactory* nonwheatBurgerFactory =  new SinghBurgerFactory();
   BurgerFactory* wheatBurgerFactory =  new KingBurgerFactory();

   Burger* nonWheatBurger = nonwheatBurgerFactory->createBurger("Premium");
   GarlicBread* nonWheatGarlicBread = nonwheatBurgerFactory->createGarlicBread("Premium");
   nonWheatBurger->prepare();
   nonWheatGarlicBread->prepare();

   nonWheatBurger = nonwheatBurgerFactory->createBurger("Standard");
   nonWheatGarlicBread = nonwheatBurgerFactory->createGarlicBread("Standard");
   nonWheatBurger->prepare();
   nonWheatGarlicBread->prepare();

   nonWheatBurger = nonwheatBurgerFactory->createBurger("Basic");
   nonWheatGarlicBread = nonwheatBurgerFactory->createGarlicBread("Basic");
   nonWheatBurger->prepare();
   nonWheatGarlicBread->prepare();

   Burger* wheatBurger = wheatBurgerFactory->createBurger("Premium");
   GarlicBread* wheatGarlicBread = wheatBurgerFactory->createGarlicBread("Premium");
   wheatBurger->prepare();
   wheatGarlicBread->prepare();
    
   wheatBurger = wheatBurgerFactory->createBurger("Standard");
   wheatGarlicBread = wheatBurgerFactory->createGarlicBread("Standard");
   wheatBurger->prepare();
   wheatGarlicBread->prepare();

   wheatBurger = wheatBurgerFactory->createBurger("Basic");
   wheatGarlicBread = wheatBurgerFactory->createGarlicBread("Basic");
   wheatBurger->prepare();
   wheatGarlicBread->prepare();

   // Clean up memory
   delete nonWheatBurger;
   delete wheatBurger;
   delete nonWheatGarlicBread;
   delete wheatGarlicBread;
   delete nonwheatBurgerFactory;
   delete wheatBurgerFactory;

    return 0;
}