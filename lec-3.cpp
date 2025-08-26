// Inheritance with access modifiers

#include<iostream>
#include<string>
using namespace std;

// class Car {
//     protected:
//     string brand;
//     string model;
//     bool isEngineOn;
//     int currentSpeed;

//     public: 
//     // Cobstructor
//     Car(string b, string m){
//         this -> brand = b;
//         this -> model = m;
//         this -> isEngineOn = false;
//         this -> currentSpeed = 0;  
//     }

//     // Common methods 
//     void startEngine() {
//         isEngineOn = true;
//         cout << "Engine started for " << brand << " " << model << endl;
//     }

//     void stopEngine() {
//         isEngineOn = false;
//         currentSpeed = 0;
//         cout << "Engine stopped for " << brand << " " << model << endl;
//     }

//     void accelerate() {
//         if(!isEngineOn){
//             cout << "Cannot accelerate, engine is off." << endl;
//             return;
//         }   
//         currentSpeed += 10;
//         cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h" << endl;
//     }

//     void brake() {
//         if (currentSpeed > 0) {
//             currentSpeed -= 10;
//             cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << " km/h" << endl;
//         } else {
//             cout << brand << " " << model << " is already stopped." << endl;
//         }
//     }

//     // destructor
//     ~Car(){
//         cout << "Car " << brand << " " << model << " is being destroyed." << endl;
//     }

// };

// class manualCar : public Car {
//     private:
//     int currentGear;

//     public:
//     manualCar(string b, string m) : Car(b,m){
//         this -> currentGear = 0;    
//     }

//     void shiftGear(){
//         if(!isEngineOn){
//             cout << "Cannot shift gear, engine is off." << endl;
//             return;
//         }
//         currentGear++;
//         cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
//     }
// };

// class electricCar : public Car {
//     private:
//      int batteryLevel; // Battery level percentage

//      public: 
//      electricCar(string b, string m) : Car(b,m){
//         this -> batteryLevel = 100; // Initialize battery level to 100%
//      }

//         void chargeBattery(int amount) {
//             batteryLevel += amount;
//             if (batteryLevel > 100) batteryLevel = 100;
//             cout << brand << " " << model << " charged to " << batteryLevel << "%" << endl;
//         }
// };

// int main(){

//     manualCar myManualCar("Toyota", "Corolla");
//     myManualCar.startEngine();
//     myManualCar.shiftGear();
//     myManualCar.accelerate();
//     myManualCar.brake();
//     myManualCar.stopEngine();

//     cout << endl;

//     electricCar myElectricCar("Tesla", "Model 3");
//     myElectricCar.startEngine();
//     myElectricCar.accelerate();
//     myElectricCar.brake();
//     myElectricCar.chargeBattery(20);
//     myElectricCar.stopEngine();

//     return 0;
// }

// Polymorphism

// Dynamic polymorphism using virtual functions and method overriding
//Method Overriding

// class Car {
//     protected:
//     string brand;
//     string model;
//     bool isEngineOn;
//     int currentSpeed;

//     public: 
//     // Cobstructor
//     Car(string b, string m){
//         this -> brand = b;
//         this -> model = m;
//         this -> isEngineOn = false;
//         this -> currentSpeed = 0;  
//     }

//     // Common methods 
//     void startEngine() {
//         isEngineOn = true;
//         cout << "Engine started for " << brand << " " << model << endl;
//     }

//     void stopEngine() {
//         isEngineOn = false;
//         currentSpeed = 0;
//         cout << "Engine stopped for " << brand << " " << model << endl;
//     }

//     virtual void accelerate() = 0; // Pure virtual function

//     virtual void brake() = 0; // Pure virtual function

//     // destructor
//     virtual ~Car(){
//         cout << "Car " << brand << " " << model << " is being destroyed." << endl;
//     }

// };

// class manualCar : public Car {
//     private:
//     int currentGear;

//     public:
//     manualCar(string b, string m) : Car(b,m){
//         this -> currentGear = 0;    
//     }

//     void shiftGear(){
//         if(!isEngineOn){
//             cout << "Cannot shift gear, engine is off." << endl;
//             return;
//         }
//         currentGear++;
//         cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
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

    
// };

// class electricCar : public Car {
//     private:
//      int batteryLevel; // Battery level percentage

//      public: 
//      electricCar(string b, string m) : Car(b,m){
//         this -> batteryLevel = 100; // Initialize battery level to 100%
//      }

//         void chargeBattery(int amount) {
//             batteryLevel += amount;
//             if (batteryLevel > 100) batteryLevel = 100;
//             cout << brand << " " << model << " charged to " << batteryLevel << "%" << endl;
//         }

//         void accelerate() override {
//             if(!isEngineOn){
//                 cout << "Cannot accelerate, engine is off." << endl;
//                 return;
//             }   
//             if(batteryLevel <= 0){
//                 cout << "Cannot accelerate, battery is dead." << endl;
//                 return;
//             }
//             currentSpeed += 15; // Electric cars accelerate faster
//             batteryLevel -= 5; // Consumes battery
//             if(batteryLevel < 0) batteryLevel = 0;
//             cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h, Battery level: " << batteryLevel << "%" << endl;
//         }

//         void brake() override {
//             if (currentSpeed > 0) {
//                 currentSpeed -= 15; // Electric cars brake faster
//                 if(currentSpeed < 0) currentSpeed = 0;
//                 cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << " km/h" << endl;
//             } else {
//                 cout << brand << " " << model << " is already stopped." << endl;
//             }
//         }

// };

// int main(){

//     manualCar myManualCar("Toyota", "Corolla");
//     myManualCar.startEngine();
//     myManualCar.shiftGear();
//     myManualCar.accelerate();
//     myManualCar.brake();
//     myManualCar.stopEngine();

//     cout << endl;

//     electricCar myElectricCar("Tesla", "Model 3");
//     myElectricCar.startEngine();
//     myElectricCar.accelerate();
//     myElectricCar.brake();
//     myElectricCar.chargeBattery(20);
//     myElectricCar.stopEngine();

//     return 0;
// }

// Static polymorphism using function overloading and operator overloading
// Method overloading

// class manualCar {
//     private:
//     string brand;
//     string model;
//     bool isEngineOn;
//     int currentSpeed;
//     int currentGear;

//     public: 
//     manualCar(string b, string m){
//         this -> brand = b;
//         this -> model = m;
//         this -> isEngineOn = false;
//         this -> currentSpeed = 0;  
//         this -> currentGear = 0;  
//     }

//     void startEngine() {
//         isEngineOn = true;
//         cout << "Engine started for " << brand << " " << model << endl;
//     }

//     void stopEngine() {
//         isEngineOn = false;
//         currentSpeed = 0;
//         cout << "Engine stopped for " << brand << " " << model << endl;
//     }

//     void accelerate() {
//         if(!isEngineOn){
//             cout << "Cannot accelerate, engine is off." << endl;
//             return;
//         }   
//         currentSpeed += 10;
//         cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h" << endl;
//     }

//     void accelerate(int increment) {
//         if(!isEngineOn){
//             cout << "Cannot accelerate, engine is off." << endl;
//             return;
//         }   
//         currentSpeed += increment;
//         cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h with increment of " << increment << endl;
//     }

//     void brake() {
//         if (currentSpeed > 0) {
//             currentSpeed -= 10;
//             cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << " km/h" << endl;
//         } else {
//             cout << brand << " " << model << " is already stopped." << endl;
//         }
//     }

//     void brake(int decrement) {
//         if (currentSpeed > 0) {
//             currentSpeed -= decrement;
//             if(currentSpeed < 0) currentSpeed = 0;
//             cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << " km/h with decrement of " << decrement << endl;
//         } else {
//             cout << brand << " " << model << " is already stopped." << endl;
//         }
//     }

//     void shiftGear(){
//         if(!isEngineOn){
//             cout << "Cannot shift gear, engine is off." << endl;
//             return;
//         }
//         currentGear++;
//         cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
//     }
// };

// int main(){
//     manualCar myManualCar("Toyota", "Corolla");
//     myManualCar.startEngine();
//     myManualCar.shiftGear();
//     myManualCar.accelerate();
//     myManualCar.accelerate(25); // Using overloaded method
//     myManualCar.brake();
//     myManualCar.brake(15); // Using overloaded method
//     myManualCar.stopEngine();

//     return 0;
// }


// Static and Dynamic Polymorphism combined

class Car {
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public: 
    // Cobstructor
    Car(string b, string m){
        this -> brand = b;
        this -> model = m;
        this -> isEngineOn = false;
        this -> currentSpeed = 0;  
    }

    // Common methods 
    void startEngine() {
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        cout << "Engine stopped for " << brand << " " << model << endl;
    }

    virtual void accelerate() = 0; // Pure virtual function

    virtual void brake() = 0; // Pure virtual function

    // destructor
    virtual ~Car(){
        cout << "Car " << brand << " " << model << " is being destroyed." << endl;
    }

};

class manualCar : public Car {
    private:
    int currentGear;
    public:
    manualCar(string b, string m) : Car(b,m){
        this -> currentGear = 0;    
    }
    void shiftGear(){
        if(!isEngineOn){
            cout << "Cannot shift gear, engine is off." << endl;
            return;
        }
        currentGear++;
        cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
    }
    void accelerate() override {
        if(!isEngineOn){
            cout << "Cannot accelerate, engine is off." << endl;
            return;
        }   
        currentSpeed += 10;
        cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h" << endl;
    }
    void accelerate(int increment) { // Overloaded method
        if(!isEngineOn){
            cout << "Cannot accelerate, engine is off." << endl;
            return;
        }   
        currentSpeed += increment;
        cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h with increment of " << increment << endl;
    }
    void brake() override {
        if (currentSpeed > 0) {
            currentSpeed -= 10;
            cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }
    void brake(int decrement) { // Overloaded method
        if (currentSpeed > 0) {
            currentSpeed -= decrement;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << "Braking " << brand << " " << model << ", current speed: " << currentSpeed << " km/h with decrement of " << decrement << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }

};


int main(){
    manualCar myManualCar("Toyota", "Corolla");
    myManualCar.startEngine();
    myManualCar.shiftGear();
    myManualCar.accelerate();
    myManualCar.accelerate(25); // Using overloaded method
    myManualCar.brake();
    myManualCar.brake(15); // Using overloaded method
    myManualCar.stopEngine();

    return 0;
}