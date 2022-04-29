#include "item.h"
#include "list.h"

typedef struct lib* libretto; 

int cercaEsame(libretto l, char* es);
void inserisciEsame(libretto l, item e);
void printLibretto(libretto l);
libretto createLibretto();
list createListaEsami(list l, int n){