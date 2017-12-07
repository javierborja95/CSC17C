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

#include "RecursiveSorts.h"
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Seed
    srand(time(0));
    //Variables
    vector<int> array;
    //Input Data
    for(int i=0;i<50;i++){
        array.push_back(rand()%90+10);
    }
    //Process Data
    vector<int>::iterator p;
    int i=0;
    for(p=array.begin();p!=array.end();p++,i++){
        cout<<*p<<" ";
        if((i+1)%10==0) cout<<endl;
    }cout<<endl;
    //Output Data
    insertRec(array,array.size());
    i=0;
    cout<<"Sorted with insertion sort"<<endl;
    for(p=array.begin();p!=array.end();p++,i++){
        cout<<*p<<" ";
        if((i+1)%10==0) cout<<endl;
    }cout<<endl;
    
    random_shuffle(array.begin(),array.end());
    i=0;
    for(p=array.begin();p!=array.end();p++,i++){
        cout<<*p<<" ";
        if((i+1)%10==0) cout<<endl;
    }cout<<endl;
    cout<<"Sorted with Bubble sort"<<endl;
    bubbleRec(array,array.size());
    i=0;
    for(p=array.begin();p!=array.end();p++,i++){
        cout<<*p<<" ";
        if((i+1)%10==0) cout<<endl;
    }cout<<endl;
    
    return 0;
}