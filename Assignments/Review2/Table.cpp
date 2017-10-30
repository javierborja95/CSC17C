/* 
 * File:   Table.h
 * Author: Javier Borja
 * Created on September 22, 2017 2:30 PM
 * Implementation for the Table
 */

//User Libraries
#include "Table.h"

Table::Table(unsigned int r, unsigned int c){
    szRow=r;
    szCol=c;
    
    //Allocate rows
    columns= new RowAray*[r];
    
    //Allocate columns
    for(int i=0;i<r;i++){
        columns[i]= new RowAray(c);
    }
}

Table::Table(const Table& old){
    szRow=old.szRow;
    szCol=old.szCol;
    
    //Allocate rows
    columns= new RowAray*[szRow];
    
    //Allocate and initialize columns
    for(int i=0;i<szRow;i++){
        columns[i]= new RowAray(szCol);
        for(int j=0;j<szCol;j++){
            columns[i]->setData(j,old.getData(i,j));
        }
    }
}

Table::~Table(){
    //Deallocate memory
    for(int i=0;i<szRow;i++){
        delete columns[i];
    }
    delete[] columns;
}

int Table::getData(int r, int c) const{
    return columns[r]->getData(c);
}

void Table::setData(int r, int c, int data){
    columns[r]->setData(c,data);
}