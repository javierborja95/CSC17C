/* File:   Base.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for a Base class
 */

#ifndef BASE_H
#define BASE_H

//System Libraries
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Player.h"

class Base{ //A class meant to be inherited as a base to an actual game class
    protected:
        Player user;
    public:
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
        
        //Member Function
        virtual void menu()=0; //Displays a menu
};

#endif /* BASE_H */