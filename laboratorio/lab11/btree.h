#include "item.h"

typedef struct node *Btree;

Btree newBtree(void);

int addNode(Btree T, item daInserire);

int emptyBtree(Btree T);

Btree figlioSX(Btree T);

Btree figlioDX(Btree T);

Btree consBtree(item val, Btree sx, Btree dx);

struct node *getRoot (Btree T);
