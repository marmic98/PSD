typedef struct myItem* item;

item createItem (int x);
void printItem (item i);
int cmp (item a, item b);
int getValue(item i);