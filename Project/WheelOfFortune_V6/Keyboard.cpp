/* File:   Keyboard.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Keyboard class
 */

//User Libraries
#include "Keyboard.h"

Keyboard::Keyboard(){
    //Initializing the keyboard
    for(int i=0;i<ALPHA;i++){   //Initialize with alphabet
        arr.push_back('A'+i);
    }
}

void Keyboard::display(){
    //Output Data
    cout<<endl<<"Your keyboard:"<<endl;
    p=arr.begin();
    for(p=arr.begin();p!=arr.end();p++){//Go through keyboard list
        if(p->isLtUsed()==false){ //If letter has not been used, hide letter
            p->display();
        }else cout<<"■";
        if((distance(arr.begin(),p)+1)%13==0) cout<<endl;
    }
}

void Keyboard::use(int i){
    p=arr.begin();
    advance(p,i);
    p->use();
}

bool Keyboard::isUsed(int i){
    p=arr.begin();
    advance(p,i);
    p->isLtUsed();
}

char Keyboard::getChar(int i){
    p=arr.begin();
    advance(p,i);
    p->getLetter();
}