#include<iostream>
#include<string>
#include<vector>

using namespace std;

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

    void describe(){
        cout << "NPC: " << name << " with power: " << power << " defense: " << defense << " attack: " << attack << endl;
    }

    virtual ~NPC() = default;
};

int main(){
    NPC *npc1 = new NPC("Alien 1 ", 100, 50, 20);
    npc1.describe();

    NPC * npc2 = new NPC("Alien 2 ", 100, 50, 30); // ONLY ATTACK CHANGED
    npc2->describe();

    delete npc1; // Free the memory allocated for npc1
    delete npc2;

    return 0;
}
