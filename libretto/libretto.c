#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libretto.h"
#include "list.h"

#define MAXLEN 40 

struct lib{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int mat;
    list esami;
};

list createListaEsami(list l, int n){
    for(int i = 0; i < n; i++){
        item esame = createItem();
        printf("Fornisci esame %d\n", i+1);
        l = consList(esame, l);
    }
    return l;
}

libretto createLibretto(){
    libretto lib = malloc(sizeof(libretto));

    printf("Nome: ");
    fgets(lib->nome, MAXLEN, stdin);
    
    printf("Cognome: ");
    fgets(lib->nome, MAXLEN, stdin);

    
    printf("mat: ");
    scanf("%d", &lib->mat);

    printf("n esami: ");
    int n = 0;
    scanf("%d", &n);

    int n = 0;
    printf("Fornire nunmero esami: ");
    scanf("%d", &n);
    lib->esami = createListEsami(n);

    return lib; 
}

void printLibretto(libretto l){
    printf("Nome: %s\nCognome: %s\nMat: %s\n");
    printList(l->esami);
}

void inserisciEsame(libretto l, item e){
    l->esami = consList(e, l);
}

int cercaEsame(libretto l, char* es){
    int pos = posItembyStr(l->esami, es);
    
    if (pos != -1)
        printItem(getItem(l->esami, pos));    

    return pos;
}
