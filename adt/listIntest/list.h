#include "item.h"

typedef struct node *nodo;
typedef struct cList *list;

list newList(void);

int emptyList(list l);

nodo consList(item val, nodo l);

list tailList(list l);

item getFirst (list l);

int sizeList (list l);

int posItem (list l, item val);

item getItem (nodo l, int pos);

void outputList (list l);

int insertList(list l,item e, int pos);

int removeList(list l, int pos);

int getSizeList(list l);

nodo reverseNode(nodo l);

int reverseList(list l);
