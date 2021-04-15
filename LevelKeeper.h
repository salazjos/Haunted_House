/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: LevelKeepr.h - contains
prototype methods for LevelKeepr class. This class
is used to repesent the level keepr of each level.
It is used primarly to allow transition to the next
level.
********************************************/

#ifndef FINALPROJECT_LEVELKEEPER_H
#define FINALPROJECT_LEVELKEEPER_H

#include <stdio.h>
#include <sstream>
#include "Space.h"
#include "Player.h"
using std::stringstream;

class LevelKeeper : public Space{
    const int COINS_NEEDED = 3;
    bool isCanAdvance;
    stringstream ss_KeeperMessage, ss_KeeperSatisfied;

    void initializeStringStreams();

public:
    LevelKeeper();
    bool canAdance() {return isCanAdvance;}
    void runSpace(Player *) override; //virtual

    Space_Type getType() override {return Space_Type::level_Keeper;}
};


#endif //FINALPROJECT_LEVELKEEPER_H
