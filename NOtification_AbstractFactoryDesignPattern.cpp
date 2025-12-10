#include<iostream>
#include<string>
#include<stdexcept>
#include<memory>
using namespace std;

// -------------------------------
// BASE CLASS
// -------------------------------
class Notification{
public:
    virtual void send(const string& to, const string& message) = 0;
    virtual ~Notification() = default;
};

class EmailNotification: public Notification{};
class SMSNotification: public Notification{};

class AWSEmailNotification: public EmailNotification{
    public: 
    void send(const string& to, const string& message) override{
        cout << "Sending AWS Email Notification to " << to << " with message " << message << endl;
    }
};

class TwilioEmailNotification: public EmailNotification{
    public: 
    void send(const string& to, const string& message) override{
        cout << "Sending Twilio Email Notification to " << to << " with message " << message << endl;
    }
};

class AWSSMSNotification: public SMSNotification{
    public: 
    void send(const string& to, const string& message) override{
        cout << "Sending AWS SMS Notification to " << to << " with message " << message << endl;
    }
};

class TwilioSMSNotification: public SMSNotification{
    public: 
    void send(const string& to, const string& message) override{
        cout << "Sending Twilio SMS Notification to " << to << " with message " << message << endl;
    }
};

class NotificationFactory{
    public:
    virtual unique_ptr<EmailNotification> createEmailNotification() = 0;
    virtual unique_ptr<SMSNotification> createSMSNotification() = 0;
    virtual ~NotificationFactory() = default;
};

class AWSNotificationFactory: public NotificationFactory{
    public:
    unique_ptr<EmailNotification> createEmailNotification() override{
        return make_unique<AWSEmailNotification>();
    }
    unique_ptr<SMSNotification> createSMSNotification() override{
        return make_unique<AWSSMSNotification>();
    }
};

class TwilioNotificationFactory: public NotificationFactory{
    public:
    unique_ptr<EmailNotification> createEmailNotification() override{
        return make_unique<TwilioEmailNotification>();
    }
    unique_ptr<SMSNotification> createSMSNotification() override{
        return make_unique<TwilioSMSNotification>();
    }
};

int main(){
    unique_ptr<NotificationFactory> Factory;

    cout << "Enter the notification type (aws = 1 or twilio = 2): ";
    int choice;
    cin >> choice;

    if(choice == 1){
        Factory = make_unique<AWSNotificationFactory>();
    }
    else if(choice == 2){
        Factory = make_unique<TwilioNotificationFactory>();
    }
    else{
        cout << "Invalid choice" << endl;
    }

    cout << "Enter the notification type (email = 1 or sms = 2 or both = 3): ";
    int notificationType;
    cin >> notificationType;

    string recipient;
    string message;

    cout << "Enter the recipient:";
    cin >> recipient;
    cout << "Enter the message: ";
    cin >> message;

    if((notificationType == 1) || (notificationType == 3)){
        auto emailNotification = Factory->createEmailNotification();
        emailNotification->send(recipient, message);
    }
    if((notificationType == 2) || (notificationType == 3)){
        auto smsNotification = Factory->createSMSNotification();
        smsNotification->send(recipient, message);
    }

    return 0;
}