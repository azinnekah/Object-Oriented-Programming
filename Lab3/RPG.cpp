#include "RPG.h"

//constructor

RPG::RPG() {

    name = "NPC";
    hits_taken = 0;
    luck = 0.1f;
    exp = 50.0f;
    level = 1;

}


//overloaded construct

RPG::RPG(string name, int hits_taken, float luck, float exp, int level) {
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

string RPG::getName() const {
    return name;
}

int RPG::getHitsTaken() const {
    return hits_taken;
}   

float RPG::getLuck() const {
    return luck;
}

float RPG::getExp() const {
    return exp;
}

int RPG::getLevel() const {
    return level;
}

//mutators

void RPG::setHitsTaken(int new_hits) {
    hits_taken = new_hits;
}

bool RPG::isAlive() const {
    return hits_taken < MAX_HITS_TAKEN;
}

void RPG::setName(string name) {
    this->name = name;
}

void RPG::updateExpLevel() {
    exp += 50.0f; // Increase experience by 50
    if (exp >= 100.0f) {
        level+= 1; // Increase level by 1
        exp = 0.0f; // Reset experience after leveling up
        luck += 0.1f; // Increase luck by 0.1
    }
}


void RPG::attack(RPG* opponent) {
    // Calculate hit chance based on luck
random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
 float random_num = dis(gen);
   bool hit = (random_num < HIT_FACTOR * opponent->getLuck());
    if (hit) {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}


void RPG::printStats() {

    printf("Name: %s\t Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\tStatus: %s\n", name.c_str(), hits_taken, luck, exp, level, isAlive() ? "Alive" : "Dead");
}



RPG::~RPG() {
    // Destructor 

}




