/* 
 * File:   Tree.cpp
 * Author: Javier Borja
 * Created on December 4, 2017,  10:00 AM
 * Purpose: Tree class Specification file
 */


#ifndef TREE_H
#define TREE_H

template<class T>
class Tree{
    private:
        struct node{
            T data;             //Nodes hold data
            node *left=NULL;    //Left branch
            node *right=NULL;   //Right branch
        };
        node *root;     //Tree begins here
        node *ptr=root; //Points to position in tree
        
        //Private Class functions
        void delTree();         //Destroy entire tree
        void balance();         //Balances tree
        
    public:
        //Constructor
        Tree();
        //Destructor
        ~Tree(){printf("Destructor\n");delTree();}
        
        //Public Class functions
        void restart(){ptr=root;}//Point ptr back to root
        void goLeft();          //Traverse left
        void goRight();         //Traverse right
        void goUp();            //Go back to parent
        
        void insertData(T);     //Insert element. Can't choose insertion node
        T getData();            //Get data from current node
        void delNode();         //Destroy current node, and child nodes
        
        void printInorder();     //Traverses tree inorder and prints elements
        void printPreorder();    //Traverses tree preorder and prints elements
        void printPostorder();   //Traverses tree postorder and prints elements
        
};

template<class T>
Tree<T>::Tree(){
    printf("Constructor\n");
}

template<class T>
void Tree<T>::delTree(){
    printf("Deleting\n");
}
#endif /* TREE_H */