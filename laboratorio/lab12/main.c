#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "PQueue.h"

//esiste getMax()
int getMinClient(PQueue p){
    PQueue temp = newPQ();
    item curr = 0;
    while(!emptyPQ(p)){
        curr = getMax(p);
        insert(temp, curr);
        deleteMax(p);    
    }
    while(!emptyPQ(temp)){
        insert(p, getMax(temp));
        deleteMax(temp);    
    }
    free(temp);
    return curr;
}
PQueue insertHeapFromArray(int* a, int n){
    PQueue p = newPQ();
    for(int i = 0; i < n; i++)
        insert(p, a[i]);
    return p;
}

void printHeap(PQueue p){
    PQueue temp = newPQ();
    while(!emptyPQ(p)){
        insert(temp, getMax(p));
        deleteMax(p);
    }//se esistesse l'operatore getSize non avremmo necessità di svuotare e riempire p
    while(!emptyPQ(temp)){
        printf("[%d] ",getMax(temp));
        insert(p, getMax(temp));
        deleteMax(temp);
    }
    printf("\n");
    free(temp);
}
//K < newK
int incrementaChiave(PQueue q, int k, int newK){
    if (k >= newK)
        return 0;
    PQueue temp = newPQ();
    while(!emptyPQ(q)){
        if (k != getMax(q))
            insert(temp, getMax(q));
        deleteMax(q);
    }
    
    while(!emptyPQ(temp)){
        insert(q, getMax(temp));
        deleteMax(temp);
    }

    insert(q, newK);
    free(temp);
    return 1; 
}

int push(PQueue p){
    //dubbio
}

int pop(PQueue p){
    deleteMax(p);
}

int merge(PQueue q1, PQueue q2){
    
}

int main (){
    int a[6] = {3,512,1,91,5,5};
    PQueue p = insertHeapFromArray(a, 6);
    printHeap(p);
    
    incrementaChiave(p, 91, 92);
    printHeap(p);
 
}