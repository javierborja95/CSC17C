/* 
 * Author: Javier Borja
 * Created on September 22, 2017 2:30 PM
 * Implementation for the Table addition operator
 */

//User Libraries
#include "PlusTab.h"

PlusTab PlusTab::operator +(const PlusTab& right){
    PlusTab temp(szRow,szCol);
    
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            //Add left element and right element
            temp.setData(i,j,(getData(i,j)+right.getData(i,j)));
        }
    }
    return temp;
}