#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

#define NULLITEM 0

struct node {
    item value;
    struct node *next;
};


list newList(void){
    return NULL;
}

int emptyList(list l){
    return l==NULL;
}

list consList(item val, list l){
    struct node* new;
    new = malloc(sizeof(*new));

    if(new){
        new->value = val;
        new->next = l;
        l=new;
    }
    return l;
}

list tailList(list l){
    list temp;

    if(l){
        temp = l->next;
    }
    else{
        temp = NULL;
    }

    return temp;
}

item getFirst (list l){
    item e;
    if(l){
        e = l->value;
    }
    else{
        e = NULLITEM;
    }
}

int sizeList (list l){
    int n = 0;

    if(!l){
        return n;
    }

    for(n = 0;!emptyList(l);n++){
        l = tailList(l);
    }
    return n;
}

int posItem (list l, item val){
    if(emptyList(l)){
        return -1;
    }

    if(cmp(getFirst(l),val) == 0){
        return 0;
    }
    else{
        int ris = posItem(tailList(l),val);
        if(ris==-1){
            return -1;
        }
        else{
            return ris + 1;
        }
    }
}

item getItemList (list l, int pos){
    item e;
    int i;

    if(pos>=sizeList(l)){
        return NULLITEM;
    }


    for(i=0;i<pos && !emptyList(l);i++){
        l = tailList(l);
    }

    if(!emptyList(l)){
        e=getFirst(l);
    }
    else{
        e = NULLITEM;
    }

    return e;
}

list reverseList (list l){
    list rev;
    item val;

    rev=newList();

    while(!emptyList(l)){
        val = getFirst(l);
        rev = consList(val,rev);
        l = tailList(l);
    }
    return rev ;
}

void outputList (list l){
    item val;
    while(!emptyList(l)){
        val = getFirst(l);
        printItem(val);
        printf("-->");
        l = tailList(l);
    }
    printf("nil\n");
}

list insertList(list l,int pos,item val){
    int i;
    list l1,prec=l;

    if(pos==0){
        return consList(val,l);
    }

    for(i=0;i<pos-1&& prec; i++){
        prec =prec->next;
    }

    if(!prec){
        return l;
    }

    l1 = consList(val,prec->next);
    prec->next = l1;

    return l;
}

list removeList(list l,int pos){
    list l1,prec;
    int i;

    if(pos==0 && l){
        l1=l;
        l=tailList(l);
        free(l1->value);
        free(l1);
    }
    else{
        prec = l;
        for(i=0;i<pos-1 && prec ;i++){
            prec = prec->next;
        }

        if(prec && prec->next){
            l1=prec->next;
            prec->next = l1->next;
            free(l1->value);
            free(l1);
        }
    }
    return l;
}

list sortList(list l){
    for(list i = l; i->next != NULL; i = i->next){
        for(list j = i->next; j != NULL; j = j->next){
            if (cmp(i->value, j->value) == -1){
                swap(&i->value, &j->value);
            }
        }
    }
    return l;
}

list cloneList(list l){
    list cloned = NULL;

    if (l == NULL)
        return cloned;
   
    list temp = NULL;
    while(l){
        temp = consList(createItem(getValue(getFirst(l))), temp);
        l = l->next;
    }
    while(temp){
        cloned = consList(getFirst(temp), cloned);
        temp = temp->next;
    }
    return cloned;
}

list subList(list* l, int inf, int sup){
    if ((inf < 0) || (sup > sizeList(*l)))
        return NULL;
    if ((sup < 0) || (inf > sizeList(*l)))
        return NULL;
    
    if (emptyList(*l))
        return NULL;

    int i = 0;
    int size = sizeList(*l);
    list sL = NULL;
    list temp = *l;
    list app = NULL;
    while(i < inf){
        app = consList(temp->value, app);
        temp = temp->next;
        i++;
    }
    while(i <= sup){
        sL = consList(temp->value, sL);
        temp = temp->next;
        i++;
    }
    while(i < size){
        app = consList(temp->value, app);
        temp = temp->next;
        i++;
    }
    *l = reverseList(app);
    return reverseList(sL);
}

list pari(list *l){
    if (l == NULL)
        return NULL;
    list pari = NULL;
    list temp = *l;
    list dispari = NULL;
    while(temp){
        if (getValue(getFirst(temp)) % 2 == 0)
            pari = consList(getFirst(temp), pari);
        else 
            dispari = consList(getFirst(temp), dispari);
        temp = temp->next;
    }
    free(temp);
    *l = reverseList(dispari);
    return reverseList(pari);
}