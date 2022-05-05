typedef struct myItem* item;

item createItem(int x);
item inputItem();
void printItem();
int cmp(item, item);
void swap(item*, item*);
int getValue(item i);