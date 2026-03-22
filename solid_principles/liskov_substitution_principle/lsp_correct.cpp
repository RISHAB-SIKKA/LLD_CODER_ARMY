#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class nonWithdrawableAccount{
    public:
    virtual void deposit(double amount) = 0;
    virtual double getBalance() = 0;
    virtual ~nonWithdrawableAccount() = default;
};

class withdrawableAccount : public nonWithdrawableAccount{
    public:
    virtual void withdraw(double amount) = 0;
    virtual double getBalance() = 0;
};

class savingAccount : public withdrawableAccount{
    private:
    double balance;

    public:
    savingAccount(double balance){
        this->balance = balance;
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
    }

    double getBalance() override{
        return balance;
    }
};

class currentAccount : public withdrawableAccount{
    private:
    double balance;

    public:
    currentAccount(double balance){
        this->balance = balance;
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
    }

    double getBalance() override{
        return balance;
    }
};

class fixedDepositAccount : public nonWithdrawableAccount{
    private:
    double balance;

    public:
    fixedDepositAccount(double balance){
        this->balance = balance;
    }

    void deposit(double amount) override{
        balance += amount;
    }

    double getBalance() override{
        return balance;
    }
};


class bankClient{
    private:
    vector<nonWithdrawableAccount*> nonWithdrawableAccounts;
    vector<withdrawableAccount*> withdrawableAccounts;

    public:
    bankClient(vector<nonWithdrawableAccount*> nonWithdrawableAccs,
               vector<withdrawableAccount*> withdrawableAccs){
        this->nonWithdrawableAccounts = nonWithdrawableAccs;
        this->withdrawableAccounts = withdrawableAccs;
    }
    
    void processTransactions(){
        for(auto acc: nonWithdrawableAccounts){
            acc->deposit(100);
            cout << "Non Withdrawable Account Balance: " << acc->getBalance() << endl;
        }
        for(auto acc: withdrawableAccounts){
            acc->deposit(100);
            acc->withdraw(50);
            cout << "Withdrawable Account Balance: " << acc->getBalance() << endl;
        }
    }
};

int main(){
    vector<nonWithdrawableAccount*> nonWithdrawableAccounts;
    vector<withdrawableAccount*> withdrawableAccounts;

    nonWithdrawableAccounts.push_back(new fixedDepositAccount(1000));

    withdrawableAccounts.push_back(new savingAccount(1000));
    withdrawableAccounts.push_back(new currentAccount(1000));

    bankClient client(nonWithdrawableAccounts, withdrawableAccounts);
    client.processTransactions();

    for (nonWithdrawableAccount* acc : nonWithdrawableAccounts) {
        delete acc;
    }
    for (withdrawableAccount* acc : withdrawableAccounts) {
        delete acc;
    }

    return 0;
}