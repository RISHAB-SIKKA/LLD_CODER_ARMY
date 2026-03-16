#include<iostream>
#include<mutex>

using namespace std;

class Logger{
    private:
    static Logger *instance;
    static mutex mtx;
    string message;
    Logger(){
        cout << "Logger constructor called" << endl;
    }
   
    public:
    static Logger* getInstance(){
        if(instance == nullptr){
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr){
                instance = new Logger();
            }
        }
        return instance;
    }

    void log(string message){
        this->message = message;
    }
    string getMessage(){
        return message;
    }
};

Logger* Logger::instance = nullptr;
mutex Logger::mtx;


int main(){
    Logger* logger1 = Logger::getInstance();    
    
    logger1->log("Hello1, World! from logger1");
    Logger* logger2 = Logger::getInstance();
    logger2->log("Hello2, World!");

    cout << ((logger1==logger2) ? "logger1 and logger2 are the same object" : "logger1 and logger2 are different objects") << endl;
    cout << "logger1 message: " << logger1->getMessage() << endl;
    cout << "logger2 message: " << logger2->getMessage() << endl;

    delete logger1;
    return 0;
}