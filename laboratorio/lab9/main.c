#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"
#include <string.h>
int sizeListRicursive(list l){
    if (emptyList(l))
        return 0;
    else 
        return 1 + sizeListRicursive(tailList(l));
}

int ennesimoQuadrato(int n){
    if(n == 1)
        return 1;
    else 
        return ennesimoQuadrato(n-1) + (2*n-1);   
}

int pal(char* str, int i, int f){
    if(str[i] != str[f])
        return 0;
    if(i < f)
        return pal(str, i+1, f-1);
    
    return 1;
}

int palindroma(char* str){
    return pal(str, 0, strlen(str)-1);
}



int main(){
    list l = newList();

    l = consList(createItem(1), l);
    l = consList(createItem(2), l);
    l = consList(createItem(3), l);
    printf("size l = %d\n", sizeListRicursive(l));

    printf("quadrato = %d\n", ennesimoQuadrato(5));

    printf("%s palindroma? %s\n","ingegni", palindroma("ingehgni") ? "si" : "no");
}

