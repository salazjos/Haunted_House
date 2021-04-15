/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: InputValidation.h - contains
prototype methods for InputValidation.cpp. File
is used by Menu class to validate user input.
********************************************/

#ifndef FINALPROJECT_INPUTVALIDATION_H
#define FINALPROJECT_INPUTVALIDATION_H

#include <stdio.h>
#include <string>

bool isInputInteger(const std::string &str);
bool isNumberInRange(int selection, int rangeMin, int rangeMax);


#endif //FINALPROJECT_INPUTVALIDATION_H
