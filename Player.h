/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: Player.h - contains
prototype methods for Player class. This class represents
the player of the game. It is used to house the player's earned coins
and their life points.
********************************************/

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H


#include <vector>

class Player {
private:
    const int START_LIFE_POINTS_AMOUNT = 3;
    std::vector<int> coins_vector;
    int life_points;

public:
    Player();
    void addCoinsToPlayer(int coins);
    void clearCoinsVector();
    void setLifePoints(int lifePoints);
    int getLifePoints() const;
    std::vector <int> getCoinsVector();
};


#endif //FINALPROJECT_PLAYER_H
