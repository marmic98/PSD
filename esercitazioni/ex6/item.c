#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define NULLITEM 0

struct myItem {
    int value;
};

item createItem(int x){
    item i = malloc(sizeof(struct myItem));
    if (!i)
        return NULLITEM;
    
    i->value = x;
    return i;
}

void printItem(item i){
    printf("(%d)-->", i->value);
}

int getValue(item i){
    return i->value;
}

int cmp (item a, item b){
    if (a->value < b->value) 
        return -1;
    if (a->value == b->value) 
        return 0;
    if (a->value > b->value) 
        return 1;
}