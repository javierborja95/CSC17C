/* File:   Phrase.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Implementation File for Phrase class
 */

//User Libraries
#include "Phrase.h"
#include "Letter.h"

void Phrase::use(int i){
    p=arr.begin();
    advance(p,i);
    p->use();
}

void Phrase::setArr(string s){
    //Input Data
    size=s.length();
    p=arr.begin();
    for(int i=0;i<size;i++,p++){    //Initialize phrase array with clue
        arr.push_back(s[i]);
        if(isspace(p->getLetter())){//If letter is space
            p->use();               //Don't hide it
        }
    }
}

void Phrase::display(){
    //Output Data
    for(p=arr.begin();p!=arr.end();p++){         //Go through clue array
        if(p->isLtUsed()==false){  //If letter has not been used, hide letter
            cout<<"□";
        }else{
            p->display();
        }
    }
    cout<<endl;
}

char Phrase::getLetter(int i){
    p=arr.begin();
    advance(p,i);
    return p->getLetter();
}

bool Phrase::getUsed(int i){
    p=arr.begin();
    advance(p,i);
    return p->isLtUsed();
}