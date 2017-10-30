/* File:   Play.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for play class
 */

#ifndef PLAY_H
#define PLAY_H

//System Libraries
#include <string>    //Strings
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Game.h"
#include "Keyboard.h"
#include "Phrase.h"

//Variables
const int WHEEL=12; //Size of wheel

class Play{
    private:
        Clue clue;   //Category and clue phrase
        bool win;    //Win or lose
        Keyboard k;  //Keyboard
        Phrase p;    //Phrase
        int w[WHEEL]={0,5,5,10,10,15,15,20,25,30,35,40}; //Wheel spin options
    public:
        
        //Member Functions
        void play(Game *); //The actual game
        void end(Game *);  //Ending screen, win or lose
        void spin(Game *); //Spin the wheel
        void buy(Game *);  //Buy a vowel
        void guess(Game *);//Guess the phrase
        void display();   //Display the keyboard and hidden phrase
        void menu(Game *); //Outputs the game menu
        
        //Accessors
        bool getWin()          //Returns win boolean
        {return win;}
        int getMoney(Game *a)  //Returns player's money
        {return a->getMoney();}
};

#endif /* PLAY_H */