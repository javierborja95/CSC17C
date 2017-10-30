/* File:   Table.h
 * Author: Javier Borja
 * Created on September 19, 2016, 10:15 AM
 * Purpose: Implementation for the Table
 */

#include "Table.h"

Table::Table(int szRow, int szCol){
    this->szRow=szRow;
    this->szCol=szCol;
    //Initialize Array
    records= new RowAray* [szRow];
    for(int i=0;i<szRow;i++){
        records[i]=new RowAray(szCol);
    }
}

Table::~Table(){
    for(int i=0;i<szRow;i++){
        delete records[i];
    }
    delete[] records;
}

int Table::getData(int r, int c){
    return records[r]->getData(c);
}