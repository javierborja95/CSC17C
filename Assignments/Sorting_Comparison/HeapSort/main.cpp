/* 
 * File:   main.cpp
 * Author: Javier Borja
 * sort from http://www.geeksforgeeks.org
 * Created on November 15, 2017, 12:00 PM
 * Purpose: Heap Sort
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <cstdlib>
#include <ctime>
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void fill(int[],int);
void disp(int[],int);
void heapSort(int [],int);
void heapify(int [],int,int);
//Execution

int main(int argc, char** argv) {
    //Seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    int n=10000000;
    int *arr=new int[n];
    
    //Input Data
    fill(arr,n);
    //Process Data
    heapSort(arr,n);
    //Output Data
    //disp(arr,n);
    
    delete[] arr;
    
    return 0;
}

void fill(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%900+100;
    }
}

void disp(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}