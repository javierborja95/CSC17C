/* 
 * File:   Table.h
 * Author: Javier Borja
 * Purpose: Arrays and tables template
 * Created on October 4, 2017, 10:30 AM
 */

#ifndef TABLE_H
#define TABLE_H

#include <cstdlib>

template <class T>
class AbsRow{
    protected:
        int size;
        T *rowData;
    public:
        virtual int getSize()const = 0;
        virtual T getData(int)const = 0;
};

template <class T>
class RowAray:public AbsRow<T>{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int getSize()const{return this->size;}
        T getData(int i)const{
            if(i>=0&&i<this->size)return this->rowData[i];
            else return 0;}
        void setData(int,T);
};

template <class T>
RowAray<T>::RowAray(unsigned int n){
    this->size=n;
    
    //Allocate Row
    this->rowData=new T[n];
    
    //Initialize Row
    for(int i=0;i<n;i++){
        this->rowData[i]=rand()%90+10.0f;
    }
}

template <class T>
RowAray<T>::~RowAray(){
    delete[] this->rowData;
}

template <class T>
void RowAray<T>::setData(int c, T data){
    this->rowData[c] = data;
}

template <class T>
class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual T getData(int,int)const = 0;
};

template <class T>
class Table:public AbsTabl<T>{
    public:
        Table(unsigned int,unsigned int);
        Table(const Table &);
        virtual ~Table();
        int getSzRow()const {return this->szRow;}
        int getSzCol()const {return this->szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template <class T>
Table<T>::Table(unsigned int r, unsigned int c){
    this->szRow=r;
    this->szCol=c;
    
    //Allocate rows
    this->columns= new RowAray<T>*[r];
    
    //Allocate columns
    for(int i=0;i<r;i++){
        this->columns[i]= new RowAray<T>(c);
    }
}

template <class T>
Table<T>::Table(const Table& old){
    this->szRow=old.szRow;
    this->szCol=old.szCol;
    
    //Allocate rows
    this->columns= new RowAray<T>*[this->szRow];
    
    //Allocate and initialize columns
    for(int i=0;i<this->szRow;i++){
        this->columns[i]= new RowAray<T>(this->szCol);
        for(int j=0;j<this->szCol;j++){
            this->columns[i]->setData(j,old.getData(i,j));
        }
    }
}

template <class T>
Table<T>::~Table(){
    //Deallocate memory
    for(int i=0;i<this->szRow;i++){
        delete this->columns[i];
    }
    delete[] this->columns;
}

template <class T>
T Table<T>::getData(int r, int c) const{
    return this->columns[r]->getData(c);
}

template <class T>
void Table<T>::setData(int r, int c, T data){
    this->columns[r]->setData(c,data);
}

template <class T>
Table<T> Table<T>::operator +(const Table<T>& right){
    //Make new PlusTab
    Table<T> temp(this->szRow,this->szCol);
    
    for(int i=0;i<this->szRow;i++){
        for(int j=0;j<this->szCol;j++){
            //Add left element and right element
            temp.setData(i,j,(this->getData(i,j)+right.getData(i,j)));
        }
    }
    return temp;
}

#endif /* TABLE1_H */

