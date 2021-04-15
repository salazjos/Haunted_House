/********************************************
Program name: Project Final - A Text-based Game
Author: Joseph Salazar
Description: Ghost.cpp - contains method
implementations for Ghost class.
********************************************/

#include "Ghost.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

/************************
class constructor
************************/
Ghost::Ghost(int id, string q, string a, string c, string n){

    setIDNumber(id);
    setQuestions(q);
    setAnswers(a);
    setChoices(c);
    setNumberAnswer(n);

    coin_amount = 1;
    isGhostAttempted = isAnswerCorrect = false;

    initializeStringSteams();
}

/******************************************
Function parameters: Player *p
Function Return type: void
Function Description: Function asks the player
the ghost's question. It determines if answer is
correct or not. Reduces life points for incorrect
answers and grants coins for correct answers.
******************************************/
void Ghost::runSpace(Player *p){

    //int attempted = (isGhostAttempted) ? 1 : 0;
    if(!isGhostAttempted){
        //display ghost message
        show_g_message();
        //display ghost question
        show_question();
        //get answer
        question_choice = menu.getGhostAnswer();

        //test if answer was correct
        if(question_choice == stoi(number_answer)){
            cout << "Corrent! You have earned my coin.\n" << endl;
            p->addCoinsToPlayer(1);
            cout << "You now have " << p->getCoinsVector().size() << " coins" << endl;
            isAnswerCorrect = true;
        }
        else{
            cout << "Incorrect choice" << endl;
            cout << "You have lost one life point\n" << endl;
            p->setLifePoints(p->getLifePoints() - 1);
            cout << "You have " <<p->getLifePoints() << " lift points remaining." << endl;
        }
        isGhostAttempted = true;
    }
    else{
        if(isAnswerCorrect)
            cout << "You have already earned my coin." << endl;
        else
            cout << " You got my question WRONG!!!" << endl;
    }
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function displays ghost's
opening message.
******************************************/
void Ghost::show_g_message(){
    cout << ss_g_message.str();
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function displays ghost's
question and answer choices.
******************************************/
void Ghost::show_question(){
    //display question
    cout << question << endl;
    //display choices
    cout << choices << endl;
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function constucts
stringstream for ghost opening message.
******************************************/
void Ghost::initializeStringSteams(){
    ss_g_message << "\nWelcome. I am Ghost " << getIdNumber() << endl;
    ss_g_message << "Answer my question and you will earn a coin." << endl;
    ss_g_message << "Get it wrong and you'll loose a life point." << endl;
    ss_g_message << "Let us begin.\n" << endl;
}
