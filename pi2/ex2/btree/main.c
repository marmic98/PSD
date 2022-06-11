#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"

int altezzaBTree(Btree b){
    if (emptyBtree(b))
        return 0;
    int lh = altezzaBTree(figlioSX(b)) + 1;
    int rh = altezzaBTree(figlioDX(b)) + 1;
    if(lh > rh)
        return lh;
    else
        return rh;
}

void printBTreeUtil(Btree b, int lv){
    if (emptyBtree(b))
        return;
    for(int i = 0; i < lv; i++)
        printf("   ");
    printItem(getItem(getRoot(b)));
    printf("\n");
    printBTreeUtil(figlioSX(b), lv+1);
    printBTreeUtil(figlioDX(b), lv+1);
}

void printBTree(Btree b){
    printBTreeUtil(b, altezzaBTree(b));
}

int fileLineCounter(char* fileName){
    FILE* fin = fopen(fileName, "r");
    if(!fin)
        return -1;
    int counter = 0;
    int c = 0;
    while (fscanf(fin, "%d", &c) == 1)
        counter++;
    fclose(fin);
    return counter;
}

int* inputArrayFromFile(char* fileName){
    int lines = fileLineCounter(fileName);
    FILE* fin = fopen(fileName, "r");
    if(fin){
        int i = 0;
        int *a = malloc(sizeof(int) * lines);
        while(fscanf(fin, "%d", &a[i]) == 1)
            i++;
        fclose(fin);
        return a;
    }
}

Btree inputBTreeFromArray(int *a, int i, int size){
    if(i >= size)
        return newBtree();
    return consBtree(createItem(a[i]), inputBTreeFromArray(a, 2*i+1, size), inputBTreeFromArray(a, 2*i+2, size));
}

int isLeaf(Btree b){
    return emptyBtree(figlioDX(b)) && emptyBtree(figlioSX(b));
}

int contaFoglie(Btree b){
    if (emptyBtree(b))
        return 0;
    if (isLeaf(b))
        return 1;
    else
        return contaFoglie(figlioSX(b)) + contaFoglie(figlioDX(b)); 
}

void printFoglie(Btree b){
    if(emptyBtree(b))
        return;
    if (isLeaf(b)){
        printItem(getItem(getRoot(b)));
        return;
    }
    printFoglie(figlioSX(b));
    printFoglie(figlioDX(b));
}

Btree speculare(Btree b){
    if(emptyBtree(b))
        return newBtree();
    return consBtree(getItem(getRoot(b)), speculare(figlioDX(b)), speculare(figlioSX(b)));
}

item maxBtree(Btree b){
    if(emptyBtree(b))
        return createItem(-1000);
    item max = getItem(getRoot(b));
    item maxl = maxBtree(figlioSX(b));
    item maxr = maxBtree(figlioDX(b));
    if (cmp(max, maxr) == 1)
        max = maxr;
    if (cmp(max, maxl) == 1)
        max = maxl;
    return max;
}

item minBtree(Btree b){
    if(emptyBtree(b))
        return createItem(1000);
    item min = getItem(getRoot(b));
    item minl = minBtree(figlioSX(b));
    item minr = minBtree(figlioDX(b));
    if (cmp(min, minr) == -1)
        min = minr;
    if (cmp(min, minl) == -1)
        min = minl;
    return min;
}

int 
areEqBtree(Btree b1, Btree b2){
    if (emptyBtree(b1) && emptyBtree(b2))
        return 1;
    if (cmp(getItem(getRoot(b1)), getItem(getRoot(b2))) == 0)
        return areEqBtree(figlioSX(b1), figlioSX(b2)) && areEqBtree(figlioDX(b1), figlioDX(b2));
    else 
        return 0;
}

Btree addNode(Btree b, item e, int* flag){     
    if (*flag == 1)
        return b;
    if(emptyBtree(b))
        return newBtree();

    if(!emptyBtree(figlioDX(b)) && !emptyBtree(figlioSX(b)))
        return b = consBtree(getItem(getRoot(b)), addNode(figlioSX(b), e, flag),addNode(figlioDX(b), e, flag));
            
    if(emptyBtree(figlioDX(b)) && !emptyBtree(figlioSX(b))){
        *flag = 1;
        return b = consBtree(getItem(getRoot(b)), figlioSX(b), consBtree(e, newBtree(), newBtree()));
    }
    if(!emptyBtree(figlioDX(b)) && emptyBtree(figlioSX(b))){
        *flag = 1;
        return b = consBtree(getItem(getRoot(b)), consBtree(e, newBtree(), newBtree()), figlioDX(b));
    }
    if (isLeaf(b)){
        *flag = 1;
        return b = consBtree(getItem(getRoot(b)), consBtree(e, newBtree(), newBtree()),newBtree());
    }       
}

Btree aggiungiNodo(Btree b, item e){
    int flag = 0;
    return addNode(b, e, &flag);
}

int isBST(Btree b){
    if(emptyBtree(b))
        return 1;
    if(getValue(getItem(getRoot(b))) < getValue(maxBtree(figlioSX(b))) || getValue(getItem(getRoot(b))) > getValue(minBtree(figlioDX(b))))
        return 0;
    else
        return isBST(figlioSX(b)) && isBST(figlioDX(b)); 
}

Btree inputFromSortedArray(Btree b, int *a, int inf, int sup){
    if (inf > sup)
        return newBtree();
    int middle = (inf + sup)/2;

    return  consBtree(createItem(a[middle]), inputFromSortedArray(b, a, inf, middle-1), inputFromSortedArray(b, a, middle+1, sup));
}

int main(){
    Btree b1 = inputBTreeFromArray(inputArrayFromFile("input.txt"), 0, fileLineCounter("input.txt"));
    //Btree b2 = inputBTreeFromArray(inputArrayFromFile("input2.txt"), 0, fileLineCounter("input2.txt"));
    int a[7] = {0,1,2,3,4,5,6};
    Btree b2 = inputFromSortedArray(b2, a, 0, 6);
    printf("b1\n");
    printBTree(b1);
    printf("b2\n");
    printBTree(b2);
    printf("is b1 BST? %s\n", isBST(b1) ? "si" : "no");
    printf("is b2 BST? %s\n", isBST(b2) ? "si" : "no");

    printf("%d %d\n%d %d", getValue(minBtree(b1)), getValue(minBtree(b2)), getValue(maxBtree(b1)), getValue(maxBtree(b2)));
    //printBTree(b1);
    //printBTree(b2);
    // printf("foglie = %d\n", contaFoglie(b));
    // printFoglie(b);
    //printf("speculare\n");
    //printBTree(speculare(b));
    //printf("minimo = %d\n", minBtree(b));
    //printf("massimo = %d\n", maxBtree(b));
    //printf("b1 == b2? = %s\n", areEqBtree(b1, b2) ? "si" : "no");
    //printBTree(aggiungiNodo(b1, createItem(3)));
}