/* File:   Clue.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Clue class
 */

#ifndef CLUE_H
#define CLUE_H

//System Libraries
#include <string>    //Strings
#include <iostream>  //Input/Output
#include <fstream>   //File input/Output
#include <cstring>   //Cstrings for strlen() function
#include <map>       //Maps
using namespace std; //Namespace of the System Libraries

//User Libraries

class Clue{
    private:
        map<int, string> catg;//Map of categories
        int size;
        unsigned int categry; //Number to represent a category
        char phrase[44];      //Max Phrase length
    public:
        Clue(); //Initialize the map
        
        //Mutators
        void setCat(unsigned int);
        void setPhrase(string);
        
        //Accessors
        char getPhrase(int i)
        {return phrase[i];}
        string getPhrase()
        {return phrase;}
        int getSize()
        {return strlen(phrase);}
        unsigned int getCat()
        {return categry;}
        
        //Output
        void showCat()
        {cout<<catg[categry]<<endl;}
        
        //Operator overload
        friend bool operator< (const Clue &left,const Clue &right){
            string a=left.phrase,b=right.phrase;
            return a<b;
        }
};

#endif /* CLUE_H */