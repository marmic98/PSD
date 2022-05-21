#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "BST.h"
#include "list.h"
#include "item.h"

BST insertFromArray(int* a, int n){
    BST b = newBST();
    for(int i = 0; i < n; i++)
        b = insert(b, createItem(a[i]));
    return b;
}

Btree inputBtreeFromArray(int* a, int i, int n){
    if (i < n)
        return consBtree(createItem(a[i]), inputBtreeFromArray(a, 2*i+1, n), inputBtreeFromArray(a, 2*i+2, n));
    else 
        return newBtree();
}

void printBTree(Btree b, int i, int h){
    if (i < h){
        for (int j = 0; j < i; j++)
            printf("   ");
        if (emptyBtree(b)){
            printf("[ ]\n");
            return;
        }
        printItem(getItem(getRoot(b)));
        printf("\n");
        printBTree(figlioSX(b), i+1, h);
        printBTree(figlioDX(b), i+1, h);
    }
    else
        return;
}

void printBST(BST b, int i, int h){
    if (i < h){
        for (int j = 0; j < i; j++)
            printf("   ");
        if (emptyBST(b)){
            printf("[ ]\n");
            return;
        }
            
        printItem(getItem(getRoot(b)));
        printf("\n");
        printBST(figlioSX(b), i+1, h);
        printBST(figlioDX(b), i+1, h);
    }
    else 
        return;
}

void nodiAltezzaK(BST b, list* a, int k, int j){
    if (emptyBST(b))
        return;
    if (k == j){
        *a = consList(getItem(getRoot(b)), *a);
        return;
    }
    else{
        nodiAltezzaK(figlioDX(b), a, k, j+1);
        nodiAltezzaK(figlioSX(b), a, k, j+1);
    }       
}

int isBst(Btree t){
    if(emptyBtree(t))
        return 1;
    if(!emptyBtree(figlioSX(t))){
        if(cmp(getItem(getRoot(t)), getItem(getRoot(figlioSX(t)))) == 1)
            return 0;
    }
    if(!emptyBtree(figlioDX(t))){
        if(cmp(getItem(getRoot(t)),getItem(getRoot(figlioDX(t)))) == -1)
            return 0;
    }
    return (isBst(figlioSX(t)) && isBst(figlioDX(t)));   
}

int altezza(Btree b){
    if (emptyBtree(b))
        return 0;
    else{
        int l = altezza(figlioSX(b));
        int r = altezza(figlioDX(b));
        if (l > r)
            return l+1;
        else 
            return r+1;
    }
}

void printInterval(BST root, int a , int b){
    if (emptyBST(root))
        return;

    if (a < getValue(getItem(getRoot(root))))
        printInterval(figlioSX(root), a, b); //prima di effettuare la stampa arrivo all'elemento più piccolo
    if ((a <= getValue(getItem(getRoot(root)))) && b >= getValue(getItem(getRoot(root)))){//se è compreso tra a e b allora lo stampa in modo crescente
        printItem(getItem(getRoot(root)));
        printf("\n");
    }
    printInterval(figlioDX(root), a, b); //controlliamo l'albero destro li stamperemo progressivamente poichè la chiamata esegue la riga 101 ed effettuare lo stesso contorllo che permette di partitre dal piu piccolo
}

int maxArrayRicorsivo(int *a, int i, int n){
    if (n == 1)
        return a[0];
    if (i < n){
        if (a[i] < maxArrayRicorsivo(a, i+1, n))
            return maxArrayRicorsivo(a, i+1, n);
        else 
            return a[i];
    }
}

int minArrayRicorsivo(int *a, int i, int n){
    if (n == 1)
        return a[0];
    if (i < n){
        if (a[i] > minArrayRicorsivo(a, i+1, n))
            return minArrayRicorsivo(a, i+1, n);
        else 
            return a[i];
    }
}

int main(){
    int a[9] = {15,10,20,2,4,5,21,0,120};
    // Btree b = newBtree();
    // b = inputBtreeFromArray(a, 0, 9);
    // printf("b altezza =  %d\n", altezza(b));
    // printBTree(b, 0, altezza(b));
    // printf("b e' un BST? %d\n", isBst(b));

    BST b = insertFromArray(a, 9);
    printBST(b, 0, altezza(b));
    printf("b e' un BST? %d\n", isBst(b));
    //print2D(b);
    list onLevK = newList();
    int i = 0;
    nodiAltezzaK(b, &onLevK, 3, 1);
    outputList(onLevK);
    printf("\n");
    printInterval(b, 1, 10);
    //printf("max = %d\n", maxArrayRicorsivo(a, 0, 9));
    //printf("min = %d\n", minArrayRicorsivo(a, 0, 9));
}