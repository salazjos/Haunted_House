/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: Menu.h - contains
prototype methods for Menu class. This class
represents a menu system. It is used by the
main.cpp to display menus, get input data from
user, and display error messages.
********************************************/


#ifndef FINALPROJECT_MENU_H
#define FINALPROJECT_MENU_H


#include <string>
#include <sstream>
class Menu {
private:
    std::stringstream ss_questionPrompt, ss_invalidInput, ss_invalidSelection;
    int testForInvalidParameterInputs(const std::string &input);
    void displayWhereCanGo(bool, bool, bool, bool);
    bool isLocationSelectionValid(int, bool, bool, bool, bool);

public:
    Menu();
    enum Movement{MOVE_LEFT, MOVE_RIGHT, MOVE_TOP, MOVE_BOTTOM};
    int getGhostAnswer();
    Movement getMovement(bool l, bool r, bool t, bool b);
};


#endif //FINALPROJECT_MENU_H
