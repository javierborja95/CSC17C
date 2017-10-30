/* File:   Phrase.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Implementation File for Phrase class
 */

//User Libraries
#include "Phrase.h"
#include "Letter.h"

Phrase::Phrase(){
    
}

Phrase::~Phrase(){
    //Deallocate Memory
    arr=nullptr;
}

void Phrase::setArr(string s){
    //Allocate Memory
    int n=s.length();
    Letter *ptr=new Letter[n]; //New array of Letters for phrase
    arr=ptr;
    //Input Data
    for(int i=0;i<n;i++){               //Initialize phrase array with clue
        arr[i].setChar(s[i]);
        if(isspace(arr[i].getLetter())){//If letter is space
            arr[i].use();               //Don't hide it
        }
    }
    size=n;
}

void Phrase::display(){
    //Output Data
    for(int i=0;i<size;i++){         //Go through clue array
        if(arr[i].isLtUsed()==false){  //If letter has not been used, hide letter
            cout<<"□";
        }else{
            arr[i].display();
        }
    }
    cout<<endl;
}

char Phrase::getLetter(int n){
    return arr[n].getLetter();
}

bool Phrase::getUsed(int n){
    return arr[n].isLtUsed();
}