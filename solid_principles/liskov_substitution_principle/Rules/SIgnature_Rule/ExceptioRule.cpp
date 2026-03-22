#include<iostream>
#include<string>
#include<vector>

using namespace std;

//ExceptionRule class definition
//This class demonstrates exception handling in C++ with inheritance and polymorphism.
//A subclass should throw fewer or narrower exceptions than its superclass. or the same exceptions.
// but not additional exceptions. or broader exceptions.
// c++ does not enforce this rule at compile time, but it's a good practice to follow.


/*
===============================
 C++ Standard Exception Hierarchy
===============================

1. Base Class
   └── std::exception
         |
         ├── what() (virtual) → returns const char* with description

2. Logic Errors (compile-time / programmer mistakes)
   └── std::logic_error
         ├── std::invalid_argument       // e.g. invalid function parameter
         ├── std::domain_error           // e.g. domain math error (sqrt(-1))
         ├── std::length_error           // e.g. container too big
         ├── std::out_of_range           // e.g. accessing beyond container bounds

3. Runtime Errors (errors that can only be detected at runtime)
   └── std::runtime_error
         ├── std::range_error            // result out of valid range
         ├── std::overflow_error         // arithmetic overflow
         ├── std::underflow_error        // arithmetic underflow

4. Memory / Allocation Errors
   ├── std::bad_alloc                    // thrown by new if memory allocation fails
   └── std::bad_array_new_length         // invalid length in array allocation

5. Type Casting Errors
   ├── std::bad_cast                     // thrown by dynamic_cast for invalid cast
   ├── std::bad_typeid                   // using typeid on nullptr
   └── std::bad_function_call            // calling empty std::function

6. Other Exceptions
   ├── std::bad_exception                // thrown if unexpected exception type is thrown
   └── std::ios_base::failure            // I/O stream errors (file, console, etc.)

===============================
*/


class Parent{
    public: 
    virtual void getValue() noexcept(false){
        cout << "Parent: getValue()" << endl;
        throw logic_error("Parent Exception: Invalid argument in getValue");
    }
};

class Child : public Parent{
    public:
    // Overriding getValue() to throw a narrower exception (valid practice)
    void getValue() noexcept(false) override{
        cout << "Child: getValue()" << endl;
        throw invalid_argument("Child Exception: Invalid argument in getValue");
    }
};

class Client{
    private:
        Parent* p;
    public:
        Client(Parent* p){
            this->p = p;
        }
        void display(){
            try{
                p->getValue();
            }catch(const invalid_argument& e){
                cout << "Caught in Client: " << e.what() << endl;
            }catch(const logic_error& e){
                cout << "Caught in Client: " << e.what() << endl;
            }catch(const exception& e){
                cout << "Caught in Client: " << e.what() << endl;
            }
        }
};

int main(){
    Parent* p = new Child();
    Client c(p);

    c.display();
    delete p;
}