#include<iostream>
#include<string>
using namespace std;

class Parent{
        public:
        virtual void print(string msg){
            cout << "Parent: " << msg << endl;
        }
};

// This is a violation of the method argument rule
// because the child class is overriding the parent class method with a different argument type
// which is not allowed according to the LSP.
// class Child1 : public Parent{
//     public:
//     void print(int msg) override{
//         cout << "Child: " << msg << endl;
//     }
// };

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
