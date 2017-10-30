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
        Letter *arr; //Array of letters
        int size;    //Size of array
    public:
        //Constructor
        Phrase();
        
        //Destructor
        ~Phrase();
        
        //Mutators
        void use(int i)
        {arr[i].use();}
        
        //Accessors
        int getSize(){return size;}
        char getLetter(int);
        bool getUsed(int);
        
        //Member Functions
        void setArr(string);
        void display() override;
};

#endif /* PHRASE_H */