#include<iostream>
#include<string>
#include<vector>

using namespace std;

class DBInterface{
    public:
        virtual void saveData(const string& data) = 0; // Pure Virtual Function
};

class MySqlDB: public DBInterface{ // Low Level Module
    public:
    void saveData(const string& data) override{
        cout << "Saving data to MySQL Database: " << data << endl;
    }
};

class MongoDB: public DBInterface{ //   Low Level Module
    public:
    void saveData(const string& data) override{
        cout << "Saving data to MongoDB Database: " << data << endl;
    }
};

class CasandraDB: public DBInterface{ //Low Level Module
    public:
    void saveData(const string& data) override{
        cout << "Saving data to Casandra Database: " << data << endl;
    }
};

class UserService{ // High Level Module
    private:
        DBInterface* db; // Depend on Abstraction // Dependency Injection
    public:
        UserService(DBInterface* db){
            this->db = db;
        }

        void storeData(const string& data){
            db->saveData(data);
        }

        ~UserService(){
            delete db; // Clean up
        }
};

int main(){
    UserService userService(new MySqlDB());
    userService.storeData("User1 Data");

    UserService userService2(new MongoDB());
    userService2.storeData("User2 Data");

    UserService userService3(new CasandraDB());
    userService3.storeData("User3 Data");
    return 0;
}