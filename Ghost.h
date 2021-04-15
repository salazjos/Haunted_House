/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: Ghost.h - contains
prototype methods for Ghost class. This class
represents a Ghost space. It is heabily used as
the game main interaction.
********************************************/

#ifndef FINALPROJECT_GHOST_H
#define FINALPROJECT_GHOST_H

#include <stdio.h>
#include <string>
#include <sstream>
#include "Space.h"
#include "Player.h"
#include "Menu.h"
using std::string;

class Ghost : public Space {
private:
    Menu menu;
    int id_number, coin_amount, question_choice = 0;
    string question, choices, answer, number_answer;
    bool isGhostAttempted, isAnswerCorrect;
    std::stringstream ss_g_message;

    void show_g_message();
    void show_question();
    void initializeStringSteams();

public:
    Ghost(int id, string q, string a, string c, string n);
    void setIDNumber(int id) {id_number = id;}
    void setQuestions(string q) {question = q;}
    void setAnswers(string  a) {answer = a;}
    void setChoices(string c) {choices = c;}
    void setNumberAnswer(string n) {number_answer = n;}
    void runSpace(Player *) override; //virtual
    int  getCoinAmount() {return coin_amount;}
    int  getIdNumber() const {return id_number;}
    bool getIsGhostClear() {return isGhostAttempted;}
    Space_Type getType() override {return Space_Type::ghost;} //virtual
};


#endif //FINALPROJECT_GHOST_H
