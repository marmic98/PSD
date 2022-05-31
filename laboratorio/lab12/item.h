typedef struct myItem* item;

item createItem(int x, int key);
item inputItem();
void printItem(item i);
void printItemChar(item i);
int cmpValue(item, item);
int cmpKey(item, item);
void swap(item*, item*);
int  getValue(item i);
int getKey(item i);
item setValue(item i, int val);
item setKey(item i, int key);