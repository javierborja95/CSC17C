/* File:   addSub.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Specification File for adding and subtracting templates
 */

#ifndef ADDSUB_H
#define ADDSUB_H

//System Libraries
using namespace std; //Namespace of the System Libraries

//User Libraries

template<class T1,class T2>
void add(T1 *t1,T2 t2){
    *(t1)+t2;
}

template<class T1,class T2>
void sub(T1 *t1,T2 t2){
    *(t1)-t2;
}

#endif /* ADDSUB_H */