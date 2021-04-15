/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: InputValidation.cpp - contains method
implementations for InputValidation.hpp methods.
********************************************/

#include "InputValidation.h"
#include <iostream>
#include <ctype.h>
using std::string;

/******************************************
Function parameters: string for input
Function Return type: bool
Function Description: Function loops through each
character in the string determing if each character is
a number 0 - 9. If a character is not a number, false
is returned.
******************************************/
bool isInputInteger(const string &input){

    if(input.length() < 1){
        return false;
    }

    //starting char is a 0 (ascii dec value of 48). not valid for integer.
    if(input.at(0) == 48){
        return false;
    }

    char c;
    for(int i = 0; i < input.length(); i++){
        c = input.at(i);
        if(i == 0){
            if(c == '-'){
                return false;
            }
        }
        else if(!isdigit(c)){
            return false; //not an integer
        }
    }
    return true; //is an integer
}

/******************************************
Function parameters: int for input number
                     int for minimum value
                     int for maximum value
Function Return type: char
Function Description: Function returns true if
input is betwbeen the values of min and max. false
if not.
******************************************/
bool isNumberInRange(int input, int min, int max){
    return (input >= min && input <= max);
}
