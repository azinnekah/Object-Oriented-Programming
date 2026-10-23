//RPG.h

#ifndef RPG_H
#define RPG_H   
#include <string>
#include <iostream>
#include <random>

using namespace std;


const int INVENTORY_SIZE = 10; // Maximum number of items in the inventory

const float HIT_FACTOR = 0.05; // Factor to determine hit success
const int MAX_HITS_TAKEN = 3; // Maximum number of hits a player can take before losing


class RPG {
public:

//constructors

RPG(); // Default constructor
RPG(string name, int hits_taken, float luck, float exp, int level); // Parameterized constructor

//destructor
~RPG(); 

//mutators
bool isAlive() const; // Check if the player is alive
void setHitsTaken(int new_hits);
void setName(string name);
void updateExpLevel();
void attack(RPG* opponent);

//accessors
string getName() const;
int getHitsTaken() const;
float getLuck() const;
float getExp() const;
int getLevel() const;
void printStats();


private:
string name;
//COMPLETE THE REST
int hits_taken;
float luck;
float exp;
int level;



};

#endif  