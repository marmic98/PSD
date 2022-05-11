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

void printBTree(Btree b){
    if (emptyBtree(b)){
        printf("nil\n");
        return;
    }   
    else{
        printItem(getItem(getRoot(b)));
        printf("\n");
        printf("sx ");
        printBTree(figlioSX(b));
        printf("dx ");
        printBTree(figlioDX(b));
    }
}

int main(){
    Btree b = inputBtree();
    printBTree(b);
}