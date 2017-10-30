/* File:   Keyboard.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Keyboard class
 */

//User Libraries
#include "Keyboard.h"

Keyboard::Keyboard(){
    setArr();
}

Keyboard::~Keyboard(){
    //Deallocate Memory
    delete[] arr;
    arr=nullptr;
}

void Keyboard::display(){
    //Output Data
    cout<<endl<<"Your keyboard:"<<endl;
    for(int i=0;i<ALPHA;i++){         //Go through keyboard array
        if(arr[i].isLtUsed()==false){ //If letter has not been used, hide letter
            arr[i].display();
        }else cout<<"■";
        if((i+1)%13==0) cout<<endl;
    }
}

void Keyboard::setArr(){
    //Allocate Memory
    arr=new Letter[ALPHA]; //New Array of Letters for keyboard
    
    //Process Data
    for(int i=0;i<ALPHA;i++){   //Initialize with alphabet
        arr[i].setChar('A'+i);
    }
}