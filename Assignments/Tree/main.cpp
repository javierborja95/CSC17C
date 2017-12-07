/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on December 4, 2017,  10:00 AM
 * Purpose: Driver program for testing a tree class
 * Reference: http://www.geeksforgeeks.org/binary-tree-data-structure/
 *            https://en.wikipedia.org/wiki/AVL_tree
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Tree.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    Tree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.inorder();
    tree.preorder();
    tree.delData(4);
    tree.preorder();
    tree.inorder();
    tree.delData(2);
    tree.inorder();
    tree.delData(3);
    tree.inorder();
    tree.preorder();
    tree.delData(5);
    tree.delData(1);
    tree.preorder();
    tree.inorder();
    return 0;
}