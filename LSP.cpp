// Tightly coupling code example that violates Liskov Substitution Principle (LSP)
// // class fixedDepositAccount : public Account {

// #include<iostream>
// #include<string>
// #include<vector>

// using namespace std;

// // Here we are going to give example for violating Liskov Substitution Principle (LSP)

// class Account {
//     public:
//     virtual void withdraw(double amount) = 0;
//     virtual void deposit(double amount) = 0;
// };

// class savingAccount : public Account {
//     private:
//     double balance;

//     public:
//     savingAccount(){
//         this -> balance = 0;
//     }

//     void deposit(double amount) override {
//         balance += amount;
//         cout << "Deposited $" << amount << ", new balance: $" << balance << endl;
//     }

//     void withdraw(double amount) override {
//         if(amount > balance){
//             cout << "Insufficient funds. Current balance: $" << balance << endl;
//             return;
//         }
//         balance -= amount;
//         cout << "Withdrew $" << amount << ", new balance: $" << balance << endl;
//     }
// };

// class currentAccount : public Account {
//     private:
//     double balance;
//     double overdraftLimit;

//     public:
//     currentAccount(double limit){
//         this -> balance = 0;
//         this -> overdraftLimit = limit;
//     }

//     void deposit(double amount) override {
//         balance += amount;
//         cout << "Deposited $" << amount << ", new balance: $" << balance << endl;
//     }

//     void withdraw(double amount) override {
//         if(amount > balance + overdraftLimit){
//             cout << "Withdrawal exceeds overdraft limit. Current balance: $" << balance << ", overdraft limit: $" << overdraftLimit << endl;
//             return;
//         }
//         balance -= amount;
//         cout << "Withdrew $" << amount << ", new balance: $" << balance << endl;
//     }
// };


// class fixedDepositAccount : public Account {
//     private:
//     double balance;

//     public:
//     fixedDepositAccount(int period){
//         this -> balance = 0;
//     }

//     void deposit(double amount) override {
//         balance += amount;
//         cout << "Deposited $" << amount << ", new balance: $" << balance << endl;
//     }

//     void withdraw(double amount) override {
//      throw logic_error("Withdrawals are not allowed from Fixed Deposit Account before maturity.");  
//     }
// };

// class bankClient{
//     private:
//     vector<Account*> accounts;

//     public:
//     bankClient(vector<Account*> accs){
//         this -> accounts = accs;
//     }

//     void performTransactions(){ 
//         for(auto acc : accounts){
//             if(typeid(*acc) == typeid(fixedDepositAccount)){
//                 cout<< "Attempting to withdraw from Fixed Deposit Account..." << endl;
//             }
//             else{
//                 try{
//                     acc -> withdraw(100); // Attempt to withdraw $100 from each account
//                 } catch (const logic_error& e) {
//                     cout << "Error: " << e.what() << endl;
//                 }
//             }

//     }
// };

// int main(){
//     vector<Account*> accounts;
//     accounts.push_back(new savingAccount());
//     accounts.push_back(new currentAccount(200));
//     accounts.push_back(new fixedDepositAccount(12)); // 12 months

//     bankClient* client = new bankClient(accounts);
//     client -> performTransactions();

//     return 0;
// }



// Tightly coupling code example that violates Liskov Substitution Principle (LSP)
// class fixedDepositAccount : public Account {

#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
#include<stdexcept>

using namespace std;

class DepositOnlyAccount{
    public:
    virtual void deposit(double amount) = 0;
};


class withdrawableAccount : public DepositOnlyAccount {
    public:
    virtual void withdraw(double amount) = 0;
};

class savingAccount : public withdrawableAccount {
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


class currentAccount : public withdrawableAccount {
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


class fixedDepositAccount : public DepositOnlyAccount {
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
};


class bankClient{
    private:
    vector<DepositOnlyAccount*> accounts;
    vector<withdrawableAccount*> withdrawableAccounts;
    public:
    bankClient(vector<DepositOnlyAccount*> accs, vector<withdrawableAccount*> wAccs){
        this -> accounts = accs;
        this -> withdrawableAccounts = wAccs;
    } 

    void performTransactions(){ 
        for(auto acc : withdrawableAccounts){
            acc -> withdraw(100); // Attempt to withdraw $100 from each withdrawable account
        }
        for(auto acc : accounts){
            acc -> deposit(200); // Deposit $200 to each account
        }
    }
};

int main(){
    vector<DepositOnlyAccount*> accounts;
    vector<withdrawableAccount*> wAccounts;
    savingAccount* sa = new savingAccount();
    currentAccount* ca = new currentAccount(200);
    fixedDepositAccount* fda = new fixedDepositAccount(12); // 12 months

    accounts.push_back(sa);
    accounts.push_back(ca);
    accounts.push_back(fda);

    wAccounts.push_back(sa);
    wAccounts.push_back(ca);

    bankClient* client = new bankClient(accounts, wAccounts);
    client -> performTransactions();

    return 0;
}
