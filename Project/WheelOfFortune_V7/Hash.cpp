/* File:   Hash.h
 * Author: Javier B
 * Created on December 10, 2017, 8:56 PM
 * Purpose: Class Implementation File for a Hash Class
 */

//User Libraries
#include "hash.h"
int Hash::hashFn(const string s){
    //Hash function
     int seed = 7567;
    for(int i=0;i<s.length();i++){
        seed^=s[i]*seed<<3;
        seed+=s[i]+7793;
    }
     if(seed<0) return seed*-1;
     else return seed;
}

//list<string> list; list.begin();

void Hash::addElmnt(string s){
    int bucket=hashFn(s)%size; //Create a hash and bucket
    table[bucket].push_back(s);       //Insert element into bucket
    //Linked list takes care of collisions
}

bool Hash::findElmnt(string s){
    //Look for bucket based on string
    int bucket=hashFn(s)%size;
    if(table[bucket].empty()){cout<<"empty"<<endl; return false;} //If empty, string is not in hash table
    else{ //Look through list to see if elements match string
        p=table[bucket].begin();
        while(p!=table[bucket].end()){
            if(s==*p){cout<<"Found"<<endl; return true; }//Return if found
            p++;
        }
    }
    cout<<"NOT Found"<<endl;
    return false; //Return not found
}