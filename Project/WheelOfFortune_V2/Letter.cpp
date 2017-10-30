/* File:   Letter.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Letter class
 */

//User Libraries
#include "Letter.h"

//Initializing static variable
int Letter::calls=0;

Letter::Letter(char a){
    //Process Data
    letter=a;
    isUsed=false;
    calls++;
}

Letter::Letter(){
    //Process Data
    letter=' ';
    isUsed=false;
    calls++;
}