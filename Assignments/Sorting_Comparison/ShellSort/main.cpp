/* 
 * File:   main.cpp
 * Author: Javier Borja
 * sort from http://www.geeksforgeeks.org
 * Created on November 15, 2017, 12:00 PM
 * Purpose: Shell Sort
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void fill(int[],int);
void disp(int[],int);
void shellSort(int arr[], int n);
//Execution

int main(int argc, char** argv) {
    //Seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    int n=200000;
    int *arr=new int[n];
    
    //Input Data
    fill(arr,n);
    //Process Data
    auto start_time = chrono::high_resolution_clock::now();
    shellSort(arr,n);
    auto end_time = chrono::high_resolution_clock::now();
    cout<<chrono::duration_cast<chrono::microseconds>(end_time-start_time).count()<<":";
    //Output Data
    //disp(arr,n);
    
    delete[] arr;
    
    return 0;
}

void fill(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

void disp(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
}

void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}