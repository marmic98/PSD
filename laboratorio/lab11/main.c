#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "BST.h"
#include "item.h"

Btree inputBtreeFromArray(int* a, int i, int n){
    if (i < n){
        return consBtree(createItem(a[i]), inputBtreeFromArray(a, 2*i+1, n), inputBtreeFromArray(a, 2*i+2, n));
    }
    else 
        return newBtree();
}

void printBTree(Btree b, int i, int h){
    if (i < h){
        for (int j = 0; j < i; j++)
            printf(" ");
        printItem(getItem(getRoot(b)));
        printf("\n");
        printBTree(figlioSX(b), i+1, h);
        printBTree(figlioDX(b), i+1, h);
        printf("\n");
    }
    else 
        return;
}

int isBST(Btree b){

}


int main(){
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    Btree b = newBtree();
    b = inputBtreeFromArray(a, 0, 10);
    printBTree(b, 0, 4);
    
}