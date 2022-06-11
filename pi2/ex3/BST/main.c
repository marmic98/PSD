#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "BST.h"
#include "item.h"
#include "btree.h"

int altezzaBST(BST b){
    if (emptyBST(b))
        return 0;
    int lh = altezzaBST(figlioSX(b))+1;
    int rh = altezzaBST(figlioDX(b))+1;
}

void printBSTUtil(BST b, int lv){
    if (emptyBST(b))
        return;
    for(int i = 0; i < lv; i++)
        printf("   ");
    printItem(getItem(getRoot(b)));
    printf("\n");
    printBSTUtil(figlioSX(b), lv+1);
    printBSTUtil(figlioDX(b), lv+1);
}

void printBST(BST b){
    printBSTUtil(b, altezzaBST(b));
}

void printIntervallo(BST b, int a, int c){
    if (emptyBST(b))
        return;

    if(getValue(getItem(getRoot(b))) > a)
        printIntervallo(figlioSX(b), a, c);
    
    if(getValue(getItem(getRoot(b))) >= a && getValue(getItem(getRoot(b))) <= c)
        printItem(getItem(getRoot(b)));
    
    printIntervallo(figlioDX(b), a,c);
}

BST inputFromSortedArray(BST b, int *a, int inf, int sup){
    if (inf > sup)
        return newBST();
    int middle = (inf + sup)/2;

    b = insert(b, createItem(a[middle]));
    inputFromSortedArray(b, a, inf, middle-1);
    inputFromSortedArray(b, a, middle+1, sup);
    return b;
}

void nodiAltezzaK(BST b, item* a, int* counter, int i, int k){
    if(emptyBST(b) || i > k)
        return;
    if (i == k){
        //printItem(getItem(getRoot(b)));
        a[*counter] = getItem(getRoot(b));
        (*counter)++;
    }
        
    else{
        nodiAltezzaK(figlioSX(b),a, counter, i+1, k);
        nodiAltezzaK(figlioDX(b),a, counter, i+1, k);
    }
}

int nodeCounter(BST b){
    if(emptyBST(b))
        return 0;
    else 
        return nodeCounter(figlioSX(b)) + nodeCounter(figlioDX(b)) + 1; 
}

int mediano(BST b, item med){
    if(emptyBST(figlioSX(b)) && emptyBST(figlioDX(b)))
        return 0;
    if (getValue(getItem(getRoot(b))) == getValue(med))
        return nodeCounter(figlioSX(b)) == nodeCounter(figlioDX(b)); 
    else if (getValue(getItem(getRoot(b))) > getValue(med))
        return mediano(figlioSX(b), med);
    else
        return mediano(figlioDX(b), med);
}

int nodeCounterLessThenK(BST b, item k){
    if(emptyBST(b))
        return 0;
    if(getValue(getItem(getRoot(b))) == getValue(k))
        return nodeCounter(figlioSX(b));  
    else if (getValue(getItem(getRoot(b))) < getValue(k))
        return nodeCounter(figlioSX(b)) + nodeCounterLessThenK(figlioDX(b), k) + 1;
    else 
        return nodeCounterLessThenK(figlioSX(b), k);
}

void BSTtoList(BST b, list* l){
    if(emptyBST(b))
        return;
    else{
        *l = consList(getItem(getRoot(b)), *l);
        BSTtoList(figlioDX(b), l);
        BSTtoList(figlioSX(b), l);
    }
}

BST arrayToFoglie(BST b, int *a, int inf, int sup){
    if(inf > sup)
        return b;
    else{
        int middle = (inf + sup)/2;
        insert(b, createItem(a[middle]));
        arrayToFoglie(b, a, middle+1, sup);
        arrayToFoglie(b, a, inf, middle-1);
        return b;
    }
}

list subListRicursive(list l, list sl, int i, int a, int b){
    if(i > b)
        return sl;
    else if(i >= a && i <= b)
        return subListRicursive(tailList(l), consList(getFirst(l), sl), i+1, a, b);
    else 
        return sl = subListRicursive(tailList(l),sl, i+1, a, b);
}

list subListRicursive2(list l, int i, int a, int b){
    if(i > b)
        return NULL;
    else if(i >= a && i <= b)
        return consList(getFirst(l), subListRicursive2(tailList(l), i+1, a, b));
    else 
        return subListRicursive2(tailList(l), i+1, a, b);
}

int main(){
    int a[7] = {0,1,2,3,4,5,6};
    int arr[8] = {7,8,9,10,11,12,13,14};
    BST b = newBST();
    b = inputFromSortedArray(b, a, 0, 6);
    printBST(b);
    //printIntervallo(b, 3,5);
    printf("\n");
    item *test = malloc(sizeof(item) * 10);
    int counter = 0;
    // nodiAltezzaK(b, test,&counter, 1, 2);
    // for(int i = 0; i < counter; i++)
    //     printItem(test[i]);
    // printf("\n");
    // item med = createItem(3);
    // printf("%d e' mediano? %s\n",getValue(med), mediano(b,med) ? "si" : "no");
    // printf("nodi minori di k %d\n", nodeCounterLessThenK(b, createItem(4)));
    // list l = newList();
    // BSTtoList(b, &l);
    // outputList(sortList(l));
    //printBST(arrayToFoglie(b, arr, 0, 8));
    list l = newList();
    l = consList(createItem(0), l);
    l = consList(createItem(1), l);
    l = consList(createItem(2), l);
    l = consList(createItem(3), l);
    l = consList(createItem(4), l);
    outputList(l);
    outputList(subListRicursive2(l, 0, 2,4));
}