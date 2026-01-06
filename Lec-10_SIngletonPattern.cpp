//Problem Statement:
//Singleton Pattern is a design pattern that ensures a class has only one instance and provides a global point of access to it.
//It is used to control the instantiation of a class and ensure that only one instance of the class is created.

#include <iostream>
#include <mutex>
using namespace std;

// // Problem: This is NOT a singleton pattern
// class SingletonProblem{
//     public:
//     SingletonProblem(){
//         cout << "Singleton constructor called" << endl;
//     }
// };

// int main(){
//     // This is not a singleton pattern because we are able to create two different objects
//     //Both s1 and s2 are pointing to two different memory addresses in heap memory.
//     SingletonProblem* s1 = new SingletonProblem();
//     SingletonProblem* s2 = new SingletonProblem();
    
// //  This will print "s1 and s2 are different objects" because s1 and s2 are two different references in stack memory
// //  pointing to two different memory addresses in heap memory.
//     cout<< (s1==s2)<<endl;
//     return 0;
// }

// Solution:

// class Singleton{
//     private:
//     static Singleton *instance;
//     Singleton(){
//         cout << "Singleton constructor called" << endl;
//     }

//     public:
//     static Singleton* getInstance(){
//         if(instance == nullptr){
//             instance = new Singleton();
//         }
//         return instance;
//     }
// };

// Singleton* Singleton::instance = nullptr;

// int main(){
//     // Problem demonstration (commented out - uncomment to see the problem)
//     /*
//     SingletonProblem* s1 = new SingletonProblem();
//     SingletonProblem* s2 = new SingletonProblem();
//     cout << ((s1==s2) ? "s1 and s2 are the same object" : "s1 and s2 are different objects") << endl;
//     */
    
//     // Solution: Singleton Pattern
//     cout << "Creating first instance:" << endl;
//     Singleton* s1 = Singleton::getInstance();
    
//     cout << "Creating second instance:" << endl;
//     Singleton* s2 = Singleton::getInstance();
    
//     cout << ((s1==s2) ? "s1 and s2 are the same object" : "s1 and s2 are different objects") << endl;
    
//     return 0;
// }


// Thread Safe Singleton Pattern:

// class Singleton{
//     private:
//     static Singleton *instance;
//     static mutex mtx;
//     Singleton(){
//         cout << "Singleton constructor called" << endl;
//     }

//     public:
//     static Singleton* getInstance(){
//         if(instance == nullptr){
//             lock_guard<mutex> lock(mtx);
//             if(instance == nullptr){
//                 instance = new Singleton();
//             }
//         }
//         return instance;
//     }
// };

// Singleton* Singleton::instance = nullptr;
// mutex Singleton::mtx;

// int main(){
//     Singleton* s1 = Singleton::getInstance();
//     Singleton* s2 = Singleton::getInstance();
//     cout << ((s1==s2) ? "s1 and s2 are the same object" : "s1 and s2 are different objects") << endl;
//     return 0;
// }

//  eager initialization

class Singleton{
    private:
    static Singleton *instance;
    Singleton(){
        cout << "Singleton constructor called" << endl;
    }

    public:
    static Singleton* getInstance(){
        return instance;
    }
};

Singleton* Singleton::instance = new Singleton();

int main(){
    cout << "Creating first instance:" << endl;
    Singleton* s1 = Singleton::getInstance();
    
    cout << "Creating second instance:" << endl;
    Singleton* s2 = Singleton::getInstance();
    
    cout << ((s1==s2) ? "s1 and s2 are the same object" : "s1 and s2 are different objects") << endl;
    
    return 0;
}