#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "stack.h"

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

int hightLevel(Btree b){
    if(emptyBtree(b))
        return 0;
    else{
        int l = hightLevel(figlioSX(b));
        int d = hightLevel(figlioDX(b));

        if(l < d)
            return d + 1;
        else 
            return l + 1;
    }
}

void preorder(Btree b){
    if (emptyBtree(b)){
        printf("nil");
        return;
    }   
    else{
        printItem(getItem(getRoot(b)));
        preorder(figlioSX(b));
        preorder(figlioDX(b));
        
    }
}

void postorder(Btree b){
    if (emptyBtree(b)){
        //printf("nil");
        return;
    }   
    else{
        postorder(figlioSX(b));
        postorder(figlioDX(b));
        printItem(getItem(getRoot(b)));
    }
}

void inorder(Btree b){
    if (emptyBtree(b)){
       // printf("nil");
        return;
    }   
    else{
        inorder(figlioSX(b));
        printItem(getItem(getRoot(b)));
        inorder(figlioDX(b));
    }
}

// Btree inputBtreeArray(int* a, int i, int n){
//     if (i > n)
//         return newBtree();
    
//     Btree sx = newBtree();
//     Btree dx = newBtree();
//     sx = inputBtreeArray(a, i+1, n);
//     dx = inputBtreeArray(a, i+2, n);
//     return consBtree(createItem(a[i]), sx, dx);
// }

void livello(Btree b, int level, int c){
    if(emptyBtree(b))
        return;
    if (level == c){
        printItem(getItem(getRoot(b)));
        return;
    }
    else{
        livello(figlioDX(b), level, c+1);
        livello(figlioSX(b), level, c+1); 
    }
}

int main(){
    //int a = {0,1,2,3,4,5,6,7,8,9}; 
    //Btree b = inputBtreeArray(a, 0, 10);
    Btree b = inputBtree();
    print2D(b);
    printf("numero di nodi: %d\n", nodeCounter(b));
    printf("altezza albero: %d\n", hightLevel(b));
    livello(b, 2, 1);
}