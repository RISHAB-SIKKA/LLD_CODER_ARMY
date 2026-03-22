#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Account{
    public:
    virtual void withdraw(double amount) = 0;
    virtual void deposit(double amount) = 0;
    virtual double getBalance() = 0;
};

class savingAccount : public Account{
    private:
    double balance;

    public:
    savingAccount(double balance){
        this -> balance = balance;
    }

    void deposit(double amount) override{
        balance += amount;
    }

    void withdraw(double amount) override{
        if(amount > balance){
            cout << "Insufficient balance" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
    }

    double getBalance() override{
        return balance;
    }
};

class currentAccount : public Account{
    private:
    double balance;
    double amount;

    public:
    currentAccount(double balance){
        this -> balance = balance;
    }

    void deposit(double amount) override{
        balance += amount;
    }

    void withdraw(double amount) override{
        if(amount > balance){
            cout << "Insufficient balance" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
    }

    double getBalance() override{
        return balance;
    }
};

class FixedDepositAccount : public Account{
    private:
    double balance;

    public:
    FixedDepositAccount(double balance){
        this-> balance = balance;
    }

    void deposit(double amount) override{
        balance += amount;
    }

    void withdraw(double amount) override{
        cout << "Withdrawals are not allowed from Fixed Deposit Account before maturity" << endl;
    }

    double getBalance() override{
        return balance;
    }

};

class bankClient{
    private:
    vector<Account*> accounts;

    public:
    bankClient(vector<Account*> accounts){
        this-> accounts = accounts;
    }

    void processTransactions(){
        for(auto acc: accounts){
            acc -> deposit(100);
            try{
                acc -> withdraw(50);
            }catch(const exception& e){
                cout << "Error: " << e.what() << endl;
            }
            cout << "Account Balance: " << acc -> getBalance() << endl;
        }
    }
};


int main(){
    vector<Account*> accounts;

    accounts.push_back(new savingAccount(1000));
    accounts.push_back(new currentAccount(100));
    accounts.push_back(new FixedDepositAccount(300));

    bankClient client(accounts);
    client.processTransactions();

    return 0;
}