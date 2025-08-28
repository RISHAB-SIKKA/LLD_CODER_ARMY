#include<iostream>
#include<string>
#include<vector>

using namespace std;

//pRE-cONDITION dEFINATION
// A precondition is a condition or predicate that must be true before a function or method is executed.
// It is a requirement that the caller of the function must satisfy in order for the function to work correctly.
// If the precondition is not met, the function may throw an exception, return an error code, or exhibit undefined behavior.
// In the context of inheritance and polymorphism, a subclass should not strengthen the preconditions of a method it overrides from its superclass.


class User{
    public:
    virtual void setPassword(string pwd) noexcept(false){
        if(pwd.length() < 8){ //PRE CONDITION PWD LENGTH SHOULD NOT BE LESS THAN 8
            throw invalid_argument("Password must be at least 6 characters long");
        }
        cout << "User: Password set to " << pwd << endl;
    }
};

class AdminUser: public User{
    public:
    void setPassword(string pwd) noexcept(false) override{
        // if(pwd.length() < 12){ //PRE CONDITION PWD LENGTH SHOULD NOT BE LESS THAN 12- STRONGER RULE (violation)
        //     throw invalid_argument("Admin Password must be at least 12 characters long");
        // }

         if(pwd.length() < 6){ //PRE CONDITION PWD LENGTH SHOULD NOT BE LESS THAN 6- weaker RULE (cORRECT)
            throw invalid_argument("Admin Password must be at least 12 characters long");
        }

        cout << "AdminUser: Password set to " << pwd << endl;
    }
};