#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "btree.h"
#include "item.h"

BST insertFromGenericArray(int* a, int size){
    BST b = newBST();
    for(int i = 0; i < size; i++)
        b = insert(b, createItem(a[i]));
    return b;
}

BST insertFromSortedArray(int *a, int i, int f){
    if (i > f)
        return newBST();
    int middle = (i+f)/2;
    return consBtree(createItem(a[middle]), insertFromSortedArray(a, i, middle-1), insertFromSortedArray(a, middle+1, f));
}

void printBST(BST b, int lv){
    if (emptyBST(b))
        return;
    for(int i = 0; i < lv; i++)
        printf("   ");
    printItem(getItem(getRoot(b)));
    printf("\n");
    printBST(figlioSX(b), lv+1);
    printBST(figlioDX(b), lv+1);
}

int kBalanced(BST b, int k){
    return (abs(altezza(figlioSX(b)) - altezza(figlioDX(b))) <= k);
}

void printLeaves(BST b){
    if (emptyBST(b))
        return;
    if (emptyBST(figlioSX(b)) && emptyBST(figlioDX(b)))
        printItem(getItem(getRoot(b)));
    
    printLeaves(figlioSX(b));
    printLeaves(figlioDX(b));
}

int isBothPresent(BST a, BST b){
    if (emptyBST(a))
        return 0;
    if(contains(b, getItem(getRoot(a))))
        return 1;
    else 
        return isBothPresent(figlioSX(a), b) || isBothPresent(figlioDX(a), b);
}

int isLeaf(BST b){
    return (emptyBST(figlioSX(b)) && emptyBST(figlioDX(b))); 
}

int sumNodes(BST b){
    if (emptyBST(b))
        return 0;
    else
        return sumNodes(figlioDX(b)) + sumNodes(figlioSX(b)) + getValue(getItem(getRoot(b)));       
}

int sumSubTree(BST b){
    return (sumNodes(figlioDX(b)) == sumNodes(figlioSX(b)));
}

int altezza(BST b){
    if (emptyBST(b))
        return 0;
    else {
        int l = altezza(figlioSX(b)) + 1;
        int r = altezza(figlioDX(b)) + 1;
        if (l < r)
            return r;
        else 
            return l;
    } 
}

int main(){
    int a[8] = {0,1,2,3,0,1,2};
    int c[7] = {6,8,9,10,11,12,13};
    BST b1 = newBST();
    b1 = insertFromSortedArray(a, 0, 6);
    BST b2 = newBST();
    b2 = insertFromSortedArray(c, 0, 6);
    printBST(b1, 0);
    int k = 0;
    if (k == 0)
        printf("b is %s-balanced? %s\n", "perfect", kBalanced(b1, k) ? "si" : "no");   
    else 
        printf("b is %d-balanced? %s\n",k, kBalanced(b1, k) ? "si" : "no");
    printLeaves(b1);
    printf("somma delle etichette di b1 = %d\n",sumNodes(b1));
    //printf("some of b1 is in b2? %s\n", isBothPresent(b1, b2) ? "si" : "no"); 

    printf("La somma dei valori dei sottoalberi e' la stessa? %s\n", sumSubTree(b1) ? "si" : "no");
}