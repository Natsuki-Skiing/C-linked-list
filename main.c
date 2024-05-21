#include <stdio.h>
#include "linkedList.h"
int main(){
    list * testList = listNew();
    listAddNode(testList,1);
    listAddNode(testList,2);
    listAddNode(testList,3);
    listAddNode(testList,3);
    printf(" mean %f\n",listMean(testList));
    int megaAids = listDataSrch(testList,3);
    listGrow(testList);
    listDelElData(testList,3,1);
    return(0);
}