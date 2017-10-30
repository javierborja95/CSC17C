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
#include "Player.h"
#include "Clue.h"

//Variables
const int SIZE=44; //Max Size of Char array

class Game{
    private:
        Player user;       //The player
        stack <Clue> stck; //A stack of clues
        fstream in;        //Input
        
    public:
        //Constructor
        Game();  //Introduction, sets random seed, creates library
        
        //Destructor
        ~Game(); //Deletes library, closes file streams, appends to leaderboard
        
        //Mutators
        void setName(string s)        //Sets a player's name
        {user.name=s;}
        void setScore(unsigned int n) //Sets a player's score
        {user.score=n;}
        void setMoney(int n)          //Sets a player's money
        {user.money=n;}
        
        //Accessors
        string getName(){return user.name;}
        unsigned int getScore(){return user.score;}
        int getMoney(){return user.money;}
        
        //Member Functions
        void fill();          //Creates an index to the library
        void menu();          //Displays the menu
        void lderBrd();       //Displays a leaderboard
        void write();         //Appends to the library
        void read();          //Displays the entire library
        void addLder();       //Adds profile to leaderboard
        bool isGood(char[]);  //Input verification
        
        //Add Functions
        void addMoney(int n)
        {user.money+=n;}
        void addScore(unsigned int n)
        {user.score+=n;}
        
        //Subtract Functions
        void subMoney(int n)
        {user.money-=n;}
        
        //Play class can access private members of Game class
        friend class Play;
};

#endif /* GAME_H */