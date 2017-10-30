/* File:   Table.h
 * Author: Javier B
 * Created on September 19, 2017, 10:05 AM
 * Purpose: Class Specification File for Triangle array from Row Array
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

//System Libraries

//User Libraries
#include "RowAray.h"

class Triangle{
    private:
        int szRow;
        RowAray **records;
    public:
        Triangle(int);
        ~Triangle();
        int getSzRow(){return szRow;}
        int getData(int,int);
};

#endif /* TABLE_H */

