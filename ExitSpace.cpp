/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: ExitSpace.cpp - contains method
implementations for ExitSpace class.
********************************************/

#include "ExitSpace.h"
#include "Player.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::stringstream;

/***************
Class constructor
********************/
ExitSpace::ExitSpace(){
    //blank
}

/******************************************
Function parameters: Player *p
Function Return type: void
Function Description: Function displays exit message
through helper function.
******************************************/
void ExitSpace::runSpace(Player *p){
    displayExitMessage();
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function builds displays the exit
space message
******************************************/
void ExitSpace::displayExitMessage(){

    stringstream ss;
    ss << "\nYOU HAVE SURVIVED!!!" << endl;
    ss << "You have made it out alive. " << endl;
    ss << "Now go and enjoy your life. " << endl;
    cout <<ss.str();
}