#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#define NULLITEM 0

struct myItem{
    int val;
};

item1 cv(int x){
    item1 i = malloc(sizeof(int));
    *i = x;
    return i;
}

int retValue(item1 i){
    return *i;
}

void pv(item1 p){
    printf("%d", *p);
}

item createItem(int x){
    item i = malloc(sizeof(struct myItem));
    if (i)
        i->val = x;
    return i; 
}

item inputItem(){
    item temp = malloc(sizeof(struct myItem));
    if (!temp)
        return NULLITEM;
    else{
        scanf("%d", &temp->val);
        return temp; 
    }
}

int cmp(item a, item b){
    if (a->val == b->val)
        return 0;
    if (a->val < b->val)
        return 1;
    if (a->val > b->val)
        return -1;
}

void swap(item* a, item* b){
    item temp = *a;
    *a = *b;
    *b = temp;
}

void printItem(item i){
    printf("[%d]", i->val);
}

int getValue(item i){
    return (i->val);
}