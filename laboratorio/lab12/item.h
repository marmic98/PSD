typedef struct myItem* item;

item createItem(int x, int key);
item inputItem();
void printItem();
int cmpValue(item, item);
int cmpKey(item, item);
void swap(item*, item*);
int  getValue(item i);
int getkey(item i);