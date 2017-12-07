/* File:   Keyboard.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Keyboard class
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

//System Libraries
#include <iostream>  //Input/Output
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Letter.h"

//Constants
const int ALPHA=26; //Size of the alphabet

class Keyboard: public Letter{
    public:
        list<Letter> arr;        //List
        list<Letter>::iterator p;//Iterator to traverse
    public:
        //Constructor
        Keyboard();
        
        //Mutators
        void use(int);
        
        //Accessors
        bool isUsed(int);
        char getChar(int);
        
        //Member functions
        void display() override;
};

#endif /* KEYBOARD_H */