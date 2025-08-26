#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Here we are going to give example for violating Liskov Substitution Principle (LSP)

class Account {
    public:
    virtual void withdraw(double amount) = 0;
    virtual void deposit(double amount) = 0;
};

class savingAccount : public Account {
    private:
    double balance;

    public:
    savingAccount(){
        this -> balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << ", new balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if(amount > balance){
            cout << "Insufficient funds. Current balance: $" << balance << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrew $" << amount << ", new balance: $" << balance << endl;
    }
};

class currentAccount : public Account {
    private:
    double balance;
    double overdraftLimit;

    public:
    currentAccount(double limit){
        this -> balance = 0;
        this -> overdraftLimit = limit;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << ", new balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if(amount > balance + overdraftLimit){
            cout << "Withdrawal exceeds overdraft limit. Current balance: $" << balance << ", overdraft limit: $" << overdraftLimit << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrew $" << amount << ", new balance: $" << balance << endl;
    }
};


class fixedDepositAccount : public Account {
    private:
    double balance;

    public:
    fixedDepositAccount(int period){
        this -> balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << ", new balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
     throw logic_error("Withdrawals are not allowed from Fixed Deposit Account before maturity.");  
    }
};

class bankClient{
    private:
    vector<Account*> accounts;

    public:
    bankClient(vector<Account*> accs){
        this -> accounts = accs;
    }

    void performTransactions(){
        for(auto acc : accounts){
            acc -> deposit(100);
            try {
                acc -> withdraw(50);
            } catch (const logic_error& e) {
                cout << "Transaction error: " << e.what() << endl;
            }
        }
    }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new savingAccount());
    accounts.push_back(new currentAccount(200));
    accounts.push_back(new fixedDepositAccount(12)); // 12 months

    bankClient* client = new bankClient(accounts);
    client -> performTransactions();

    return 0;
}