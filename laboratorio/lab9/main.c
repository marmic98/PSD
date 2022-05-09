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

int mcd(int m, int n, int d){
    if(d == n){
        return d;
    } 
    else if (d > n){
        d = m - n;
        return mcd(d, n, d);
    }
    else {
        d = n - d;
        return mcd(n, d, d);
    }
}

int MCD(int m, int n){
    if (m > n)
        return mcd(m, n, m - n);
    else
        return mcd(n, m, n - m);
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

int tart(int r, int c){
    if(r == c)//diagonale restituisce 1
        return 1;

    if (r < 3) //righe 1 e 2 restituisce 1
        return 1;

    if (c < 2)//colonne 1 restituisce 1
        return 1;
    else
        return tart(r-1, c-1) + tart(r-1, c);
}

int main(){
    list l = newList();

    l = consList(createItem(1), l);
    l = consList(createItem(2), l);
    l = consList(createItem(3), l);
    printf("size l = %d\n", sizeListRicursive(l));

    printf("quadrato = %d\n", ennesimoQuadrato(5));

    printf("mcd: %d\n", MCD(300, 16));

    printf("%s palindroma? %s\n","ingegni", palindroma("ingegni") ? "si" : "no");

    printf("tartaglia: %d\n", tart(14,3));
}

