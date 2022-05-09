#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"

Btree inputBtree(int n){
    Btree b = newBtree();
    for(int i = 0; i < n; i++){
        printf("Fornisci figlio sx: ");
        int sx = 0;
        scanf("%d", &sx);
        printf("Fornisci figlio dx: ");
        int dx = 0;
        scanf("%d", &dx);
        b = consBtree();
    }
    return b;
}



int main(){
    
}