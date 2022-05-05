typedef struct myItem* item;
typedef int* item1; 

item1 cv(int x);
void pv(item1);
int retValue(item1 i);
item createItem(int x);
item inputItem();
void printItem();
int cmp(item, item);
void swap(item*, item*);
int getValue(item i);