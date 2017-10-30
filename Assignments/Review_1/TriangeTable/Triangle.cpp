/* File:   Table.h
 * Author: Javier B
 * Created on September 19, 2017, 10:05 AM
 * Purpose: Class Implementation File for Triangle array from Row Array
 */

#include "Triangle.h"

Triangle::Triangle(int row){
    szRow=row;
    records=new RowAray*[row];
    for(int i=0;i<row;i++){
        records[i]=new RowAray(i+1);
    }
}

Triangle::~Triangle(){
    for(int i=0;i<szRow;i++){
        delete records[i];
    }
    delete[] records;
}

int Triangle::getData(int r, int c){
    return records[r]->getData(c);
}