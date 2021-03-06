#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "list.h"

int main(){
    int n;
    printf("Fornire numero di elementi da inserire nella lista\n");
    scanf("%d", &n);
    list l = createList(n);
    system("clear");
    l = reverseList(l);
    printf("Reverse list\n");
    printLista(l);
    
    printf("\nInserimento\n");
    float x, y;
    printf("Fornire ascissa: ");
    scanf("%f", &x);
    printf("Fornire ordinata: ");
    scanf("%f", &y);
    item p = creaPunto(x,y);

    int pos = 0;
    printf("In quale posizione vuoi inserire l'elemento?\n");
    scanf("%d", &pos);
    
    list l2 = insertListOpt(l, p, pos);
    printLista(l2);
    printf("p aggiunto presente: %d\n", searchItem(p, l2));
    printf("p aggiunto pos: %d\n", posItem(p, l2));
    
    list l3 = removeItemOpt(l2, p);
    printf("\nrimozione\n");
    printLista(l3); 
    
    list sorted = sorty(l3);
    printf("\nsort by y\n");
    printLista(sorted);
    list sortedx = sortx(l3);
    printf("\nsort by x\n");
    printLista(sortedx);
    
    // free(l);
    // free(l2);
    // free(l3);
    // free(sorted);
    // free(sortedx);

}