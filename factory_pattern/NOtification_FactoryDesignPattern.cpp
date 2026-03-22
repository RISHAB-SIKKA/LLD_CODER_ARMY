#include<iostream>
#include<string>
#include<stdexcept>
#include<memory>
#include<algorithm>
using namespace std;

// -------------------------------
// ENUM CLASS
// -------------------------------
enum class NotificationType{
    Email,
    SMS,
    Unknown,
    PUSH
};

// -------------------------------
// Convert string → lowercase
// -------------------------------
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// -------------------------------
// STRING → ENUM
// -------------------------------
NotificationType stringToNotificationType(const string& type){
    string t = toLower(type);

    if(t == "email") return NotificationType::Email;
    if(t == "sms")   return NotificationType::SMS;
    if(t == "push")  return NotificationType::PUSH;

    return NotificationType::Unknown;
}

// -------------------------------
// ENUM → STRING
// -------------------------------
string notificationTypeToString(NotificationType type){
    switch(type){
        case NotificationType::Email: return "email";
        case NotificationType::SMS:   return "sms";
        case NotificationType::PUSH:  return "push";
        default:                      return "unknown";
    }
}

// -------------------------------
// BASE CLASS
// -------------------------------
class Notification{
public:
    virtual void send(const string& to, const string& message) = 0;
    virtual ~Notification() = default;
};

// -------------------------------
// EMAIL
// -------------------------------
class EmailNotification: public Notification{
public:
    void send(const string& to, const string& message) override{
        cout << "Sending EMAIL to " << to << " : " << message << endl;
    }
};

// -------------------------------
// SMS
// -------------------------------
class SMSNotification: public Notification{
public:
    void send(const string& to, const string& message) override{
        cout << "Sending SMS to " << to << " : " << message << endl;
    }
};

//PUSH METHOD
class PUSHNotification: public Notification{
public:
    void send(const string& to, const string& message) override{
        cout << "Sending PUSH notification to " << to << " with message " << message << endl;
    }
};

// -------------------------------
// FACTORY USING ENUM
// -------------------------------
class NotificationFactory{
public: 
    static unique_ptr<Notification> createNotification(NotificationType type){
        switch(type){
            case NotificationType::Email:
                return make_unique<EmailNotification>();
            case NotificationType::SMS:
                return make_unique<SMSNotification>();
            case NotificationType::PUSH:
                return make_unique<PUSHNotification>();
            default:
                throw invalid_argument("Invalid notification type");
        }
    }
};

// -------------------------------
// MAIN
// -------------------------------
int main(){

    string s1 = "email";
    string s2 = "sms";
    string s3 = "PUSH";
    string s4 = "unknown";

    NotificationType type1 = stringToNotificationType(s1);
    NotificationType type2 = stringToNotificationType(s2);
    NotificationType type3 = stringToNotificationType(s3);
    NotificationType type4 = stringToNotificationType(s4);

    cout << "type1: " << notificationTypeToString(type1) << endl;
    cout << "type2: " << notificationTypeToString(type2) << endl;
    cout << "type3: " << notificationTypeToString(type3) << endl;
    cout << "type4: " << notificationTypeToString(type4) << endl;

    auto n1 = NotificationFactory::createNotification(type1);
    n1->send("john@example.com", "Hello, how are you?");

    auto n2 = NotificationFactory::createNotification(type2);
    n2->send("+1234567890", "Hello, how are you?");

    auto n3 = NotificationFactory::createNotification(type3);
    n3->send("john@example.com", "Hello, how are you?");

    // auto n4 = NotificationFactory::createNotification(type4);
    // n4->send("john@example.com", "Hello, how are you?");

    return 0;
}
