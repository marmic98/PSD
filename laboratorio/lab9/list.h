#include "item.h"

typedef struct node *list;
int sizeListRic(list l);
list newList(void);
int emptyList(list l);
list consList(item val, list l);
list tailList(list l);
item getFirst (list l);
int sizeList (list l);
int posItem (list l, item val);
item getItem (list l, int pos);
list reverseList (list l);
void outputList (list l);
list removeList(list l,int pos);
list cloneList(list l);
list insertList(list l,int pos,item val);
list sortList(list l);
list subList(list* l, int inf, int sup);
list pari(list *l);