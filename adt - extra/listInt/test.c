#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    printf("Fornire lunghezza della lista\n");
    int size  = 0;
    scanf("%d", &size);
    list l = createList(size);

    l = reverseList(l);
    printList(l);
    int pos, element;
    printf("\ninserisco elemento in posizione\nfornire elemento: ");
    scanf("%d",&element);
    printf("Fornire pos: ");
    scanf("%d",&pos);
    l = insertList(l, element, pos);
    printList(l);

    printf("\nordino l\n");
    l = sort(l);
    printList(l);


    printf("\nelimino elemento in pos\n");
    printf("Fornire elemento da eliminare: ");
    scanf("%d",&element);
    l = removeListItem(l, element);
    printList(l);
}