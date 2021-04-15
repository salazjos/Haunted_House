/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: LevelKeepr.cpp - contains method
implementations for LevelKeepr class.
********************************************/

#include "LevelKeeper.h"
#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

/*******************
class constructor
*******************/
LevelKeeper::LevelKeeper(){
    isCanAdvance = false;
    initializeStringStreams();
}

/******************************************
Function parameters: Player *p
Function Return type: void
Function Description: Function determines if
player can advance to the next level.
******************************************/
void LevelKeeper::runSpace(Player *p){

    //display level keeper message
    cout << ss_KeeperMessage.str();

    //test if player has enough coins
    if(p->getCoinsVector().size() >= COINS_NEEDED){
        cout << ss_KeeperSatisfied.str();
        p->clearCoinsVector();
        isCanAdvance = true;
    }
    else{
        cout << "Sorry. You don't have enough coins." << endl;
        cout << "You are trapped here.....FOREVER!!!\n" << endl;
    }
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function constructs class
stringstream objects.
******************************************/
void LevelKeeper::initializeStringStreams(){

    ss_KeeperMessage << "\nYou have reached the LEVEL KEEPER" << endl;
    ss_KeeperMessage << "I am the keeper of this level." << endl;
    ss_KeeperMessage << "You need 3 coings to leave my level and advance.\n" << endl;

    ss_KeeperSatisfied << "You have enough coins to leave my level and " << endl;
    ss_KeeperSatisfied << "advance. Good luck on the next level.\n" << endl;
}
