/* File:   Player.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Struct Specification File for Player
 */

#ifndef PLAYER_H
#define PLAYER_H

//System Libraries
#include <iostream>
#include <string>
using namespace std; //Namespace of the System Libraries

//User Libraries

struct Player{
    string name;
    int money;
    unsigned int score;
    
    Player(){
        money=50; //Player starts with $500.00
        score=0;  //Player starts with 0 points
    }
};

#endif /* PLAYER_H */