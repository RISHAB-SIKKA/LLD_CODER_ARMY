#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Violation Of Dependency Inversion Principle
// High Level Module should not depend on Low Level Module
// Both should depend on Abstraction
// Abstraction should not depend on details


class MySqlDB{ // Low Level Module
    public:
    void saveData(const string& data){
        cout << "Saving data to MySQL Database: " << data << endl;
    }
};

class MongoDB{ //   Low Level Module
    public:
    void saveData(const string& data){
        cout << "Saving data to MongoDB Database: " << data << endl;
    }
};

class CasandraDB{ //Low Level Module
    public:
    void saveData(const string& data){
        cout << "Saving data to Casandra Database: " << data << endl;
    }
};

class UserService{ // High Level Module
    private:
        MySqlDB* mySqlDB;
        MongoDB* mongoDB;
        CasandraDB* casandraDB;
    public:
        UserService(){
            mySqlDB = new MySqlDB();
            mongoDB = new MongoDB();
            casandraDB = new CasandraDB();
        }

        void storeInMySql(const string& data){
            mySqlDB->saveData(data);
        }
        void storeInMongo(const string& data){
            mongoDB->saveData(data);
        }
        void storeInCasandra(const string& data){
            casandraDB->saveData(data);
        }

};

int main(){
    UserService userService;
    userService.storeInMySql("User1 Data");
    userService.storeInMongo("User2 Data");
    userService.storeInCasandra("User3 Data");
    return 0;
}