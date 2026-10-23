#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "Rpg.h"

using namespace std;


class Game {
public:
    Game(); //constructor
   void generatePlayers(int n);
    int selectPlayer();
    void endRound(RPG* winner, RPG* loser, int loserIndex);
    void battleRound();
    void gameLoop();
    void printFinalResults();

    ~Game(); //destructor

    private:

    //private members

    vector<RPG*> players; // Vector to hold the players
    set<int> live_players;
    
};
#endif


    
