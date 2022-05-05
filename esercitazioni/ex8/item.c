#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define MAXDIM 50

item createItem(/*char* stringa*/){
    item temp = malloc(MAXDIM);        
    if (temp){
        scanf("%s", temp);
        return temp;
    }
    else 
        return NULL;
}

void printItem(item i){
    char* str = i;
    printf("%s", str);
}

item catValue(item a, item b){
    char* catStr = malloc(sizeof(strlen(a) + strlen(b)));
    if (catStr){
        strcat(a, b);
        item cat = createItem(catStr);
        return cat;
    }
    else 
        return NULL;
}

int cmp(item a, item b){
    return strcmp(a, b);
}

char* getStr(item i){
    char* str = malloc(sizeof(MAXDIM));
    if (str)
        return NULL;
    strcpy(str, i);
    return str;
}