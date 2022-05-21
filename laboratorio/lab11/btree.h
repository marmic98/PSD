#include "item.h"

typedef struct node *Btree;

Btree newBtree(void);

item getItem(Btree T);

int addNode(Btree T, item daInserire);

int emptyBtree(Btree T);

Btree figlioSX(Btree T);

Btree figlioDX(Btree T);

Btree consBtree(item val, Btree sx, Btree dx);

struct node *getRoot (Btree T);

void print2D(struct node *root);
