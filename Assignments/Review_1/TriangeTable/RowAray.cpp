/* File:   RowAray.h
 * Author: Javier Borja
 * Created on September 19, 2016, 10:15 AM
 * Purpose: Implementation for the RowAray
 */

#include <stdlib.h>
#include "RowAray.h"


RowAray::RowAray(int n){
    size=n;
    //Initialize Data
    rowData=new int[size];
    for(int i=0;i<size;i++){
        rowData[i]=rand()%90+10;
    }
}

RowAray::~RowAray(){
    delete[] rowData;
}