#include<iostream>
#include<string>
#include<vector>

using namespace std;

class cloneable{
    public:
    virtual NPC* clone() = 0;
    virtual ~cloneable() = default;
};

class NPC{
    public:
    string name;
    int power;
    int defense;
    int attack;

    NPC(string name, int power, int defense, int attack){
        this->name = name;
        this->power = power;
        this->defense = defense;
        this->attack = attack;
        cout << "NPC created: " << name << " with power: " << power << " defense: " << defense << " attack: " << attack << endl;
    }

    NPC(const NPC& other){
        name = other.name;
        power = other.power;
        defense = other.defense;
        attack = other.attack;
        cout << "NPC cloned: " << name << " with power: " << power << " defense: " << defense << " attack: " << attack << endl;
    }

    cloneable clone() const override{
        return new NPC(*this);
    }   
    
    void describe(){
        cout << "NPC: " << name << " with power: " << power << " defense: " << defense << " attack: " << attack << endl;
    }

    void setAttack(int attack){
        this->attack = attack;
    }

    void setPower(int power){
        this->power = power;
    }

    void setDefense(int defense){
        this->defense = defense;
    }

    void setName(string name){
        this->name = name;
    }

    virtual ~NPC() = default;
};



int main(){
    NPC *npc1 = new NPC("Alien 1 ", 100, 50, 20);
    npc1->describe();

    NPC *npc2 = dynamic_cast<NPC*>(npc1->clone());
    npc2->setName("Alien 2");
    npc2->describe();

    NPC *npc3 = dynamic_cast<NPC*>(npc1->clone());
    npc3->setAttack(30);
    npc3->setName("Alien 3");
    npc3->describe();

    delete npc1;
    delete npc2;
    delete npc3;
    return 0;
}