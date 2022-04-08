#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "list.h"

#define NULLITEM 0

typedef punto item;

struct node {
    item value;
    struct node* next;
}node;

list newList(){
    return NULL;
}

int emptyList(list l){
    return l == NULL;
}

list consList(item val, list l){
    struct node* new = malloc(sizeof(struct node));
    if(new != NULL){
        new->value = val;
        new->next = l;
        l = new;
    }
    return l;
}

list tailList(list l){
    list temp;
    if(!emptyList(l)){
        temp = l->next;
    }
    else{
        temp = NULL;
    }
    return temp;
}

item getFirst(list l){
    item e;
    if (!emptyList(l)){
        e = creaPunto(ascissa(l->value), ordinata(l->value));
    }
    else{
       e = creaPunto(0,0);
    }
    return e;
}

int sizeList(list l){
    int n = 0;
    while(!emptyList(l)){
        n++;
        l = tailList(l);
    }
    return n;
}

list createList(int n){
    int i = 0;
    float x,y;
    list l = newList(l);
    while(i < n){
        printf("Fornire ascissa\n");
        scanf("%f", &x);
        printf("Fornire ordinata\n");
        scanf("%f", &y);
        item temp = creaPunto(x, y);
        l = consList(temp, l);
        i++;
    }
    return l;
}

void printLista(list l){
    int len = sizeList(l);
    for(int i = 0; i < len;i++){ 
        printf("Item n. %d [%g][%g]\n", i+1, ascissa(l->value), ordinata(l->value));
        l = tailList(l);
    }
    printf("\n");
}

int searchItem(item e, list l){
    while(!emptyList(l)){
        if (equal(e,getFirst(l)))
            return 1;
        else l = tailList(l);
    }
    return 0;
}

int posItem(item e, list l){
int pos = 0;
while(!emptyList(l)){
        if (equal(e, getFirst(l)))
            return pos;
        else{
            l = tailList(l);
            pos++;
        }
    }
    return -1; //-1 stands for item not found   
}

item getItem(list l, int pos){
    int i = 0;
    while (i < pos && !emptyList(l)){
        l = tailList(l);
        i++;
    }

    if (!emptyList(l))
        return getFirst(l);
    else 
        return NULLITEM;
}

list reverseList(list l){
    list rev = newList();
    while(!emptyList(l)){
        rev = consList(getFirst(l), rev);
        l = tailList(l);
    }
    return rev;
}

list insertList(list l, item e, int pos){
    int i = 0;
    list lnew = newList(); 
    list ltemp = newList();

    while(!emptyList(l) && i < pos){
        ltemp = consList(getFirst(l), ltemp);
        l = tailList(l);
        i++;
    }

    if (i == pos)
        lnew = consList(e, l);
    
    while (!emptyList(ltemp)){
        lnew = consList(getFirst(ltemp), lnew);
        ltemp = tailList(ltemp);
    }
    return lnew;
}

list removeList(list l, int pos){
    int i = 0;
    list ltemp = newList();
    list lnew = newList();

    while(i < pos && !emptyList(l)){
        ltemp = consList(getFirst(l), ltemp);
        l = tailList(l);
        i++;
    }

    if (i == pos)
        lnew = tailList(l);
    
    while(!emptyList(ltemp)){
        lnew = consList(getFirst(ltemp), lnew);
        ltemp = tailList(ltemp);
    }
    return lnew;
}

list insertListOpt(list l, item e ,int pos){
    if (pos==0)
        return consList(e, l);
    
    int i = 0;
    list l1 = l;
    
    while (i < pos-1 && !emptyList(l1)){
        l1 = l1->next;
        i++;
    }
    if (l1 == NULL)
        return l;

    list insNode = newList();
    insNode = consList(e, l1->next);
    l1->next = insNode;    
    return l;  
}

list removeListOpt(list l, int pos){
    list l1;
    if (pos==0){
        l1 = tailList(l);
        free(l->value);
        free(l);
        return(l1);
    }
    int i = 0;
    l1 = l;
    
    while (i < pos-1 && !emptyList(l1)){
        l1 = l1->next;
        i++;
    }
    if (l1 == NULL && l1->next == NULL) return l;
    
    list succ = l1->next;
    l1->next = l1->next->next;
    free(succ->value);   
    free(succ);
    return l;  
}

list removeItemOpt(list l, item e){
    int i = 0;
    if (equal(l->value, e))
        return tailList(l);
    list lApp = newList(); //secondo elemento della lista
    list temp = newList();
    lApp = tailList(l); //secondo elemento della lista
    temp = tailList(lApp);
    while(!emptyList(temp)){
        if (equal(temp->value, e)){
            lApp->next = lApp->next->next;
            free(temp);
            return l;
        }
        else{
            lApp = lApp->next;
            temp = lApp->next->next;
        }  
    }
    if (temp == NULL)
    return l;
}

list sorty (list l) {

    list i;
    list j; 
    item temp;

    i = l;
    while (i->next != NULL) {
        j = i->next;
        while(j != NULL){
            if (!lessy(i->value, j->value)){
                temp = (i->value);
                i->value = j->value;
                j->value = temp;
                
            }
            j = j->next;
        }
    i = i->next;
    }
    return(l);
}

list sortx(list l) {

    list i;
    list j; 
    item temp;

    i = l;
    while (i->next != NULL) {
        j = i->next;
        while(j != NULL){
            if (!lessx(i->value, j->value)){
                temp = (i->value);
                i->value = j->value;
                j->value = temp;
                
            }
            j = j->next;
        }
    i = i->next;
    }
    return(l);
}

void freeList(list l){
    while(l != NULL){
        list temp = l;
        l = l->next;
        free(temp->value);
        free(temp);
    }
}