/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 4 , 2017, 5:00 PM
 * Purpose: Driver program for SimpleVector
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "SimpleVector.h"
//Global Constants

//Function Prototypes
void menu();
void init(SimpleVector<int> &);
void opt1(SimpleVector<int> &);
void opt2(SimpleVector<int> &);
void disp(SimpleVector<int> &);
//Execution

int main(int argc, char** argv) {
    //Variables
    int choice;
    //Input Data
    cout<<"Input array size"<<endl;
    cin>>choice;

    //Process Data
    SimpleVector<int> vector(choice);
    cout<<"Creating a vector of size "<<vector.size()<<endl;
    init(vector);
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:opt1(vector);
            case 2:opt2(vector);
            default: break;
        }
    
    //Output Data
        disp(vector);
    }while(choice>0&&choice<3);
    
    return 0;
}

void menu(){
    cout<<"Input:\n"
            "1 to add element\n"
            "2 to delete element\n"<<endl;
}

void init(SimpleVector<int> &a){
    int x;
    for(int i=0;i<a.size();i++){
        cout<<"Input value for element #"<<(i+1)<<": ";
        cin>>x;
        a[i]=x;
    }
    cout<<endl;
}

void opt1(SimpleVector<int> &a){
    int n;
    cout<<"Input new value: ";
    cin>>n;
    a.push_back(n);
    cout<<endl;
}

void opt2(SimpleVector<int> &a){
    a.pop_off();
    cout<<endl;
}

void disp(SimpleVector<int> &a){
    cout<<"Current Vector: "<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}