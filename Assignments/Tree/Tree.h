/* 
 * File:   Tree.cpp
 * Author: Javier Borja
 * Created on December 4, 2017,  10:00 AM
 * Reference: http://www.geeksforgeeks.org/binary-tree-data-structure/
 *            https://en.wikipedia.org/wiki/AVL_tree
 * Purpose: Tree class Specification and Implementation file
 */


#ifndef TREE_H
#define TREE_H

#include<iostream>

using namespace std;

struct node{
    int data;
    node* left=NULL;
    node* right=NULL;
    int height=0;
};

class Tree{
    private:
        node *root;
        
        //Setter
        node* insert(node *,int);   //Insert data as a new leaf
        
        //Delete
        void delTree(node *);       //Deletes itself
        node* delData(node *,int);  //Delete a single node, and replace it
        node* min(node *);      //Helper for deleting, no need for max
        
        //Display
        void inorder(node *);       //View left-root-right
        void preorder(node *);      //View root-left-right
        void postorder(node *);     //View left-right-root
        
        //Balacing Functions
        node* balance(node *); //Performs balancing based on bottom conditions
        node* LL(node *);      //1 Right rotation
        node* LR(node *);      //Left rotate, then Right rotate
        node* RL(node *);      //Right rotate, then left rotate
        node* RR(node *);      //1 Left rotation
        int height(node *leaf)  //Helper to keep tree balanced
        {if(leaf==NULL) return -1; else return leaf->height;}
        
    public:
        //Constructor
        Tree()
        {root=NULL;}
        Tree(int data)
        {root=insert(root,data);}
        
        //Destructor
        ~Tree()
        {delTree(root);}
        
        //Set
        void insert(int data)    //Insert data as a new leaf
        {root=insert(root,data);}
        
        //Mutate
        void delData(int data)
        {root=delData(root,data);}
        
        //Display
        void inorder()      //View left-root-right
        {inorder(root); cout<<endl;}
        void preorder()     //View root-left-right
        {preorder(root); cout<<endl;}
        void postorder()    //View left-right-root
        {postorder(root); cout<<endl;}
};

void Tree::delTree(node *leaf){
    if(leaf!=NULL){
        delTree(leaf->left);
        delTree(leaf->right);
        delete leaf;
    }
}

node* Tree::insert(node *leaf,int data){
    if(leaf==NULL){
        leaf=new node;
        leaf->data=data;
    }else if(data<leaf->data){
        leaf->left=insert(leaf->left,data);
        if(height(leaf->left)-height(leaf->right)==2){
            if(data<leaf->left->data)
                leaf=LL(leaf);
            else
                leaf=RL(leaf);
        }
    }else if(data>leaf->data){
        leaf->right=insert(leaf->right,data);
        if(height(leaf->right)-height(leaf->left)==2){
            if(data>leaf->right->data) leaf=RR(leaf);
            else leaf=LR(leaf);
        }
    }
    int hLeft=height(leaf->left), hRight=height(leaf->right);
    if(hLeft>hRight) leaf->height=hLeft+1;
    else leaf->height=hRight+1;
    return leaf;
}

node* Tree::LL(node *leaf){
    node *child=leaf->left;
    leaf->left=child->right;
    child->right=leaf;
    {
        int hLeft=height(leaf->left), hRight=height(leaf->right);
        if(hLeft>hRight) leaf->height=hLeft+1;
        else leaf->height=hRight+1;
    }
    {
        int hLeft=height(child->left), hRight=leaf->height;
        if(hLeft>hRight) child->height=hLeft+1;
        else child->height=hRight+1;
    }
    return child;
}

node* Tree::LR(node *leaf){
    leaf->right=LL(leaf->right);
    return RR(leaf);
}

node* Tree::RL(node *leaf){
    leaf->left=RR(leaf->left);
    return LL(leaf);
}

node* Tree::RR(node *leaf){
    node* child=leaf->right;
    leaf->right=child->left;
    child->left=leaf;
    {
        int hLeft=height(leaf->left), hRight=height(leaf->right);
        if(hLeft>hRight) leaf->height=hLeft+1;
        else leaf->height=hRight+1;
    }
    {
        int hLeft=height(leaf->right), hRight=leaf->height;
        if(hLeft>hRight) child->height=hLeft+1;
        else child->height=hRight+1;
    }
    return child;
}

node* Tree::min(node *leaf){
    if(leaf==NULL) return NULL;
    else if(leaf->left==NULL) return leaf;
    else return min(leaf->left);
}

node* Tree::delData(node *leaf,int data){
    if(leaf == NULL) return NULL;

    else if(data<leaf->data) //Go left if data is less than
        leaf->left=delData(leaf->left, data);
    else if(data>leaf->data) //Go right if data is greater than
        leaf->right=delData(leaf->left, data);
    else if(leaf->left!=NULL&&leaf->right!=NULL){
        node* temp;
        temp=min(leaf->right);
        leaf->data=temp->data;
        leaf->right=delData(leaf->right,leaf->data);
    }else{   
        node* temp;
        temp=leaf;
        if(leaf->left==NULL)
            leaf=leaf->right;
        else if(leaf->right==NULL)
            leaf=leaf->left;
        delete temp;
    }if(leaf==NULL)
        return leaf;

    leaf->height = max(height(leaf->left), height(leaf->right))+1;
    leaf=balance(leaf);
    return leaf;
}

node* Tree::balance(node *leaf){
    if(height(leaf->left)-height(leaf->right)==2){
        if(height(leaf->left->left)-height(leaf->left->right)==1)
             return RR(leaf); //Rotate left once
        else return LR(leaf); //Rotate left, then right
    }
    else if(height(leaf->right)-height(leaf->left)==2){
        if(height(leaf->right->right)-height(leaf->right->left)==1)
             return LL(leaf); //Rotate right once
        else return RL(leaf); //Rotate right, then left
    }
    return leaf;
}

void Tree::inorder(node *leaf){
    if(leaf!=NULL){
        inorder(leaf->left);
        cout<<leaf->data<<" ";
        inorder(leaf->right);
    }
}
void Tree::preorder(node *leaf){
    if(leaf!=NULL){
        cout<<leaf->data<<" ";
        preorder(leaf->left);
        preorder(leaf->right);
    }
}
void Tree::postorder(node *leaf){
    if(leaf!=NULL){
        postorder(leaf->left);
        postorder(leaf->right);
        cout<<leaf->data<<" ";
    }
}
#endif /* TREE_H */