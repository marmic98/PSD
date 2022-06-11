#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "btree.h"
#include "item.h"

BST inputStortissima(int* a, int size){
    BST b = newBST();
    for(int i = 0; i < size; i++){
        b  =insert(b, createItem(a[i]));
    }
    return b;
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

BST inputBSTFromArray(BST t, int* a, int inf, int sup){
    if(inf > sup)
        return newBST();
    int middle = (inf + sup)/2;
    t = insert(t, createItem(a[middle]));
    inputBSTFromArray(t, a, inf, middle-1);
    
    inputBSTFromArray(t, a, middle + 1, sup);
    
    return t;
}

BST buildTree(int* a, int inf, int sup){
    if (inf > sup)
        return newBST();
     int middle = (inf + sup)/2;
    return consBtree(createItem(a[middle]), buildTree(a, inf, middle-1), buildTree(a, middle+1, sup));
}

int altezzaTree(BST b){
    if (emptyBST(b))
        return 0;
    int lh = altezzaTree(figlioSX(b))+1;
    int rh = altezzaTree(figlioDX(b))+1;
    if(lh > rh)
        return lh;
    else 
        return rh;
}

int isAVL(BST b){
    return abs(altezzaTree(figlioSX(b)) - altezzaTree(figlioDX(b))) <= 1;
}

int iskBalanced(BST b, int k){
    return abs(altezzaTree(figlioSX(b)) - altezzaTree(figlioDX(b))) <= k;
}

void printFoglie(BST b){
    if (emptyBST(b))
        return;
    if (emptyBST(figlioSX(b)) && emptyBST(figlioDX(b)))
        printItem(getItem(getRoot(b)));
    printFoglie(figlioSX(b));
    printFoglie(figlioDX(b));
}

void printFoglieOnLevel(BST b, int k, int lv){
    if (k > lv)
        return;
    if (emptyBST(b))
        return;
    if (k == lv){
        if (emptyBST(figlioSX(b)) && emptyBST(figlioDX(b))){
            printItem(getItem(getRoot(b)));
            return;
        }
    }
    else{
        printFoglieOnLevel(figlioDX(b), k + 1, lv);
        printFoglieOnLevel(figlioSX(b), k + 1, lv);
    }
}

int nodeCounter (BST b){
    if (emptyBST(b))
        return 0;
    else 
        return nodeCounter(figlioDX(b)) + nodeCounter(figlioSX(b)) + 1;
}

int nodeCounterOnLevel (BST b, int i, int lv){
    if (emptyBST(b))
        return 0;
    if(i == lv)
        return 1;
    else
        return nodeCounterOnLevel(figlioSX(b), i+1, lv) + nodeCounterOnLevel(figlioDX(b), i+1, lv);        
}

void larghezza(BST b, int lv, int h, int* max){
    if(lv <= h){
        if(nodeCounterOnLevel(b, 1, lv) > *max)
            *max = nodeCounterOnLevel(b, 1, lv);
        larghezza(b, lv+1, h, max);
    }
    else 
        return;
}

void printOnLevel(BST b, int i, int lv){
   if (emptyBST(b))
        return;
   if (i < lv){
        printOnLevel(figlioSX(b), i+1, lv);
        printOnLevel(figlioDX(b), i+1, lv);
    }
    else{
        if(!emptyBST(b)){
            printItem(getItem(getRoot(b)));
        }
    }
        
}

void printLevels(BST b, int i , int h){
    if (i <= h){
        if(!emptyBST(b)){
            printf("livello %d ", i);
            printOnLevel(b, 1, i);
            printf("\n");
            printLevels(b, i+1, h);
        }
    }
    else 
        return;
}

int isLeaf(BST b){
    return emptyBST(figlioDX(b)) && emptyBST(figlioSX(b));
}

BST aggiungiFogliaSum(BST b, int sum){
    if (emptyBST(b))
        return newBST();
    if (isLeaf(b))
        return insert(b, createItem(sum + getValue(getItem(getRoot(b)))));
    else 
        sum += getValue(getItem(getRoot(b)));
    aggiungiFogliaSum(figlioSX(b), sum);
    aggiungiFogliaSum(figlioDX(b), sum);

    return b;
}

int hItem (BST b, item e, int i, int lv){
    if (emptyBST(b))
        return -1;
    if(cmp(getItem(getRoot(b)), e) == 0){
        return i;
    }
    else if(cmp(getItem(getRoot(b)), e) == -1){
        return hItem(figlioSX(b), e, i+1, lv);
    }
    else
        return hItem(figlioDX(b), e, i+1, lv);
}

int itemFogliaH(BST b, item e){
    return altezzaTree(b) - hItem(b, e, 1, altezzaTree(b));
}

BST potatura (BST b){
    if(emptyBST(b))
        return newBST();
    if (isLeaf(b))
       return b = deleteNode(b, getItem(getRoot(b)));
    potatura(figlioDX(b));
    potatura(figlioSX(b));
    return b;
        
}

int isFull(BST b){
    if (emptyBST(b))
        return 1;
    if((emptyBST(figlioSX(b)) && !emptyBST(figlioDX(b))) || (!emptyBST(figlioSX(b)) && emptyBST(figlioDX(b))))
            return 0;
    else
       return  isFull(figlioDX(b)) && isFull(figlioSX(b));
}

int contaFoglie(BST b){
    if (emptyBST(b))
        return 0;    
    if (isLeaf(b))
        return 1;
    else 
        return contaFoglie(figlioDX(b)) + contaFoglie(figlioSX(b));
}



int main(){
    int a[7] = {0,1,2,3,4,5,6};
    BST b = newBST();
    //b = inputBSTFromArray(b, a, 0, 6);
    b = inputBSTFromArray(b, a, 0, 6);
    printBST(b, 3);
    
    printf("b is AVL? %s\n", isAVL(b) ? "si" : "no");
    int k = 7;
    printf("b is %d-balanced %s\n", k, iskBalanced(b, k) ? "si" : "no");
    printFoglieOnLevel(b, 1, 3);
    printf("\nnumero foglio sul livello 3 = %d\n", nodeCounterOnLevel(b, 1,3));
    int max = 0;
    printf("altezza = %d\n", altezzaTree(b));
    larghezza(b, 1, altezzaTree(b), &max);
    printf("larghezza = %d\n", max);
    //printOnLevel(b, 1, altezzaTree(b));
    printLevels(b,1,altezzaTree(b));
    //printBST(aggiungiFogliaSum(b, 0), 4);
    printf("distanza tra item 2 e le foglie = %d\n", itemFogliaH(b, createItem(2)));
    printf("is b full? %s\n", isFull(b) ? "si" : "no");
    printf("contafoglie %d\n", contaFoglie(b));
}