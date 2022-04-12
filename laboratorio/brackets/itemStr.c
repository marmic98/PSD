#include "itemStr.h"
#include "stdio.h"
#include "stdlib.h"
#define NULLITEM 0

item inputItem(){
    item temp = malloc(sizeof(char));
    if (!temp)
        return NULLITEM;
    else{
        scanf("%c", &temp);
        return temp; 
    }
}

int equal(int a, int b){
    return a == b;
}

void swap(char* a, char* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void printItem(item i){
    printf("[%c] ", *i);
}

int eqBrackets(char a, char b){
    if (a=='(' && b==')')
        return 1;
    if (a=='{' && b=='}')
        return 1;
    if (a=='[' && b==']')
        return 1;
    return 0;
}

item chToItem(char c){
    item i = malloc (sizeof(char));
    if (i){
        i = &c;
        return (i);
    }
}

char itemToCh(item c){
    return *c;
    
}