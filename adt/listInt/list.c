#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node{
    item value;
    struct node* next;
};

//crea lista vuota
list newList(){
    return NULL;
}

//verifica se la lista l è vuota oppure no
int emptyList(list l){
    return l == NULL;
}

//restituisce la lista l senza il primo elemento
list tailList(list l){
    return l->next;
}

//inserisce un item e in testa alla lista
list consList(list l, item e){
    struct node* newNode = malloc(sizeof(struct node));
    if (!newNode){
        perror("");
        exit(-1);
    }
    newNode->value = e;
    newNode->next = l;
    l = newNode;
    return l;
}

//restituisce value del nodo in testa alla lista
item getFirst(list l){
    if (l != NULL)
        return l->value;
    else return 0;
}

//individua lunghezza lista
int sizeList(list l){
    int size = 0;
    while (l!=NULL){
        l = l->next;
        size++;
    }
    return size;  
}

//crea lista
list createList(int size){
    list l = newList();
    int e = 0;
    for (int i = 0; i < size; i++){
        printf("Fornisci item n%d\n", i+1);
        scanf("%d", &e);
        l = consList(l, e);
    }
    return l;
}

//stampa lista
void printList(list l){
    if (l == NULL)
        printf("Lista vuota\n");
    else{
        int size = sizeList(l);
        for (int i = 0; i < size; i++){
            printf("Item n%d = [%d]\n", i+1, l->value);
            l = l->next;
        }
    }
}

int searchItem(list l, item e){
    while(l->value != e && l != NULL){
        l=l->next;    
    }
    return l!=NULL;
}

int posItem(list l, item e){
    int pos = 0;
    int size = sizeList(l);
    while(pos < size && l->value != e){
        l=l->next; 
        pos++;   
    } 
    if (pos == size)//e non trovato
        return -1;
    
    return pos;
}

item getItem(list l, int pos){
    int size = sizeList(l);
    if (pos >= size)
        return 600;
    
    int i = 0;
    while (i < pos){
        l = l->next;
        i++;
    }
    return l->value;   
}

list reverseList(list l){
    list reverse = newList();
    while(l != NULL){
        reverse = consList(reverse, l->value);
        l = l->next;
    }
    return reverse;
}

list insertList(list l, item e, int pos){
    if (pos == 0)
        return l = consList(l, e); //inserimento in testa di e in l
    int size = sizeList(l);
    if (pos > size)
        return l;
    
    int i = 0;
    list l1 = l; 
    while (i < pos-1){
        l1 = l1->next;
        i++;
    }

    struct node* insNode = malloc(sizeof(struct node));
    insNode->value = e;
    insNode->next = l1->next;
    l1->next = insNode;

    return l; 
}

list removeList(list l, int pos){
    if (pos == 0){
        list l1 = tailList(l);;
        free(l1);
        return l1;

    } //rimozione elemento in testa
    int size = sizeList(l);
    if (pos > size)
        return l;
    
    int i = 0;
    list l1 = l;
    while (i < pos-1){
        printf("%d\n", i);
        l1 = l1->next;
        i++;
    }
    list toDelete = l1->next; 
    l1->next = toDelete->next;
    free(toDelete);
    return l; 
}

list removeListItem(list l, item e){
    int pos = posItem(l , e);

    if (pos == -1)
        return l; //elemento non presente
    
    int i = 0;
    list l1 = l;
    while (i < pos-1){
        l1 = l1->next;
        i++;
    }
    list toDelete = l1->next;
    l1->next = toDelete->next;
    free(toDelete);
    return l; 
}

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

list sort (list l){
    list i = l;
    while (i->next != NULL){//referiamo a next di i cosi da evitare di fare iterazioni in piu. Come fare fino a len-1
        list j = i->next;
        while(j != NULL){
            if (i->value > j->value)
                swap(&i->value, &j->value);
            j = j->next;
        }
        i = i->next;
    }
    return l;
}


