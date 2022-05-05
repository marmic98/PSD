#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

list inputList(int n){
    list l = newList();
    char* s = malloc(sizeof(50));
    for(int i = 0; i < n; i++){
        printf("fornire stringa: ");
        l = consList(l, createItem());
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
    list l = NULL;
    l = inputList(4);
    printList(l);
}