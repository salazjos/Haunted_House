/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: Menu.cpp - contains method
implementations for Menu class.
********************************************/

#include "Menu.h"
#include "InputValidation.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::cin;

/************************
Class constructor
***********************/
Menu::Menu(){
    ss_questionPrompt << "Enter either 1, 2, 3, 4 corresponding to the choices above." <<endl;
    ss_questionPrompt << "Enter choice now: " << endl;
    ss_invalidInput << "Invalid input." << endl;
    ss_invalidInput << "Please enter whole numbers. Ex: 1,2,3, etc.\n" << endl;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns the
selected choice of the ghost's question.
1 - 4 is returned.
******************************************/
int Menu::getGhostAnswer(){
    std::string question_choice;
    int invalidStart_index_error = 0;
    int selection = 0;
    bool isValidInteger = false;

    do{
        try{
            cout << ss_questionPrompt.str();
            cin >> question_choice;
            cin.ignore();

            invalidStart_index_error = testForInvalidParameterInputs(question_choice);

            while(invalidStart_index_error != 3){ //input was not an integer
                if(invalidStart_index_error == 1){ // not an integer
                    cout << ss_invalidInput.str();
                    cout << ss_questionPrompt.str();
                    cin >> question_choice;
                    cin.ignore();
                }
                else if(invalidStart_index_error == 2){ //invalid selection
                    cout << ss_invalidSelection.str();
                    cout << ss_questionPrompt.str();
                    cin >> question_choice;
                    cin.ignore();
                }
                //test for valid input
                invalidStart_index_error = testForInvalidParameterInputs(question_choice);
            }

            selection = stoi(question_choice);
            isValidInteger = true;

        }catch(std::out_of_range &outrange){ //exception thrown from stoi())
            cout << "Inputted number was out of range for integer." << endl;
            isValidInteger = false;
        }
        catch(std::invalid_argument &ia){ //exception thrown from stoi()
            cout << "Number could not be converted to integer. " << endl;
            isValidInteger = false;
        }

    }while(!isValidInteger);

    return selection;
}

/******************************************
Function parameters: string for input
                     int for minimum value
                     int for maximum value
Function Return type: int
Function Description: Function determines if string
input is an integer, 1 is returned if not integer.
If string choice is integer, input is determined if
within range. 2 is returned if not within range. 3 is
returned by defualt if input is valid on both tests.
******************************************/
int Menu::testForInvalidParameterInputs(const std::string &input) {
    //1: input not an integer
    //2: input not within range
    //3: good
    int number = 0;
    int error_Code = 3; //by defualt it is good

    if(!isInputInteger(input))
        error_Code = 1;
    else{ //is an integer
        number = stoi(input);
        if(!isNumberInRange(number, 1, 4))
            error_Code = 2;
    }
    return error_Code;
}

/******************************************
Function parameters: bool left
                     bool right
                     bool top
                     bool bottom
Function Return type: Movememnt move
Function Description: Function determines where the player can
move to next from the current space based on the parameter bool values.
The selected direction is returned.
******************************************/
Menu::Movement Menu::getMovement(bool left, bool right, bool top, bool bottom){

    bool isSelectionValid = false;
    int next_direction = 0;
    //Movement move;

    while(!isSelectionValid){
        cout << "\nWhere would you like to go next?" << endl;
        displayWhereCanGo(left,right,top,bottom);
        next_direction = getGhostAnswer();

        //test if next_direction is valid
        if(isLocationSelectionValid(next_direction,left,right,top,bottom))
            isSelectionValid = true;
        else
            cout << "Invalid direction choice " << endl;
    }

    if(next_direction == 1)
        return MOVE_LEFT;
    else if(next_direction == 2)
        return MOVE_RIGHT;
    else if(next_direction == 3)
        return MOVE_TOP;
    else
        return MOVE_BOTTOM;
}

/******************************************
Function parameters: bool left
                     bool right
                     bool top
                     bool bottom
Function Return type: void
Function Description: Function builds and displays a string indicating
the choices the player has in selecting their next move.
******************************************/
void Menu::displayWhereCanGo(bool left, bool right, bool top, bool bottom){

    std::stringstream ss_movementOptions;
    ss_movementOptions.str("");

    if(left)
        ss_movementOptions << "1) Left" << endl;

    if(right)
        ss_movementOptions << "2) Right" << endl;

    if(top)
        ss_movementOptions << "3) Up" << endl;

    if(bottom)
        ss_movementOptions << "4) Down" << endl;

    cout << ss_movementOptions.str();
}

/******************************************
Function parameters:  int choice - movement coice
                      bool left
                      bool right
                      bool top
                      bool bottom
Function Return type: bool
Function Description: Function tests wheither the choice
and its associated bool direction is a valid choice.
Function is a helper function.
******************************************/
bool Menu::isLocationSelectionValid(int choice, bool left, bool right, bool top, bool bottom){

    return (left && choice == 1) || (right && choice == 2) ||
           (top && choice == 3) || (bottom && choice == 5);

}
