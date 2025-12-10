#include <iostream>
#include<vector>
#include<string>
#include<memory>

using namespace std;


// ----Startegy Interface for Walkable Robot----
class WalkableRobot{
    public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {};
};


//-----Concrete classes for Walkable Robot-----
class normalWalk: public WalkableRobot{
    public:
    void walk() override {
        cout << "Normal Walk" << endl;
    }
};

class noWalk: public WalkableRobot{
    public:
    void walk() override {
        cout << "noWalk" << endl;
    }
};


//-----Interface for Talkable Robot-----

class TalkableRobot{
    public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {};
};

//-----Concrete classes for Talkable Robot-----
class normalTalk: public TalkableRobot{
    public:
    void talk() override {
        cout << "Normal Talk" << endl;
    }
};

class noTalk: public TalkableRobot{
    public:
    void talk() override {
        cout << "No Talk" << endl;
    }
};

//-----Interface for Flyable Robot-----
class FlyableRobot{
    public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {};
};

//-----Concrete classes for Flyable Robot-----
class normalFly: public FlyableRobot{
    public:
    void fly() override {
        cout << "Normal Fly" << endl;
    }
};
class noFly: public FlyableRobot{
    public:
    void fly() override {
        cout << "No Fly" << endl;
    }
};

class Robot{
    protected:
    WalkableRobot* walkBehaviour;
    TalkableRobot* talkBehaviour;
    FlyableRobot* flyBehaviour;

    public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f){
        this->walkBehaviour = w;
        this->talkBehaviour = t;
        this->flyBehaviour = f;
    }

    void walk(){
        walkBehaviour->walk();
    }

    void talk(){
        talkBehaviour->talk();
    }

    void fly(){
        flyBehaviour->fly();
    }

    virtual void Projection() = 0;  //Abstract Method for subClasses
};


class CompanionRobot: public Robot{
    public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

    void Projection() override {
        cout << "Companion Robot" << endl;
    }   
};

class WorkerRobot: public Robot{
    public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

    void Projection() override {
        cout << "Worker Robot" << endl;
    }
};


int main(){
    Robot *robot1 = new CompanionRobot(new noWalk(), new noTalk(), new noFly());
    robot1->Projection();
    robot1->walk();
    robot1->talk();
    robot1->fly();

    cout << "--------------------------------" << endl;


    Robot *robot2 = new WorkerRobot(new normalWalk(), new normalTalk(), new normalFly());
    robot2->Projection();
    robot2->walk();
    robot2->talk();
    robot2->fly();

    cout << "--------------------------------" << endl;
    cout << "--------------------------------" << endl;
}