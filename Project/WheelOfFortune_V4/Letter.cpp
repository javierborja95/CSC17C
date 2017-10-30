/* File:   Letter.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Specification File for Letter class
 */

//User Libraries
#include "Letter.h"


Letter::Letter(char a){
    //Process Data
    letter=a;
    isUsed=false;
}

Letter::Letter(){
    //Process Data
    letter=' ';
    isUsed=false;
}