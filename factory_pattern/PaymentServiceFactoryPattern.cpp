#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

using namespace std;

class PaymentService{
    public:
    virtual void validatePayment() = 0;
    virtual void pay() = 0;
    virtual ~PaymentService() = default;
};

class CreditCardPaymentService : public PaymentService{
    public:
    void validatePayment() override{
        cout << "Validating credit card payment" << endl;
    }
    void pay() override{
        cout << "Paying with credit card" << endl;
    }
};

class DebitCardPaymentService : public PaymentService{
    public:
    void validatePayment() override{
        cout << "Validating debit card payment" << endl;
    }
    void pay() override{
        cout << "Paying with debit card" << endl;
    }
};

class WalletPaymentService : public PaymentService{
    public:
    void validatePayment() override{
        cout << "Validating wallet payment" << endl;
    }
    void pay() override{
        cout << "Paying with wallet" << endl;
    }
};

class PaymentServiceFactory{
    private:
    using creator = function<unique_ptr<PaymentService>()>;
    unordered_map<string, creator> creators;

    public:
    void registerPaymentService(const string& name, creator creator){
        creators[name] = creator;
    }

    unique_ptr<PaymentService> createPaymentService(const string& name){
        if(creators.find(name) == creators.end()){
            throw invalid_argument("Invalid payment service type");
        }
        return creators[name]();
    }
};

int main(){
    PaymentServiceFactory factory;
    factory.registerPaymentService("credit_card", []() -> unique_ptr<PaymentService> {
        return make_unique<CreditCardPaymentService>();
    });
    factory.registerPaymentService("debit_card", []() -> unique_ptr<PaymentService> {
        return make_unique<DebitCardPaymentService>();
    });
    factory.registerPaymentService("wallet", []() -> unique_ptr<PaymentService> {
        return make_unique<WalletPaymentService>();
    });
    auto paymentService = factory.createPaymentService("credit_card");
    paymentService->validatePayment();
    paymentService->pay();
}