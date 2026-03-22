#include<iostream>
#include<string>
#include<vector>

using namespace std;

class BankAccount{
    protected:
        double balance;
    public:

        BankAccount(double b){
            if(b<0){
                throw invalid_argument("Initial balance cannot be negative");
            }
            balance = b;
        }

        virtual void withdraw(double amount){
            if(balance-amount <0){
                throw runtime_error("Insufficient funds");
            }
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
};


class cheatAccount : public BankAccount{
    public:
        cheatAccount(double b) : BankAccount(b) {}

        void withdraw(double amount) override{
            // Violates invariant by allowing overdraft
            balance -= amount; // No check for negative balance
            cout << "Cheat Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
}; 


int main(){
    try{
        BankAccount* acc = new cheatAccount(100);
        acc->withdraw(150); // This should throw an error in a proper implementation
    }
    catch(const exception& e){
        cout << "Caught Exception: " << e.what() << endl;
    }
}