/* File:   Phrase.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Phrase class
 */

#ifndef PHRASE_H
#define PHRASE_H

//System Libraries
#include <iostream>  //Input/Output
#include <string>    //String Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Letter.h"

class Phrase: public Letter{
    private:
        list<Letter> arr;        //List
        list<Letter>::iterator p;//Iterator to traverse
        int size;    //Size of array
    public:
        //Mutators
        void use(int i);
        
        //Accessors
        int getSize(){return size;}
        char getLetter(int);
        bool getUsed(int);
        
        //Member Functions
        void setArr(string);
        void display() override;
};

#endif /* PHRASE_H */