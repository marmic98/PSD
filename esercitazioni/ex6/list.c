#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

#define NULLITEM 0

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

list cancFinoItem(list l, item i){
  if (l == NULL)
    return l;

  while(l != NULL && cmp(l->value, i) != 0){
      struct node* p = l;
      l = l->next;
      free(p);
      free(p->value);
    }
  return l;
}

list fondiDaItem(list l1, list l2, item i){
  if (l1 == NULL || l2 == NULL)
    return NULL;
  
  l1 = cancFinoItem(l1, i);
  l2 = cancFinoItem(l2, i);
  
  if (l1 == NULL|| l2 == NULL)
    return NULL;

  struct node* temp1 = l1;
  struct node* temp2 = l2;
  list nL = newList();
  while(temp1){
    while(temp2){
      if (cmp(temp1->value, temp2->value) == 0){
          nL = consList(temp1->value, nL); 
      }
      temp2 = temp2->next;
    }
    temp2 = l2;
    temp1 = temp1->next;
  }
  return nL;
}