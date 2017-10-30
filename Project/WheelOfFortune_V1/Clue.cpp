/* File:   Clue.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Implementation File for Clue class
 */

//User Libraries
#include "Clue.h"

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

void Clue::showCat(){
    //Output Data
    switch(categry){
        case 1:
            cout<<"TV Show"<<endl;
            break;
        case 2:
            cout<<"Event"<<endl;
            break;
        case 3:
            cout<<"Movie"<<endl;
            break;
        case 4:
            cout<<"Landmark"<<endl;
            break;
        case 5:
            cout<<"Famous Person"<<endl;
            break;
        case 6:
            cout<<"Thing"<<endl;
            break;
        default:
            cout<<"Song Title"<<endl;
    }
}