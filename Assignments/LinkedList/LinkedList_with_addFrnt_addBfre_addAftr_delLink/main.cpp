//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr- Modified by Javier Borja
 * Created on September 21st, 2017 8:40 PM
 * Modified on October 12, 2017 9:00 AM
 * Purpose:  Linked List Version 3 Objects - Procedures with ADT
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Object.h"
#include "LinkedList.h"

//Global Constants Only, No Global Variables

//Function Prototypes Here

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare an object and place in the linked list
    Object obj(5);
    LinkedList<Object> *lnkList;
    lnkList=new LinkedList<Object>(obj);
    
    //Print the entire list
    lnkList->prntLst();
    
    //Add a value to the end of the list
    Object valAdd(2);
    Object valFnd1(valAdd);
    Object valFnd2(5);
    lnkList->addLst(valAdd);
    lnkList->addLst(Object(3));
    lnkList->addLst(Object(4));
    lnkList->addLst(Object(5));
    lnkList->addLst(Object(6));
    lnkList->addLst(valFnd1);
      
    //Print the entire list after adding to it
    lnkList->prntLst();
    
    //Add values to beginning, before and after index, and then delete valAdd
    Object bigObj(10);
    Object medObj(8);
    Object smlObj(2);
    lnkList->addFrnt(smlObj);  //Add to front, small object
    lnkList->addBfre(bigObj,1);//Add before index 1, big object
    lnkList->addAftr(medObj,2);//Add after index 2, medium object
    lnkList->delLink(valAdd);  //Delete link containing valAdd
    
    //Print the entire list after adding to it
    lnkList->prntLst();
    
    //Find some values in the List
    cout<<"This Object "<<valFnd1
            <<"is found at link    "<<lnkList->findLst(valFnd1)<<endl;
    cout<<"This Object "<<valFnd2
            <<"is found at link   "<<lnkList->findLst(valFnd2)<<endl;
    cout<<endl<<
            "The number of elements in the list = "<<lnkList->cntLst()<<endl;
    
    //Test the object return
    cout<<"The 6th element in the List at index 5 is "<<lnkList->getObj(5);
    
    //Deallocate memory
    delete lnkList;

    //Exit
    return 0;
}