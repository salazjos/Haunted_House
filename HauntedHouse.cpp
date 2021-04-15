/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: HauntedHouse.cpp - contains method
implementations for HauntedHouse class.
********************************************/

#include "HauntedHouse.h"
/*
#include "Space.h"
#include "Ghost.h"
#include "ExitSpace.h"
#include "LevelKeeper.h"
#include "Player.h"
#include "Menu.h" */
#include <fstream>
#include <string>
#include <iostream>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;

/****************
class constructor
***************/
HauntedHouse::HauntedHouse(){

    currentSpace = nullptr;
    startSpace = nullptr;
    player = new Player();
    exitSpace = new ExitSpace();

    //populate appropriate arrays with data from files.
    fileArrayFromFile(ifs, questions_file_name, all_questions);
    fileArrayFromFile(ifs, chocies_file_name, all_choices);
    fileArrayFromFile(ifs, answers_file_name, all_answers);
    fileArrayFromFile(ifs, answers_numbers_file_name, answers_inNumbers);

    initializeGrid();
}

/******************************************
Function parameters: Player *p
Function Return type: void
Function Description: Function runs the game.
******************************************/
void HauntedHouse::playGame(){

    currentSpace = startSpace;
    while(true){

        //get what spaces are available
        bool bottomAvailable = currentSpace->isBottomAvailable();
        bool topAvailable    = currentSpace->isTopAvailable();
        bool leftAvailable   = currentSpace->isLeftAvailable();
        bool rightAvailable  = currentSpace->isRightAvailable();

        //run currentSpace
        currentSpace->runSpace(player);

        //we are at the exit
        if(currentSpace->getType() == Space::exit)
            return;

        //game is over
        if(player->getLifePoints() < 1){
            cout << "\nYOU HAVE DIED. " << endl;
            cout << "GAME OVER! " << endl;
            return;
        }

        //pass bools into the menu function to ask where to go next
        Menu::Movement movement;
        movement = menu.getMovement(leftAvailable, rightAvailable, topAvailable,
                                     bottomAvailable);

        //assign the next space
        switch(movement){
            case Menu::MOVE_LEFT:
                currentSpace = currentSpace->getLeft();
                break;
            case Menu::MOVE_RIGHT:
                currentSpace = currentSpace->getRight();
                break;
            case Menu::MOVE_TOP:
                currentSpace = currentSpace->getTop();
                break;
            default:break;
        }
    } //end switch
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function initializes all the ghost
and level keep objects and assigns where they point to.
******************************************/
void HauntedHouse::initializeGrid(){

    //create 15 ghosts
    for(int i = 0; i < MAX_GHOST_AMT; i++){
        ghosts[i] = new Ghost(i+1, all_questions[i], all_answers[i],
                              all_choices[i], answers_inNumbers[i]);
    }

    //create 3 level keepers
    for(auto &levelKeeper : levelkeepers){
        levelKeeper = new LevelKeeper();
    }

    for(int i = 0; i < MAX_GHOST_AMT; i++){

        if(i == 0){
            ghosts[i]->setTop(nullptr);
            ghosts[i]->setBottom(nullptr);
            ghosts[i]->setLeft(nullptr);
            ghosts[i]->setRight(ghosts[i+1]);
        }

        if(i == 4){
            ghosts[i]->setTop(nullptr);
            ghosts[i]->setBottom(nullptr);
            ghosts[i]->setLeft(ghosts[i-1]);
            ghosts[i]->setRight(levelkeepers[0]);
        }

        if(i == 5){
            ghosts[i]->setTop(nullptr);
            ghosts[i]->setBottom(nullptr);
            ghosts[i]->setLeft(nullptr);
            ghosts[i]->setRight(ghosts[i+1]);
        }
    }

    //ghost 1
    ghosts[0]->setTop(nullptr);
    ghosts[0]->setBottom(nullptr);
    ghosts[0]->setLeft(nullptr);
    ghosts[0]->setRight(ghosts[1]);

    //ghost 2
    ghosts[1]->setTop(nullptr);
    ghosts[1]->setBottom(nullptr);
    ghosts[1]->setLeft(ghosts[0]);
    ghosts[1]->setRight(ghosts[2]);

    //ghost 3
    ghosts[2]->setTop(nullptr);
    ghosts[2]->setBottom(nullptr);
    ghosts[2]->setLeft(ghosts[1]);
    ghosts[2]->setRight(ghosts[3]);

    //ghost 4
    ghosts[3]->setTop(nullptr);
    ghosts[3]->setBottom(nullptr);
    ghosts[3]->setLeft(ghosts[2]);
    ghosts[3]->setRight(ghosts[4]);

    //ghost 5
    ghosts[4]->setTop(nullptr);
    ghosts[4]->setBottom(nullptr);
    ghosts[4]->setLeft(ghosts[3]);
    ghosts[4]->setRight(levelkeepers[0]);

    //ghost 6
    ghosts[5]->setTop(nullptr);
    ghosts[5]->setBottom(nullptr);
    ghosts[5]->setLeft(nullptr);
    ghosts[5]->setRight(ghosts[6]);

    //ghost 7
    ghosts[6]->setTop(nullptr);
    ghosts[6]->setBottom(nullptr);
    ghosts[6]->setLeft(ghosts[5]);
    ghosts[6]->setRight(ghosts[7]);

    //ghost 8
    ghosts[7]->setTop(nullptr);
    ghosts[7]->setBottom(nullptr);
    ghosts[7]->setLeft(ghosts[6]);
    ghosts[7]->setRight(ghosts[8]);

    //ghost 9
    ghosts[8]->setTop(nullptr);
    ghosts[8]->setBottom(nullptr);
    ghosts[8]->setLeft(ghosts[7]);
    ghosts[8]->setRight(ghosts[9]);

    //ghost 10
    ghosts[9]->setTop(nullptr);
    ghosts[9]->setBottom(nullptr);
    ghosts[9]->setLeft(ghosts[8]);
    ghosts[9]->setRight(levelkeepers[1]);

    //ghost 11
    ghosts[10]->setTop(nullptr);
    ghosts[10]->setBottom(nullptr);
    ghosts[10]->setLeft(nullptr);
    ghosts[10]->setRight(ghosts[11]);

    //ghost 12
    ghosts[11]->setTop(nullptr);
    ghosts[11]->setBottom(nullptr);
    ghosts[11]->setLeft(ghosts[10]);
    ghosts[11]->setRight(ghosts[12]);

    //ghost 13
    ghosts[12]->setTop(nullptr);
    ghosts[12]->setBottom(nullptr);
    ghosts[12]->setLeft(ghosts[11]);
    ghosts[12]->setRight(ghosts[13]);

    //ghost 14
    ghosts[13]->setTop(nullptr);
    ghosts[13]->setBottom(nullptr);
    ghosts[13]->setLeft(ghosts[12]);
    ghosts[13]->setRight(ghosts[14]);

    //ghost 15
    ghosts[14]->setTop(nullptr);
    ghosts[14]->setBottom(nullptr);
    ghosts[14]->setLeft(ghosts[13]);
    ghosts[14]->setRight(levelkeepers[2]);

    //levelkeeper 1
    levelkeepers[0]->setTop(ghosts[5]);
    levelkeepers[0]->setBottom(nullptr);
    levelkeepers[0]->setLeft(ghosts[4]);
    levelkeepers[0]->setRight(nullptr);

    //levelkeeper 2
    levelkeepers[1]->setTop(ghosts[10]);
    levelkeepers[1]->setBottom(nullptr);
    levelkeepers[1]->setLeft(ghosts[9]);
    levelkeepers[1]->setRight(nullptr);

    //levelkeeper 1
    levelkeepers[2]->setTop(exitSpace);
    levelkeepers[2]->setBottom(nullptr);
    levelkeepers[2]->setLeft(nullptr);
    levelkeepers[2]->setRight(nullptr);

    startSpace = ghosts[0];
}

/******************************************
Function parameters: ifstream &ifs
                     string &file_name
                     string *string_array
Function Return type: void
Function Description: Function opens the file and reads in the
file contents to the string array.
******************************************/
void HauntedHouse::fileArrayFromFile(ifstream &ifs, string &file_name, string *string_array){

    ifs.open(file_name.c_str());
    if(!ifs){
        cout << "Could not open file " << file_name << endl;
        return;
    }

    for(int i = 0; i < MAX_QUESTIONS_ANSWERS_AMT; i++){
        getline(ifs, string_array[i], '\n');
    }

    ifs.close();
}

/********************
class destructor
*******************/
HauntedHouse::~HauntedHouse(){

    //delete all ghosts
    for(auto &ghost : ghosts){
        delete ghost;
    }

    //delete all level keepers
    for(auto &levelkeeper : levelkeepers){
        delete levelkeeper;
    }

    delete player;
    delete exitSpace;
}
