/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: Player.cpp - contains method
implementations for Player class.
********************************************/

#include "Player.h"

/*****************
class constructor
****************/
Player::Player(){
    setLifePoints(START_LIFE_POINTS_AMOUNT);
}

/******************************************
Function parameters: int c - coint amount
Function Return type: void
Function Description: Function adds coing amount
to coin vector
******************************************/
void Player::addCoinsToPlayer(int c){
    coins_vector.push_back(c);
}

/******************************************
Function parameters: none
Function Return type: vecotr
Function Description: Function returns the coin
vector
******************************************/
std::vector<int> Player::getCoinsVector(){
    return coins_vector;
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function clears the coin
vector
******************************************/
void Player::clearCoinsVector(){
    coins_vector.clear();
}

/******************************************
Function parameters: int l - life point
Function Return type: void
Function Description: Function sets life_points
to parameters value l.
******************************************/
void Player::setLifePoints(int l){
    life_points = l;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: returns life_points value.
******************************************/
int Player::getLifePoints() const{
    return life_points;
}
