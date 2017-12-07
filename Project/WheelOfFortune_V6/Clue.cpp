/* File:   Clue.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Implementation File for Clue class
 */

//User Libraries
#include "Clue.h"

Clue::Clue(){
    catg[1]="TV Show";
    catg[2]="Event";
    catg[3]="Movie";
    catg[4]="Landmark";
    catg[5]="Famous Person";
    catg[6]="Thing";
    catg[7]="Song Title";
}

void Clue::setCat(unsigned int n){
    categry=n;
}

void Clue::setPhrase(string s){
    size=s.length();
    //Input Data
    for(int i=0;i<s.length();i++){
        phrase[i]=s[i];
    }
    phrase[size]='\0';
}