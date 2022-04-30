#include "item.h"
#define NULLITEM 0

struct myItem{
    int val;
};


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

int equal(item a, item b){
    return a->val == b->val;
}

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void printItem(item i){
    printf("[%d] ", i->val);
}

int getValue(item i){
    return (i->val);
}