/* File:   RecursiveSorts.h
 * Author: Javier B
 * Created on December 7, 2017, 11:49 AM
 * Purpose:Specification File for Recursive Sorts
 */

#ifndef RECURSIVESORTS_H
#define RECURSIVESORTS_H

//System Libraries
#include <vector>
using namespace std; //Namespace of the System Libraries

//User Libraries

//Functions

//Recursive bubble Sort (Parameters:Vector,Sizeof() vector)
template<class T>
void bubbleRec(vector<T> &array,int size){
    if(size==1) return; //Finished recursion
    //Process Data
    for(int i=0;i<size-1;i++){
        if(array[i]>array[i+1]){
            T temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
        }
    }
    //End is sorted, sort previous
    bubbleRec(array,size-1);
}

//Recursive insertion Sort (Parameters:Vector,Sizeof() vector)
template<class T>
void insertRec(vector<T> &array,int size){
    if(size<=1) return; //Keep recursion going until you reach first index
    
    //Process Data
    insertRec(array,size-1); //From beg()array to end()array
    T key=array[size-1];
    int flag=size-2;
    while(flag>=0&&array[flag]>key){
        //swap()
        array[flag+1]=array[flag];
        flag-=1;
    }
    array[flag+1]=key;
}

#endif /* RECURSIVESORTS_H */