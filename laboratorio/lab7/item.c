#include "item.h"
#define NULLITEM

item inputItem(){
    item temp = malloc(sizeof(int));
    if (!temp)
        return NULLITEM;
    else{
        scanf("%d", &temp);
        return temp; 
    }
}

int equal(int a, int b){
    return a == b;
}

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void printItem(item i){
    printf("[%d] ", i);
}

