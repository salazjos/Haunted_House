/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: ExitSpace.h - contains
prototype methods for ExitSpace class. This class represents
the exit space. It is used for triggering the end of the
game and indicating that the player has completed the dungeons.
********************************************/

#ifndef FINALPROJECT_EXITSPACE_H
#define FINALPROJECT_EXITSPACE_H

#include "Space.h"

class ExitSpace : public Space{
private:
    void displayExitMessage();

public:
    ExitSpace();
    void runSpace(Player *) override; //virtual
    Space_Type getType() override {return Space_Type::exit;} //virtual
};


#endif //FINALPROJECT_EXITSPACE_H
