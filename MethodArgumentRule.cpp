#include<iostream>
#include<string>
using namespace std;

// Method ArgumentRule class definition
// This class checks if a method argument is valid based on certain rules
// and provides a way to validate method arguments.
// It includes a method to check if the argument is not empty and does not exceed a certain length.
// The class also includes a method to display the validation result.

class Parent{
        public:
        virtual void print(string msg){
            cout << "Parent: " << msg << endl;
        }
};

class Child : public Parent{
    public:
    void print(string msg) override{
        cout << "Child: " << msg << endl;
    }
};

class client{
    private:
        Parent* p;
    public:
        client(Parent* p){
            this->p = p;
        }
        void display(string msg){
            p->print(msg);
        }
};

int main(){
    Parent* p = new Child();
    client c(p);

    c.display("Hello, World!");
    delete p;
}
