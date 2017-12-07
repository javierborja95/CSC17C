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
#include <cstdlib>   //For random
#include <ctime>     //For time
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Tree.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Seeding
    srand(time(0));
    
    //Variables
    Tree<int> tree(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    
    //Output
    cout<<"Inserted numbers so that tree looks like:\n"
            "       4\n"
            "   2       6\n"
            "1     3  5     7\n";
    cout<<"Displaying inorder:"<<endl;
    tree.inorder();
    cout<<"Displaying preorder:"<<endl;
    tree.preorder();
    cout<<"Displaying postorder:"<<endl;
    tree.postorder();
    
    cout<<"\nDeleting 2, 4, and 5\n";
    tree.delData(2);
    tree.delData(4);
    tree.delData(5);
    cout<<"Displaying preorder:"<<endl;
    tree.preorder();
    cout<<"Displaying inorder:"<<endl;
    tree.inorder();
    
    //Variables
    Tree<int> randTree;
    int rand1;
    
    //Process Data
    cout<<"Now creating a random tree"<<endl;
    for(int i=0;i<50;i++){
        if(i==10){
            rand1=rand()%90+10;
            randTree.insert(rand1);
        }
        randTree.insert(rand()%90+10);
    }
    cout<<"Outputing Preorder:\n";
    randTree.preorder();
    cout<<"Outputing Inorder:\n";
    randTree.inorder();
    cout<<"Deleting the random values "<<rand1<<endl;
    //randTree.delData(rand1);
    cout<<"And displaying Preorder:\n";
    randTree.preorder();
    cout<<"And inorder:\n";
    randTree.inorder();
    
    //Output
    return 0;
}