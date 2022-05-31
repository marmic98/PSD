#include "item.h"
#define NULLITEM 0

struct myItem{
    int val;
    int key
};


item createItem(int x, int key){
    item i = malloc(sizeof(struct myItem));
    if (i){
        i->val = x;
        i->key = key;
    }    
    return i; 
}

item inputItem(){
    item temp = malloc(sizeof(struct myItem));
    if (!temp)
        return NULLITEM;
    else{
        scanf("%d", &temp->val);
        scanf("%d", &temp->key);
        return temp; 
    }
}

int cmpVal(item a, item b){
    if (a->val == b->val)
        return 0;
    if (a->val < b->val)
        return 1;
    if (a->val > b->val)
        return -1;
}

int cmpKey(item a, item b){
    if (a->key == b->key)
        return 0;
    if (a->key < b->key)
        return 1;
    if (a->key > b->key)
        return -1;
}

void swap(item* a, item* b){
    item temp = *a;
    *a = *b;
    *b = temp;
}

void printItem(item i){
    printf("value: [%d]\nkey:   [%d]\n-\n", i->val, i->key);
}

int getValue(item i){
    return (i->val);
}

int getKey(item i){
    return (i->key);
}

item setValue(item i, int val){
    i->val = val;
    return (i);
}

item setKey(item i, int key){
    i->key = key;
    return (i);
}