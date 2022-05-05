#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define NULLITEM 0

struct node {
     item value;
     struct node *next;
};

struct cList {
     struct node* first;
     int size;
};


list newList(){
     list l = malloc(sizeof(struct cList));
     if (l){
          l->first = NULL;
          l->size = 0;
          return l;
     }
     //la verifica che la lista sia null (non allocata a causa di fallimento malloc) è lasciata al cliente
}

item getItem(nodo l, int pos){
     nodo temp = l;
     int i = 0;
     while(temp != NULL && i < pos){
          i++;
          temp = temp->next;
     }
     if (temp != NULL){
          return temp->value;
     }
     else 
          return NULLITEM;
}

item getitemList(list l, int pos){
     item found = malloc(sizeof(item));
     found = getItem(l->first, pos);
     if(found){
          return found;
     }
     else return NULL;
     
}

int emptyList(list l){
     return l->size == 0;
}

static struct node* insertNode(struct node* l, int pos, item val){
     nodo new, prec = l;              
     int i = 0;
     new = malloc(sizeof(struct node));
     if (!new)   
          return NULL;
     new->value = val;
     
     if(pos == 0)  {        
          new->next = l;   
          return new; 
     }  
        
     while (i < pos-1 && prec!= NULL) {  
          prec = prec->next;
          i++;
     }

     if (prec == NULL)  {                    
          free(new);
          return NULL;
     }
     new->next = prec->next;
     prec->next = new;     
     return l;
}

int insertList (list l, int pos, item val){
     nodo tmp= insertNode(l->first, pos, val);
     if(tmp==NULL) 
          return 0;
     l->first = tmp;        
     l->size++;
     return 1;                  
}   



nodo removeNode(nodo l, int pos){     
    nodo l1;   
    if(pos == 0 && l != NULL) {   
        l1 = l;
        l = l->next;
        free(l1);
     }
     else {
        
          int i = 0;
          struct node* prec = l;         
          while (i < pos-1 && prec!= NULL) {   
                 prec = prec->next;
               i++;
          }

          if(prec != NULL && prec->next != NULL) { 
               l1 = prec->next;
               prec->next = l1->next;
               free(l1); 
          }
     }
     return l; 
}

int removeList (list l, int pos){     
     if (!l || l->first==NULL || l->size==0)   
          return 0;  
     l->first = removeNode(l->first,pos);
     l->size--;
     return 1;
}

void outputList(list l){
     for(int i = 0; i < l->size; i++){
          output_item(getItem(l->first, i));
     }
     printf("nil\n");
}

int reverseList(list l){
     nodo rev = reverseNode(l->first);
     if (!rev)
          return 0;
     else {
          l->first = rev;
          return 1;
     }
}

nodo reverseNode(nodo l){
     nodo temp = l;
     nodo rev = NULL;
     while(temp != NULL){
          rev = insertNode(rev,0,getItem(temp, 0));
          temp = temp->next;
     }
     return rev;
}

int searchItem(list l, item e){
     
}

