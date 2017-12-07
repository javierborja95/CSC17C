/* File:   Letter.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Letter class
 */

#ifndef LETTER_H
#define LETTER_H

//System Libraries
#include <iostream>  //Input/Output
#include <list>      //list
using namespace std; //Namespace of the System Libraries

//User Libraries

class Letter{
    protected:
        char letter;
        bool isUsed;
        
    public:
        //Constructors
        Letter(char);
        Letter();
        
        //Mutators
        void setChar(char a)
        {letter=a;}
        void use()
        {isUsed=true;}
        
        //Accessors
        char getLetter(){return letter;}
        bool isLtUsed(){return isUsed;}
        
        //Member functions
        virtual void display(){cout<<letter;}
};

#endif /* LETTER_H */