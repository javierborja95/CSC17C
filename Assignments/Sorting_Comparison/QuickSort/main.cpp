/* 
 * File:   main.cpp
 * Author: Javier Borja
 * sort from http://www.geeksforgeeks.org
 * Created on November 15, 2017, 12:00 PM
 * Purpose: Quick Sort
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
void swap(int*,int*);
void quickSort(int [],int,int);
int partition (int [],int,int);
//Execution

int main(int argc, char** argv) {
    //Seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    int n=1000;
    int arr[n];
    
    //Input Data
    fill(arr,n);
    //Process Data
    quickSort(arr,0,n-1);
    //Output Data
    disp(arr,n);
    
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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}