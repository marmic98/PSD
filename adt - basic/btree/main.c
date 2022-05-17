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


int contaFoglie(Btree root){
    if (emptyBtree(root)) 
        return 0;
    if (emptyBtree(figlioSX(root)) && emptyBtree(figlioDX(root)))
        return 1;
    else 
        return contaFoglie(figlioDX(root)) + contaFoglie(figlioSX(root));
}

int nodeCounter(Btree b){
    if(emptyBtree(b))
        return 0;
    else 
        return nodeCounter(figlioDX(b)) + nodeCounter(figlioSX(b)) + 1;
}

Btree speculare (Btree root){
    if (emptyBtree(root))
        return;
    else if (emptyBtree(figlioSX(root)) && emptyBtree(figlioDX(root))){
        return consBtree(getItem(getRoot(root)), newBtree(), newBtree());
    }
    else if (!emptyBtree(figlioSX(root)) && !emptyBtree(figlioDX(root))){
        return consBtree(getItem(getRoot(root)), speculare(figlioDX(root)), speculare(figlioSX(root)));
    }
    else if (emptyBtree(figlioSX(root)) && !emptyBtree(figlioDX(root))){
        return consBtree(getItem(getRoot(root)), speculare(figlioDX(root)), newBtree());
    }
    else if (!emptyBtree(figlioSX(root)) && emptyBtree(figlioDX(root))){
        return consBtree(getItem(getRoot(root)), newBtree(), speculare(figlioSX(root)));
    }
}

int maxBTree(Btree b){
    if (emptyBtree(b))
        return;
    else {
        int max = getValue(getItem(getRoot(b))); 
        int sx = maxBTree(figlioSX(b));
        int dx = maxBTree(figlioDX(b));
        if (max < sx)
            return sx;
        else if (max < dx)
            return dx;
    }
}

int minBTree(Btree b){
    if (emptyBtree(b))
        return;
    else {
        int min = getValue(getItem(getRoot(b))); 
        int sx = maxBTree(figlioSX(b));
        int dx = maxBTree(figlioDX(b));
        if (min > sx)
            return sx;
        else if (min > dx)
            return dx;
    }
}

int eqBTree(Btree b1, Btree b2){

    if(emptyBtree(b1) && emptyBtree(b2))
        return 1;
    if (getValue(getItem(getRoot(b1))) != getValue(getItem(getRoot(b2))))
        return 0;
    else{
        int eqSx =  eqBTree(figlioSX(b1), figlioSX(b2));
        int eqDx =  eqBTree(figlioDX(b1), figlioDX(b2));
        if ((eqSx && eqDx))
            return 1;
    }
}

void aggiungiNode(Btree b, item e, int* inserito){
    if(*inserito)
        return;
    
    if (emptyBtree(figlioSX(b)) || emptyBtree(figlioDX(b))){
        addNode(b, e);
        *inserito = 1;
        return;
    }
    aggiungiNode(figlioSX(b), e, inserito);
    aggiungiNode(figlioDX(b), e, inserito);
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

Btree RinputBtree(int i,FILE *fcon, int dim){
    int num;

    float f=roundf(log2f(dim+1))-1;

    if(i > f || feof(fcon)){
        return NULL;
    }

    fscanf(fcon, "%d\n", &num);
    item t = createItem(num);

    return consBtree(t, RinputBtree(i+1, fcon, dim), RinputBtree(i+1, fcon, dim));
}


int fileLineCounter(char* finName){
    FILE* fin = fopen(finName, "r");
    if (fin == NULL)
        return -1;
    int size = 0;
    int x = 0;
    while(fscanf(fin, "%d", &x) == 1) size++;
    fclose(fin);
    return size;
    
}
//funzione che legge da file n interi e riempie un albero
//binario in modo uniforme
Btree inputBtreeFile(char *path_name){
    FILE *fcon= fopen(path_name, "r");
    printf("il file ha %d numeri\n", fileLineCounter(path_name));

    Btree new = RinputBtree(0, fcon, fileLineCounter(path_name));

    fclose(fcon);
    return new;
}

int main(){
    //int a = {0,1,2,3,4,5,6,7,8,9}; 
    //Btree b = newBtree();
    //b = inputBTreeFromArray(a, b, 0, 10);
    Btree b1 = inputBtreeFile("input1.txt");
    print2D(b1);

    Btree b2 = inputBtreeFile("input2.txt");
    print2D(b2);
    

    printf("alberi uguali? %d\n", eqBTree(b1, b2));
    
    // printf("numero di nodi: %d\n", nodeCounter(b1));
    // printf("numero di foglie: %d\n", contaFoglie(b1));
    // printf("altezza albero: %d\n", hightLevel(b1));
    // printf("speculatio\n");
    // print2D(speculare(b1));
    // livello(b1, 2, 1);
    // int flag = 0;
    // aggiungiNode(b1, createItem(666), &flag);
    // print2D(b1);
    // printf("\nmax albero: %d\n", maxBTree(b1));
    // printf("\nmin albero: %d\n", minBTree(b1));
}