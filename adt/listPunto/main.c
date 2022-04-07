#include <stdio.h>
#include "list.h"
#include "punto.h"
#include "utility.h"

int coppieVicine(list p, float d){
    int counter = 0;
    for(list i = p; i != NULL; i = tailList(i)){
        for(int j = tailList(i); j != NULL; j = tailList(j)){
            if (distanza(getFirst(i), getFirst(j)) < d)
                counter++;
        }
    }
    return counter;
}

list distMaxDots(list p, int nPunti){
    list max = newList();
    if (nPunti < 2){
        return NULL; 
    }
    item item1;
    item item2;

    float maxDist = distanza(getFirst(p), getFirst(tailList(p)));
    for(list i = p; tailList(i) != NULL; i = tailList(i)){
        for(list j = tailList(i); j != NULL; j = tailList(j)){
            float dist = distanza(getFirst(i), getFirst(j));
            if (dist > maxDist){
                maxDist = dist;
                item1 = getFirst(i);
                item2 = getFirst(j);     
            }
        }
    }
    max = consList(item2, max);
    max = consList(item1, max);
    return max;
}

list bubbleSortCrescentex(list p){
    list ordered = newList();
    int position = 0;
    int x = ascissa(getFirst(p));
    while(p != NULL){
        for(int i = 0; i < sizeList(p); i++){
            if (x < ascissa(getItem(p, i))){
                x = ascissa(getItem(p, i));
                position = i;
            }
        }
        ordered = consList(getItem(p, position), ordered);
        p = removeListOpt(p, position);
        x = 0;
    }
    
    return ordered;
}

list bubbleSortCrescentey(list p){
    list ordered = newList();
    int position = 0;
    int y = ordinata(getFirst(p));
    while(p != NULL){
        for(int i = 0; i < sizeList(p); i++){
            if (y < ordinata(getItem(p, i))){
                y = ordinata(getItem(p, i));
                position = i;
            }
        }
        ordered = consList(getItem(p, position), ordered);
        p = removeListOpt(p, position);
        y = 0;
    }
    return ordered;
}

void riordina (list *p, char coordinata, char criterio){
    if (coordinata =='a'){
        //*p = sortx(*p);
        *p = bubbleSortCrescentex(*p);
        if (criterio == 'd')
            *p = reverseList(*p);
    }
    else{
        *p = bubbleSortCrescentey(*p);
        //*p = sorty(*p);
        if (criterio == 'd')
            *p = reverseList(*p);
    }
}
//funzione che restituisce una sottolista che va dal nodo in posizione inf a quello in posizone sup
//precondizione: inf e sup devono essere compresi tra 0 e lunghezza della lista
//postcondizione: la nuova lista deve avere una dimensione minore o ugula ealla precedente con gli elementi dell'intervallo selezionato
list sottoLista(list* l, int inf, int sup){
    int size = sizeList(*l);

    if (inf < 0 || sup > size)
        return *l;
    
    int i = 0;
    list temp = *l;
    list temp2 = NULL;
    list outList = NULL;
    while(i < inf){
        i++;
        temp2 = consList(getFirst(temp), temp2);
        temp = tailList(temp);
        
    }

    while(i <= sup){
        i++;
        outList = consList(getFirst(temp), outList);
        temp = tailList(temp);
    }

    while(i < size){
        i++;
        temp2 = consList(getFirst(temp), temp2);
        temp = tailList(temp);
    }
    temp2 = reverseList(temp2);
    printLista(temp2);
    *l = temp2;
    return reverseList(outList);
}
//inserisce una lista all'interno di una lista già esistente a partire da una certa posizione restituendo la lista modificata
//precondizioni: pos dove inserire la sottolista deve essere compresa tra 0  e size della lista
//postcondizioni: la lista in output deve avere inserita nella pos indicata la sottolista passato in input alla funzione 
list inserisci_lista(list l, list toInsert, int pos){
    int size = sizeList(l);
    if (pos < 0 || pos > size)
        return l;

    list outList = NULL;
    list temp = l;

    int i = 0;
    while(i < pos){
        i++;
        outList = consList(getFirst(temp), outList);
        temp = tailList(temp);
    }
    int sizeToIns = sizeList(toInsert);
    i = 0;
    while (i < sizeToIns){
        i++;
        outList = consList(getFirst(toInsert),outList);
        toInsert = tailList(toInsert);
    }

    i = 0;
    while (i < (size - pos)){
        i++;
        outList = consList(getFirst(temp), outList);
        temp = tailList(temp);
    }
    return reverseList(outList);
}



int main(){
    int n;
    printf("Fornire dimensione lista di item\n");
    scanf("%d", &n);
    list l = createList(n);
    l = reverseList(l);
    printLista(l);

    // printf("Fornisci distanza ");
    // float dist = 0;
    // scanf("%f", &dist);
    // printf("numero coppie vicine entro %g sono %d\n",dist ,coppieVicine(l, dist));

    //char criterio = ' '; 
    //char coordinata = ' ';
    // printf("Ricerca coppia con distanza massima\n");
    // list test = distMaxDots(l, n);
    // printLista(test);

    // printf("Riordino lista\n");
    // fflush(stdin);
    // printf("Fornire coordinata ");
    // scanf("%c", &coordinata);
    // fflush(stdin);
    // printf("Fornire criterio ");
    // scanf("%c", &criterio);
    // riordina(&l, coordinata, criterio);
    // printLista(l);

    
    // list subList = sottoLista(&l, 1, 2);
    // printLista(subList);
    // printLista(l);
    // list insert = createList(2);
    // insert = reverseList(insert);
    // printLista(insert);
    // list test = inserisci_lista(l, insert, 2);
    // printLista(test);

}