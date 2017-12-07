/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September , 2017,  PM
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

#include "Tree.h"
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Seed
    srand(time(0));
    //Variables
    Tree<string> arr;
    arr.insert("apple");
    arr.insert("cool");
    arr.insert("dino");
    arr.insert("fire");
    arr.insert("octopus");
    arr.insert("zebra");
    //Input Data
    
    arr.inorder();
    //Process Data
    
    //Output Data
    
    return 0;
}