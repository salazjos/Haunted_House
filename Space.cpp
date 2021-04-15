/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: Space.cpp - contains method
implementations for Space class.
********************************************/

#include "Space.h"

/*************
class constructor
*************/
Space::Space(){
//blank
}

/******************************************
Function parameters: none
Function Return type: bool
Function Description: Function determines if the
left pointer space is null
******************************************/
bool Space::isLeftAvailable(){
    return (left != nullptr);
}

/******************************************
Function parameters: none
Function Return type: bool
Function Description: Function determines if the
right pointer space is null
******************************************/
bool Space::isRightAvailable(){
    return (right != nullptr);
}

/******************************************
Function parameters: none
Function Return type: bool
Function Description: Function determines if the
top pointer space is null
******************************************/
bool Space::isTopAvailable(){
    return (top != nullptr);
}

/******************************************
Function parameters: none
Function Return type: bool
Function Description: Function determines if the
bottom pointer space is null
******************************************/
bool Space::isBottomAvailable(){
    return (bottom != nullptr);
}
