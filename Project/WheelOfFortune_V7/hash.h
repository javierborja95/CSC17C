/* File:   Hash.h
 * Author: Javier B
 * Created on December 10, 2017, 8:56 PM
 * Purpose: Class Specification File for a Hash Class
 */

#ifndef HASH_H
#define HASH_H

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <vector>   //Vectors
#include <list>     //Lists
using namespace std; //Namespace of the System Libraries

//User Libraries

class Hash{
    private:
        int size=500;  //Max hash table size to minimize collisions. 500 buckets.
        vector<list<string> > table;
        list<string>::iterator p; //Iterator to traverse linked list
        int hashFn(const string); //Hash Function
    public:
        Hash()
        {vector<list<string> > preTable(size);
        table=preTable;} //Pre allocating memory
        void addElmnt(string); //Add element into hash table
        bool findElmnt(string);//Find element in the hash table. True if found.
};

#endif
