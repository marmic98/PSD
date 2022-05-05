#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"

#define NULLITEM 0
#define MAXCAT 300

struct node {
    item value;
    struct node *next;
};


list newList(void)
{
  return NULL;
}

int emptyList(list l)
{
  return l==NULL;
}

list consList(item val, list l)
{
  struct node* new;
  new = malloc(sizeof(*new));

  if(new)
  {
    new->value = val;
    new->next = l;
    l=new;
  }
  return l;
}

list tailList(list l)
{
  list temp;

  if(l)
  {
    temp = l->next;
  }
  else
  {
    temp = NULL;
  }

  return temp;
}

item getFirst (list l)
{
  item e;
  if(l)
  {
    e = l->value;
  }
  else
  {
    e = NULLITEM;
  }
}

int sizeList (list l)
{
  int n = 0;

  if(!l)
  
  {
    return n;
  }

  for(n = 0;!emptyList(l);n++)
  {
    l = tailList(l);
  }

  return n;

}

int posItem (list l, item val)
{
    if(emptyList(l))
    {
      return -1;
    }

    if(cmp(getFirst(l),val) == 0)
    {
      return 0;
    }
    else
    {
      int ris = posItem(tailList(l),val);
      if(ris==-1)
      {
        return -1;
      }
      else
      {
        return ris + 1;
      }
    }

}

item getItem (list l, int pos)
{
  item e;
  int i;

  if(pos>=sizeList(l))
  {
    return NULLITEM;
  }


  for(i=0;i<pos && !emptyList(l);i++)
  {
    l = tailList(l);
  }

  if(!emptyList(l))
  {
    e=getFirst(l);
  }
  else
  {
    e = NULLITEM;
  }

  return e;
}

list reverseList (list l)
{
  list rev;
  item val;

  rev=newList();

  while(!emptyList(l))
  {
    val = getFirst(l);
    rev = consList(val,rev);
    l = tailList(l);
  }

  return rev ;

}

void outputList (list l)
{
  item val;
  int size = sizeList(l);
  int i = 0;
  while(!emptyList(l)){
    val = getFirst(l);
    printItem(val);
    l = tailList(l);
  }
  printf("nil\n");
}

list insertList(list l,int pos,item val)
{
  int i;
  list l1,prec=l;

  if(pos==0)
  {
    return consList(val,l);
  }

  for(i=0;i<pos-1&& prec; i++)
  {
    prec =prec->next;
  }

  if(!prec)
  {
    return l;
  }

  l1 = consList(val,prec->next);
  prec->next = l1;

  return l;
}

list removeList(list l,int pos)
{
  list l1,prec;
  int i;

  if(pos==0 && l)
  {
    l1=l;
    l=tailList(l);
    free(l1->value);
    free(l1);
  }
  else
  {
    prec = l;
    for(i=0;i<pos-1 && prec ;i++)
    {
      prec = prec->next;
    }

    if(prec && prec->next)
    {
      l1=prec->next;
      prec->next = l1->next;
      free(l1->value);
      free(l1);
    }
  }

  return l;
}

char* concatena(list l){
  if (l == NULL)
    return NULL;
  
  char* cat = malloc(MAXCAT);
  if (!cat)
    return NULL;
  struct node* temp = l;
  while(temp != NULL){
    strcat(cat, getStr(temp->value));
    temp = temp->next;
  }
  return cat;
}

item *dueMinimo(list l){
  if (l == NULL) return NULL;

  item* minimi = malloc(sizeof(item)*2);
  minimi[0] = malloc(sizeof(item));
  minimi[1] = malloc(sizeof(item));
  struct node* temp = l;
  item minToSave = l->value;
  int i = 0;
  int pos = 0;
  while(temp != NULL){
    if (cmp(minToSave, temp->value) > 0){
      minToSave = temp->value;
      pos = i;
    }
    temp = temp->next;
    i++;
  }
  
  minimi[0] = minToSave;
  if (sizeList(l) < 2)
    return minimi;
  temp = l;
  temp = removeList(temp, pos);
  
  
  item min = l->value;
    
  while(temp != NULL){
    if (cmp(min, temp->value) > 0){
      min = temp->value;
    }
    temp = temp->next;
  }

  minimi[1] = min;
  l = insertList(l, pos, minToSave);                         
  free(temp);
  return minimi;
}