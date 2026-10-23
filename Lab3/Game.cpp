#include "Game.h"
#include <iostream>
#include <random>
#include <iterator>

using namespace std;

Game::Game() {

}


void Game::generatePlayers(int n){
for (int i = 0; i < n; i++) {
    players.push_back(new RPG());

    string new_name = "NPC_" + to_string(i);

    players[i]->setName(new_name);
    live_players.insert(i);
}

}

int Game::selectPlayer() {
   random_device rd; // Obtain a random number from hardware
   mt19937 gen(rd()); 
   uniform_int_distribution<> dist(0, live_players.size() - 1); 

   int randomIndex = dist(gen);

   set<int>::iterator it = live_players.begin();
   advance(it, randomIndex); // Move the iterator to the randomly selected index
   int selectedIndex = *it;

    return selectedIndex;
}

void Game::endRound(RPG* winner, RPG* loser, int loserIndex) {
   winner->setHitsTaken(0);
   live_players.erase(loserIndex);
   winner->updateExpLevel();
   cout << winner->getName() << "  won against " << loser->getName() << "!\n";

}

void Game::battleRound() {
    int player1Index = selectPlayer();
    int player2Index = selectPlayer();

    if (player1Index == player2Index) {
       battleRound();
       return;
    }
    RPG* player1 = players[player1Index];
    RPG* player2 = players[player2Index];

    while (player1->isAlive() && player2->isAlive()) {
        player1->attack(player2);
        if (player2->isAlive()) {
            player2->attack(player1);
        }

    }
    if (player1->isAlive()) {
        endRound(player1, player2, player2Index);
    } else {
        endRound(player2, player1, player1Index);
    }   

}

void Game::gameLoop() {
    
    while (live_players.size() > 1) {
        battleRound();
    }
}

void Game::printFinalResults() {
for (size_t i = 0; i < players.size(); i++) {
    players[i]->printStats();
    }
}

Game::~Game(){

}