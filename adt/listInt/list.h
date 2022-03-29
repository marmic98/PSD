typedef int item; //non ncludo il item.h poichè int è primitivo e non ho previsto l'implentazione modulo...per ora
typedef struct node* list;

list newList();
int emptyList(list l);
list tailList(list l);
list consList(list l, item e);
item getFirst(list l);
int sizeList(list l);
list createList(int size);
void printList(list l);
int searchItem(list l, item e);
int posItem(list l, item e);
item getItem(list l, int pos);
list reverseList(list l);
list insertList(list l, item e, int pos);
list removeList(list l, int pos);
list removeListItem(list l, item e);
list sort (list l);