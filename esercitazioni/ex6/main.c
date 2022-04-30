#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

list inputListdaFile(list l, char* fInputName){
    FILE* fin = fopen(fInputName, "r");
    if(!fin)
        exit(-1);
    int x = 0;
    while(fscanf(fin, "%d", &x) == 1){
        item i = createItem(x);
        l = consList(i, l);
    }
    fclose(fin);
    return l;
}

int main (int argc, char *argv[]){
    int n = 0;
    list l1 = newList();
    list l2 = newList();

    l1 = inputListdaFile(l1, argv[1]);
    outputList(l1);

    l2 = inputListdaFile(l2, argv[2]);
    outputList(l2);

    //l = cancFinoItem(l, createItem(45));
    list nl = fondiDaItem(l1, l2, createItem(45));
    outputList(nl);
    return 0;
}