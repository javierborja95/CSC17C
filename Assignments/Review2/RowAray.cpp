/* 
 * File:   RowAray.h
 * Author: Javier Borja
 * Created on September 22, 2017 2:30 PM
 * Implementation for the RowAray
 */

//User Libraries
#include "RowAray.h"

RowAray::RowAray(unsigned int n){
    size=n;
    
    //Allocate Row
    rowData=new int[n];
    
    //Initialize Row
    for(int i=0;i<n;i++){
        rowData[i]=rand()%90+10;
    }
}

RowAray::~RowAray(){
    delete[] rowData;
}

void RowAray::setData(int c, int data){
    rowData[c] = data;
}