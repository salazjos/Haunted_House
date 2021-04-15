/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: HauntedHouse.h - contains
prototype methods for HauntedHouse class. This class
represents a huanted house with 3 dungen levels. It is
used by the main.cpp to run the game.
********************************************/

#ifndef FINALPROJECT_HAUNTEDHOUSE_H
#define FINALPROJECT_HAUNTEDHOUSE_H

#include <stdio.h>
#include "Space.h"
#include "Player.h"
#include "Menu.h"
#include "Ghost.h"
#include "LevelKeeper.h"
#include "ExitSpace.h"
#include <fstream>
#include <string>
using std::ifstream;
using std::string;

class HauntedHouse {
private:
    static const int MAX_GHOST_AMT = 15,
            MAX_LEVELKEEPER_AMT = 3,
            MAX_QUESTIONS_ANSWERS_AMT = 15;
    Menu menu;
    Space *currentSpace, *startSpace;
    Player *player;
    Ghost *ghosts[MAX_GHOST_AMT];
    LevelKeeper *levelkeepers[MAX_LEVELKEEPER_AMT];
    ExitSpace *exitSpace;

    string all_questions[MAX_QUESTIONS_ANSWERS_AMT];
    string all_choices[MAX_QUESTIONS_ANSWERS_AMT];
    string all_answers[MAX_QUESTIONS_ANSWERS_AMT];
    string answers_inNumbers[MAX_QUESTIONS_ANSWERS_AMT];
    string questions_file_name = "questions.txt";
    string chocies_file_name = "choices.txt";
    string answers_file_name = "answers.txt";
    string answers_numbers_file_name = "numbers.txt";
    ifstream ifs;

    void fileArrayFromFile(ifstream &, string &filename, string *array);
    void initializeGrid();

public:
    HauntedHouse();
    void playGame();
    ~HauntedHouse();
};


#endif //FINALPROJECT_HAUNTEDHOUSE_H
