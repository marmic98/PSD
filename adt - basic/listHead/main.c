#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

// list cloneListClient(list l){
//     list cloned = newList();

//     if (emptyList(l))
//         return cloned;
    
//     list temp = newList();

//     while(!emptyList(l)){
//         insertList(temp, 0, getItem(l,0));
//         removeList(l, 0);
//     }

//     while(!emptyList(temp)){
//         insertList(l, 0, getItem(temp,0));
//         insertList(cloned, 0, getItem(l,0));
//         removeList(temp, 0);
//     }
//     free(temp);
//     return cloned;
// }

list reverseListClient(list l){
    int size = sizeList(l);
    if (size == 0)
        return l;
    
    list reverse = newList();
    for(int i = 0; i < size; i++)
        insertList(reverse, 0, getItem(l, i));
    
    return reverse;
}

list cloneListClient(list l){
    list cloned = newList();
    cloned = reverseListClient(l);
    cloned = reverseListClient(cloned);
}
// list reverseListClient(list l){
//     list reverse = newList();

//     if (emptyList(l))
//         return reverse;
    
//     list temp = newList();

//     while(!emptyList(l)){
//         insertList(temp, 0, getItem(l,0));
//         insertList(reverse, 0, getItem(l,0));
//         removeList(l, 0);
//     }

//     while(!emptyList(temp)){
//         insertList(l, 0, getItem(temp,0));
//         removeList(temp, 0);
//     }
//     free(temp);
//     return reverse;
// }

list inputList(int n){
    list l = newList();
    for(int i = 0; i < n; i++){
        printf("Fornisci elemento: ");
        int x = 0;
        scanf("%d", &x);
        insertList(l, 0, createItem(x));
    }
    return l;
}

void printList(list l){
    int size = sizeList(l);
    int i = 0;
    while(i < size){
        printItem(getItem(l,i));
        printf("-->");
        i++;
    }
    printf("nil\n");
}
//dato di riferiemnto: lista concatenata
//SPECIFICA SINTATTICA
//compatta(list) --> list
//SPECIFICA SEMANTICA
//compatta(l) = l1
//pre: l deve esistere 
//post: se l = nil allora l' = nil;
//      se l non è vuota e possiede delle occorrenze dello stesso valore allora l' sarà pari a l al netto delle occorrenze
//PROGETTAZIONE
//Se l è vuota restituimo una lista vuota
//Se le non è vuota
//  scorriamo la lista e per ogni elemento
//  se è uguale a quello successivo allora viene elminato 
//  altrimenti passa all'elemento successivo
// restituiamo la lista modificata
int compatta(list l){
    if (sizeList(l) < 2)
        return l;
    int counter = 0;
    int i = 0;
    while(i < sizeList(l)-1){
        if (cmp(getItem(l, i), getItem(l, i+1)) == 0){
            removeList(l, i);
            counter++;
        }
        else 
            i++;
    }
    return counter;
}

int compattaTot(list l){
    if (emptyList(l))
        return l;
    int i = 0, j = 1;
    int counter = 0;
    while(i < sizeList(l)-1){
        j = i+1;
        while(j < sizeList(l)){
            if (cmp(getItem(l, i), getItem(l, j)) == 0){
                removeList(l, j);
                counter++;
            }
            else 
                j++;
        }
    i++;
    }
    return counter;
}

list sort(list l){
    if (sizeList(l) < 2)
        return l;
    list temp = cloneListClient(l);
    list sorted = newList();

    int maxPos = 0;
    
    int i;
    while(!emptyList(temp)){
        i = 1;
        item max = createItem(getValue(getItem(temp, 0)));
        while(i < sizeList(temp)){
            if (cmp(max, getItem(temp, i)) == 1){
                maxPos = i;
                max = createItem(getValue(getItem(temp, i)));
            }
            i++;
        }
        insertList(sorted, 0, max);
        removeList(temp, maxPos);
        max = createItem(0);
        maxPos = 0;
    }
    return sorted;
}

list* paridispari (list l){
    if (emptyList(l))
        return NULL;
    list* a = malloc(sizeof(list)*2);
    if (a){
        a[0] = newList();
        a[1] = newList();
        int size = sizeList(l);
        for(int i = 0; i < size; i++){
            if (getValue(getItem(l, i)) % 2 == 0)
                insertList(a[0], 0, getItem(l, i));
            else 
                insertList(a[1], 0,getItem(l, i));
        }
        return a;
    }
}

int main(){
    list l = newList();
    // printf("Quanti item si disidera inserire nella lista? \n");
    // int n = 0;
    // scanf("%d", &n);
    // l = inputList(n);
    //printList(l);
    
    item1 test = cv(3);
    int x = retValue(test);
    printf("%d\n", x);
    pv(test);
    

    //printList(m);
    //printList(cloneListClient(l));
    //printList(reverseListClient(l));
    //int c = compatta(l);
    //printf("La lista e' stata compattata eliminando %d occorrenze\n", c);
    
    // int x = compattaTot(l);
    // printf("La lista e' stata compattata eliminando %d occorrenze\n", x);    
    // printList(l);
    //list sl = subList(&l, 1, 2);
    //printList(sl);
    //printList(l);
    // list sorted = sort(l);
    // printList(sorted);
    // list* a = paridispari(l);
    // printList(a[0]);
    // printList(a[1]);
}