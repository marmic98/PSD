#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

list inputList(list l, int n){
    item it;
    for(int i = 0; i < n; i++){
        input_item(&it);
        l = consList(it, l);
    }   
    return l;
}

int searchItem(list l, item e) {
    list temp = newList();
    temp = l;
    while(!emptyList(temp)){
        if (eq(e, getFirst(temp)))
            return 1;
        else temp = tailList(temp);
    }
    return -1;
}

int searchItemPos(list l, item e){
    list temp = newList();
    temp = l;
    int pos=0;
    while(!emptyList(temp)){
        if (eq(e, getFirst(temp)))
            return pos;
        else {
            temp = tailList(temp);
            pos++;
        }
    }
    return -1;
}

list switchCoppie(list l){
    list temp = l;
    list outlist = newList();
    if(sizeList(l) < 2){
        return NULL;
    }else{    
        temp = reverseList(temp);
        while(!emptyList(temp)){
            item tempItem = createItem(getFirst(temp));
            temp = tailList(temp);
            outlist = consList(getFirst(temp), outlist);
            outlist = consList(tempItem, outlist); 
            temp = tailList(temp);
        }
        return outlist;
    }
}

list removeMiddleItem(list l){
    return l = removeList(l, (sizeList(l)-1)/2);
}

int main (int argc, char *argv[]){
    int n = 0;
    list l = newList();
    
    printf("Fornire numero elementi della lista\n");
    scanf("%d", &n);

    l = inputList(l, n);
    outputList(l);

    printf("Elemento 55 presente? %d\n", searchItem(l , 55));
    printf("Elemento 25 in pos? %d\n", searchItemPos(l , 25));
    outputList(switchCoppie(l));
    outputList(removeMiddleItem(l));

    return 0;
}