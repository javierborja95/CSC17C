/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 15, 2017, 12:00 PM
 * Purpose: Merge Sort
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
void mergeSort(int [],int,int);
void merge(int [],int,int,int);

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
    mergeSort(arr,0,n-1);
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

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}