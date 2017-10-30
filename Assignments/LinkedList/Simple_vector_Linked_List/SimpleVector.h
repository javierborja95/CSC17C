// SimpleVector class template, Linked list version
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class Node{
    public:
        T data;
        int pos; //position in list
        struct Node<T> *next=NULL;
    };

template <class T>
class SimpleVector
{
private:
    
   int arraySize;       // Number of elements in the list
   void memError()const;// Handles memory allocation errors
   void subError()const;// Handles subscripts out of range
   Node<T> *head;

public:
   // Default constructor
   SimpleVector()
      {arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector<T> &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position)const;

   // Overloaded [] operator declaration
   T &operator[](const int &)const;
   
   void push_back(T); //Adds element to the end
   void pop_off();    //Removes ending element and shrinks array by one 
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    //Initialize list
   arraySize = 0;
   for(int i=0;i<s;i++){
       push_back(0);
   }
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    arraySize=0;
    // Copy the elements of obj's array.
    for(int i=0;i<obj.size();i++){
        push_back(obj.getElementAt(i));
    }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize <= 0)
      return;
    while(arraySize!=0){
        pop_off();
    }
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()const
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()const
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)const
{
    return (operator [](sub));
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)const
{
    if (sub < 0 || sub >= arraySize)
      subError();
    Node<T> *temp;
    temp=head;
    temp=temp->next;
    for(int i=0;i<sub;i++){
        temp=temp->next;
    }
    return temp->data;
}

template <class T>
void SimpleVector<T>::push_back(T nwElmnt){
    arraySize++;
    Node<T> *temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node<T> *nextNode=new Node<T>;
    if(nextNode==0)
        memError();
    nextNode->data=nwElmnt;
    temp->next=nextNode;
    nextNode->next=NULL;
}

template <class T>
void SimpleVector<T>::pop_off(){
    if(arraySize==0)return;
    Node<T> *temp=head;
    Node<T> *lastNode;
    for(int i=0;i<arraySize;i++){
        if(i==arraySize-1){
            lastNode=temp;
        }
        temp=temp->next;
    }
    delete temp;
    lastNode->next=NULL;
    arraySize--;
}
#endif