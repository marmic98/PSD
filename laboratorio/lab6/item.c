#include <stdio.h>
#include "item.h"


int eq(item a, item b) {
   return a == b;
}

item createItem(int a){
    item i = malloc(sizeof(int));
    i = a;
    return i;
}

void input_item(item *x) {
    scanf("%d", x);
} 

void output_item(item x) {
    printf("(%d)-->", x);
} 

