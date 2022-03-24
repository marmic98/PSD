#include "punto.h"

typedef punto item;
typedef struct node* list;

list newList();
int emptyList(list l);
list consList(item val, list l);
list tailList(list l);
item getFirst(list l);
list createList(int n);
void printLista(list l);
int searchItem(item e, list l);
int posItem(item e, list l);
list reverseList(list l);
list removeList(list l, int pos);
list insertList(list l, item e, int pos);
list insertListOpt(list l, item e, int pos);
list removeListOpt(list l, int pos);
list removeItemOpt(list l, item e);
