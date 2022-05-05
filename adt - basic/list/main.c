#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

list inputList(int n){
    list l = newList();
    for(int i = 0; i < n; i++){
        printf("Fornisci elemento: ");
        int x = 0;
        scanf("%d", &x);
        l = consList(createItem(x), l);
    }
    return l;
}

void printList(list l){
    while(!emptyList(l)){
        printItem(getFirst(l));
        printf("-->");
        l = tailList(l);
    }
    printf("nil\n");
}

int main(){
    list l = newList();

    l = inputList(4);
    //printList(l);
    list m = pari(&l);
    printList(m);
    printList(l);
    //list sl = subList(&l, 1, 2);
    //printList(sl);
    //printList(l);
}