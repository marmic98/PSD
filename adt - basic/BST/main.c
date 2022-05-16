#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"

Btree inputBtree(){
    Btree sx = newBtree();
    Btree dx = newBtree();
    printf("Albero vuoto?\n");
    int choice = 0;
    scanf("%d", &choice);
    if (choice)
        return newBtree();
    printf("Fornisci etichetta: ");
    int x = 0;
    scanf("%d", &x);
    printf("creo albero sinistro\n");
    sx = inputBtree();
    printf("creo albero destro\n");
    dx = inputBtree();
        
    return consBtree(createItem(x), sx , dx);
}

int nodeCounter(Btree b){
    if(emptyBtree(b))
        return 0;
    else 
        return nodeCounter(figlioDX(b)) + nodeCounter(figlioSX(b)) + 1;
}

void printBTree(Btree b){
    if (emptyBtree(b)){
        printf("nil");
        return;
    }   
    else{
        printItem(getItem(getRoot(b)));
        
        printf("sx ");
        printBTree(figlioSX(b));
        printf("dx ");
        printBTree(figlioDX(b));
        
    }
}

int main(){
    Btree b = inputBtree();
    printBTree(b);
    printf("numero di nodi %d\n", nodeCounter(b));
}