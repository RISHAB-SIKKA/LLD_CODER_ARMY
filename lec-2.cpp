// Abstraction in C++ 
// is a fundamental concept that allows you to define interfaces and implement them in derived classes. This enables you to create flexible and reusable code. Below is an example of how to implement abstraction using an abstract class and a derived class in C++.

// #include<iostream>
// #include<string>

// using namespace std;

// class Car {
//     public:
//     virtual void startEngine() = 0;
//     virtual void shiftGear() = 0;
//     virtual void accelerate() = 0;
//     virtual void brake() = 0;
//     virtual void stopEngine() = 0;
//     virtual ~Car() {}
// };

// class sportsCar : public Car {
// public:
//     string brand;
//     string model;
//     bool isEngineOn;
//     int currentSpeed;
//     int currentGear;

//     sportsCar(string b, string m){
//         this -> brand = b;
//         this -> model = m;
//         this -> isEngineOn = false;
//         this -> currentSpeed = 0;
//         this -> currentGear = 0;
//     }

//     void startEngine() override {
//         isEngineOn = true;
//         cout << "Engine started for " << brand << " " << model << endl;
//     }

//     void shiftGear() override {
//         if (isEngineOn) {
//             currentGear++;
//             cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
//         } else {
//             cout << "Cannot shift gear, engine is off." << endl;
//         }
//     }

//     void accelerate() override {
//         if(!isEngineOn){
//             cout << "Cannot accelerate, engine is off." << endl;
//             return;
//         }   
//         currentSpeed += 10;
//         cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h" << endl;
//     }

//     void brake() override {
//         if (currentSpeed > 0) {
//             currentSpeed -= 10;
//             cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << " km/h" << endl;
//         } else {
//             cout << brand << " " << model << " is already stopped." << endl;
//         }
//     }

//     void stopEngine() override {
//         if (currentSpeed > 0) {
//             cout << "Cannot stop engine while " << brand << " " << model << " is moving." << endl;
//         } else {
//             isEngineOn = false;
//             currentGear = 0;
//             cout << "Engine stopped for " << brand << " " << model << endl;
//         }
//     }
//     ~sportsCar() {
//         cout << "Destroying " << brand << " " << model << endl;
//     }
// };

// int main(){
//     Car* myCar = new sportsCar("Porsche", "911");
    
//     myCar->startEngine();
//     myCar->shiftGear();
//     myCar->accelerate();
//     myCar->brake();
//     myCar->stopEngine();

//     delete myCar; // Clean up memory
//     return 0;
// }

// Encapsulation in C++    
// is a fundamental concept that allows you to bundle data and methods that operate on that data within a single unit, typically a class. This helps to restrict direct access to some of the object's components, which can prevent the accidental modification of data. Below is an example of how to implement encapsulation in C++ using a class that represents a car.

#include<iostream>
#include<string>

using namespace std;

class sportsCar {
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre = "MRF";

public:
    sportsCar(string b, string m){
        this -> brand = b;
        this -> model = m;
        this -> isEngineOn = false;
        this -> currentSpeed = 0;
        this -> currentGear = 0;    
    }

    // Getter methods to access private members
    int getCurrentSpeed() const {
        return currentSpeed;
    }

    string getTyre () {
        return tyre;
    }

    // Setter methods to modify private members
    void setTyre(string newTyre) {
        tyre = newTyre;
    }

    void startEngine() {
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void shiftGear() {
        if (isEngineOn) {
            currentGear++;
            cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
        } else {
            cout << "Cannot shift gear, engine is off." << endl;
        }
    }

    void accelerate() {
        if(!isEngineOn){
            cout << "Cannot accelerate, engine is off." << endl;
            return;
        }   
        currentSpeed += 10;
        cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        if (currentSpeed > 0) {
            currentSpeed -= 10;
            cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }

    void stopEngine() {
        if (currentSpeed > 0) {
            cout << "Cannot stop engine while " << brand << " " << model << " is moving." << endl;
        } else {
            isEngineOn = false;
            currentGear = 0;
            cout << "Engine stopped for " << brand << " " << model << endl;
        }
    }
    ~sportsCar() {
        cout << "Destroying " << brand << " " << model << endl;
    }
};

int main(){
    sportsCar* myCar = new sportsCar("Porsche", "911");
    
    myCar->startEngine();
    myCar->shiftGear();
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();


    // myCar->currentSpeed = 500; // This line will not compile because currentSpeed is private
    cout << "Current speed of " << myCar->getCurrentSpeed() << " km/h" << endl;

    cout << "Tyre brand: " << myCar->getTyre() << endl;
    myCar->setTyre("Bridgestone");  
    cout << "New tyre brand: " << myCar->getTyre() << endl;

    delete myCar; // Clean up memory
    return 0;
}