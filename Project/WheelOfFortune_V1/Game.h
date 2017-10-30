/* File:   Game.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Game class
 */

#ifndef GAME_H
#define GAME_H

//System Libraries
#include <cstdlib>   //Random seed
#include <ctime>     //Time
#include <fstream>   //File Input/Output
#include <iomanip>   //Output manipulation
#include <vector>    //Vectors
#include <algorithm> //For performing some algorithm functions
#include <stack>     //Stacks
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Base.h"
#include "Player.h"
#include "Clue.h"
#include "addSub.h"

//Variables
const int SIZE=44; //Max Size of Char array

class Game: public Base{
    private:
        stack <Clue> stck; //A stack of clues
        fstream in;        //Input
        
    public:
        //Constructor
        Game();  //Introduction, sets random seed, creates library
        
        //Destructor
        ~Game(); //Deletes library, closes file streams, appends to leaderboard
        
        //Member Functions
        void fill();          //Creates an index to the library
        void menu();          //Displays the menu
        void lderBrd();       //Displays a leaderboard
        void write();         //Appends to the library
        void read();          //Displays the entire library
        void addLder();       //Adds profile to leaderboard
        bool isGood(char[]);  //Input verification
        
        //Add Functions
        void addMoney(int);
        void addScore(unsigned int);
        
        //Subtract Functions
        void subMoney(int);
        
        //Play class can access private members of Game class
        friend class Play;
};

#endif /* GAME_H */