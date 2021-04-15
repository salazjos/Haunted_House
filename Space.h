/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: Space.h - contains
prototype methods for Space class. This class
represents the space class needed to build linked spaces
and transition between them. The LevelKeeper, ExitSpace,
and Ghost class are child classes of this class.
********************************************/

#ifndef FINALPROJECT_SPACE_H
#define FINALPROJECT_SPACE_H

#include "Player.h"
#include <stdio.h>

class Space {
private:
    Space *top = nullptr, *bottom = nullptr,
          *left = nullptr, *right = nullptr;

public:
    Space();

    void setTop(Space *t) {top = t;}
    void setBottom(Space *b) {bottom = b;}
    void setLeft(Space *l) {left = l;}
    void setRight(Space *r) {right = r;}

    Space *getTop() {return top;}
    Space *getBottom() {return bottom;}
    Space *getLeft() {return left;}
    Space *getRight() {return right;}

    enum Space_Type {ghost, level_Keeper, exit};

    virtual bool isLeftAvailable();
    virtual bool isRightAvailable();
    virtual bool isTopAvailable();
    virtual bool isBottomAvailable();

    virtual Space_Type getType() = 0;
    virtual void runSpace(Player *) = 0;
};
#endif //FINALPROJECT_SPACE_H
