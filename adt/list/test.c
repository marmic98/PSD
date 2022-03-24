#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    int n;
    printf("Fornire numero di elementi da inserire nella lista\n");
    scanf("%d", &n);
    list l = createList(n);
    system("cls");
    l = reverseList(l);
    printf("Reverse list\n");
    printLista(l);
    
    printf("\nInserimento\n");
    item p = creaPunto(3, 3);
    //printf("elemento in pos: %d\n", posItem(p, l));
    list l2 = insertListOpt(l, p, 2);
    printLista(l2);
    printf("3 3 presente: %d\n", searchItem(p, l2));
    printf("3 3 pos: %d\n", posItem(p, l2));
    list l3 = removeListOpt(l2, 2);
    printf("\nrimozione\n");
    printLista(l3);
}