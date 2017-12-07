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

template<class T>
struct node{
    T data;
    node* left=NULL;
    node* right=NULL;
    int height=0;
};

template<class T>
class Tree{
    private:
        node<T> *root;
        
        //Setter
        node<T>* insert(node<T> *,T);   //Insert data as a new leaf
        
        //Delete
        void delTree(node<T> *);       //Deletes itself
        node<T>* delData(node<T> *,T);  //Delete a single node, and replace it
        node<T>* min(node<T> *);      //Helper for deleting, no need for max
        
        //Display
        void inorder(node<T> *);       //View left-root-right
        void preorder(node<T> *);      //View root-left-right
        void postorder(node<T> *);     //View left-right-root
        
        //Balacing Functions
        node<T>* balance(node<T> *); //Performs balancing based on bottom conditions
        node<T>* LL(node<T> *);      //1 Right rotation
        node<T>* LR(node<T> *);      //Left rotate, then Right rotate
        node<T>* RL(node<T> *);      //Right rotate, then left rotate
        node<T>* RR(node<T> *);      //1 Left rotation
        int height(node<T> *leaf)  //Helper to keep tree balanced
        {if(leaf==NULL) return -1; return leaf->height;}
        
    public:
        //Constructor
        Tree()
        {root=NULL;}
        Tree(T data)
        {root=NULL; root=insert(root,data);}
        
        //Destructor
        ~Tree()
        {delTree(root);}
        
        //Set
        void insert(T data)    //Insert data as a new leaf
        {root=insert(root,data);}
        
        //Mutate
        void delData(T data)
        {root=delData(root,data);}
        
        //Display
        void inorder()      //View left-root-right
        {inorder(root); cout<<endl;}
        void preorder()     //View root-left-right
        {preorder(root); cout<<endl;}
        void postorder()    //View left-right-root
        {postorder(root); cout<<endl;}
};

template<class T>
void Tree<T>::delTree(node<T> *leaf){
    if(leaf!=NULL){
        delTree(leaf->left);
        delTree(leaf->right);
        delete leaf;
    }
}

template<class T>
node<T>* Tree<T>::insert(node<T> *leaf,T data){
    if(leaf==NULL){
        leaf=new node<T>;
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

template<class T>
node<T>* Tree<T>::LL(node<T> *leaf){
    node<T> *child=leaf->left;
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

template<class T>
node<T>* Tree<T>::LR(node<T> *leaf){
    leaf->right=LL(leaf->right);
    return RR(leaf);
}

template<class T>
node<T>* Tree<T>::RL(node<T> *leaf){
    leaf->left=RR(leaf->left);
    return LL(leaf);
}

template<class T>
node<T>* Tree<T>::RR(node<T> *leaf){
    node<T>* child=leaf->right;
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

template<class T>
node<T>* Tree<T>::min(node<T> *leaf){
    if(leaf==NULL) return NULL;
    else if(leaf->left==NULL) return leaf;
    else return min(leaf->left);
}

template<class T>
node<T>* Tree<T>::delData(node<T> *leaf,T data){
    if(leaf == NULL) return NULL;

    else if(data<leaf->data) //Go left if data is less than
        leaf->left=delData(leaf->left, data);
    else if(data>leaf->data) //Go right if data is greater than
        leaf->right=delData(leaf->left, data);
    else if(leaf->left!=NULL&&leaf->right!=NULL){
        node<T>* temp=min(leaf->right);
        leaf->data=temp->data;
        leaf->right=delData(leaf->right,leaf->data);
    }else{   
        node<T>* temp=leaf;
        if(leaf->left==NULL)
            leaf=leaf->right;
        else if(leaf->right==NULL)
            leaf=leaf->left;
        delete temp;
    }if(leaf==NULL)
        return leaf;
    int hLeft=height(leaf->left),hRight=height(leaf->right);
    if(hLeft>hRight) leaf->height=hLeft+1;
    else leaf->height=hRight+1;
    leaf=balance(leaf);
    return leaf;
}

template<class T>
node<T>* Tree<T>::balance(node<T> *leaf){
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

template<class T>
void Tree<T>::inorder(node<T> *leaf){
    if(leaf!=NULL){
        inorder(leaf->left);
        cout<<leaf->data<<endl;
        inorder(leaf->right);
    }
}

template<class T>
void Tree<T>::preorder(node<T> *leaf){
    if(leaf!=NULL){
        cout<<leaf->data<<endl;
        preorder(leaf->left);
        preorder(leaf->right);
    }
}

template<class T>
void Tree<T>::postorder(node<T> *leaf){
    if(leaf!=NULL){
        postorder(leaf->left);
        postorder(leaf->right);
        cout<<leaf->data<<endl;
    }
}
#endif /* TREE_H */