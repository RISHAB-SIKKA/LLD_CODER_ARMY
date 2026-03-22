#include<iostream>
#include<string>
#include<vector>

using namespace std;
 // PostCondition Definition
    // A postcondition is a condition or predicate that must be true after a function or method has executed.
    // It is a guarantee provided by the function to the caller about the state of the system after the function completes.
    // If the postcondition is not met, it indicates that the function did not complete successfully or as expected.    
    // In the context of inheritance and polymorphism, a subclass should not weaken the postconditions of a method it overrides from its superclass.


class Car{
    protected:
        int speed;
    public:
        Car(){
            speed = 0;
        }

        virtual void accelerate(int increment) noexcept(false){
            speed += increment;
            if(speed > 200){ // POST CONDITION SPEED SHOULD NOT EXCEED 200
                throw runtime_error("Speed cannot exceed 200 km/h");
            }
            cout << "Car: Accelerated to " << speed << " km/h" << endl;
        }

        virtual void brake(int decrement) noexcept(false){
            speed -= decrement;
            cout << "Car: Decelerated to " << speed << " km/h" << endl;
        }
};

class SportsCar : public Car{

    private:
        int charge;
    public:
        void accelerate(int increment) noexcept(false) override{
            speed += increment;
            if(speed > 100){ // POST CONDITION SPEED SHOULD NOT EXCEED 300 - Stronger RULE (CORRECT)
                throw runtime_error("SportsCar Speed cannot exceed 300 km/h");
            }
            cout << "SportsCar: Accelerated to " << speed << " km/h" << endl;
        }

        void brake(int decrement) noexcept(false) override{
            speed -= decrement;
            charge += 5; // SportsCar gains charge when braking ((STRONGER RULE (CORRECT))
           
            cout << "SportsCar: Decelerated to " << speed << " km/h" << endl;
        }
};
