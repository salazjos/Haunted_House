/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: main.cpp - executes the Haunted House
game.
********************************************/

#include <iostream>
#include "HauntedHouse.h"


int main(int argc, const char * argv[]) {

    HauntedHouse *hauntedHouse = new HauntedHouse();

    hauntedHouse->playGame();

    std::cout << "\nYou have completed the game.";

    delete hauntedHouse;

    return 0;
}
