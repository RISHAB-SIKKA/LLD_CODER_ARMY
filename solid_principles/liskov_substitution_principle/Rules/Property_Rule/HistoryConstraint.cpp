#include<iostream>
#include<string>
#include<vector>

using namespace std;

class bankAccount{
    protected:
        double balance;
    public:
        bankAccount(double b){
            if(b<0){
                throw invalid_argument("Initial balance cannot be negative");
            }
            balance = b;
        }

        virtual void withdraw(double amount) noexcept(false){
            if(balance-amount <0){
                throw runtime_error("Insufficient funds");
            }
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
};


class fixedDeposit : public bankAccount{
    public:
        fixedDeposit(double b) : bankAccount(b) {}

        void withdraw(double amount) noexcept(false) override{
            // Fixed deposits cannot be withdrawn before maturity
            //violation of LSP
            //violation of history constraint
            throw runtime_error("Withdrawals not allowed before maturity");
        }
};

class client{
    private:
        bankAccount* acc;
    public:
        client(bankAccount* acc){
            this->acc = acc;
        }
        void performWithdrawal(double amount){
            try{
                acc->withdraw(amount);
            }catch(const exception& e){
                cout << "Caught Exception in Client: " << e.what() << endl;
            }
        }
};


int main(){
    try{
        bankAccount* acc = new fixedDeposit(1000);
        client c(acc);
        c.performWithdrawal(100); // This should throw an error
    }
    catch(const exception& e){
        cout << "Caught Exception in Main: " << e.what() << endl;
    }
}