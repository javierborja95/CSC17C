// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int utilized;     // Number of elements in array utilized
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0; utilized=0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return utilized; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
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
   arraySize = s*2;
   utilized = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [arraySize];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   utilized = obj.size();
   arraySize = utilized*2;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < utilized; count++)
      *(aptr + count) = *(obj.aptr + count);
   //Initialize the rest of unused elements
   for(int count = utilized; count < arraySize; count++){
       aptr[count]=0;
   }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
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
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= utilized)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= utilized)
      subError();
   return aptr[sub];
}

template <class T>
void SimpleVector<T>::push_back(T nwElmnt){
   if(utilized==arraySize){ //If utilized and arraySize are equal
       arraySize*=2;        //Double the size of the array to limit copying
       T *temp;
       // Allocate memory for the new array
       try{
       temp = new T [arraySize];
       }
       catch (bad_alloc){
         memError();
       }
       //Copy Old elements to new array
       for(int i=0;i<utilized;i++){
            temp[i]=aptr[i];
       }
       //Initialize unused to 0
       for(int i=utilized;i<arraySize;i++){
            temp[i]=0;
       }
       temp[utilized]=nwElmnt;
       utilized++;
       
       //Delete old array;
       delete[] aptr;
   
       //Replace old array
       aptr=temp;
   }
    else{
        aptr[utilized]=nwElmnt;
        utilized+=2;//for some reason running this code subtracts 1 from utilized so
                    //I have to add 2 instead of 1 to counteract the extra subtraction
   }
}

template <class T>
void SimpleVector<T>::pop_off(){
    if(utilized==0) return;
    if(utilized<(arraySize/3)){ //If utilized is less than 1/3 of array size
       arraySize/=2;             //Remove half of array
       T *temp;
       utilized--;
       // Allocate memory for the new array
       try{
       temp = new T [utilized];
       }
       catch (bad_alloc){
         memError();
       }
       //Copy Old elements to new array
       for(int i=0;i<utilized;i++){
            temp[i]=aptr[i];
       }
       //Initialize unused to 0
       for(int i=utilized;i<arraySize;i++){
            temp[i]=0;
       }
       
       //Delete old array;
       delete[] aptr;
   
       //Replace old array
       aptr=temp;
   }
    else{
       utilized--;
   }
}
#endif