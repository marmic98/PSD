typedef struct myItem* item;

item createItem(int x);
item inputItem();
void printItem();
int eq(item, item);
void swap(int*, int*);
int getValue(item i);