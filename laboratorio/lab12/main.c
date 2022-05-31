#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "PQueue.h"

item getMaxClient(PQueue p){
    return getMax(p);
}

item getMinClient(PQueue p){
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
PQueue insertHeapFromArray(item* a, int n){
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
        printItem(getMax(temp));
        insert(p, getMax(temp));
        deleteMax(temp);
    }
    printf("\n");
    free(temp);
}
//K < newK
int incrementaChiave(PQueue q, item k, item newK){
    if (getValue(k) >= getValue(newK))
        return 0;
    PQueue temp = newPQ();
    while(!emptyPQ(q)){
        if (getValue(k) != getValue(getMax(q)))
            insert(temp, getMax(q));
        deleteMax(q);
    }
    
    while(!emptyPQ(temp)){
        insert(q, getMax(temp));
        deleteMax(temp);
    }
    free(temp);
    return insert(q, newK);; 
}

int push(PQueue p, item i){
    if (getKey(getMax(p)) > getKey(i))
        i = setKey(i, getKey(getMax(p))+1);
    return insert(p, i);
}

int pop(PQueue p){
    return deleteMax(p);
}



int merge(PQueue q1, PQueue q2){
    
}

int main (){
    item a[6];
    a[0] = createItem(26, 81);
    a[1] = createItem(60, 1);
    a[2] = createItem(89, 2);
    a[3] = createItem(34, 3);
    a[4] = createItem(11, 4);
    a[5] = createItem(6, 5);
    PQueue p = insertHeapFromArray(a, 6);
    printHeap(p);
    printf("min: ");
    printItem(getMinClient(p));
    printf("\n");
    incrementaChiave(p, createItem(89, 2), createItem(97, 0));
    printHeap(p);
    printf("fake push\n");
    push(p, createItem(315, 7));
    printHeap(p);
    printf("fake pop\n");
    pop(p);
    printHeap(p);

 
}