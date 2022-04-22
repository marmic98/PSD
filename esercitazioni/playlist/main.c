#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "item.h"

#define MAXLEN 50

typedef list playlist;

// list inputListFromFile (char* InputfileName){
//     int x = 0;
//     list l = newList();
//     FILE* fin = fopen(InputfileName, "r");
//     while(fscanf(fin, "%d", &x) == 1){
//         item i = createItem(x);
//         l = consList(i, l);
//     }
//     fclose(fin);
//     l = reverseList(l);
//     return l;
// }

// void printListOnFile (list l, char* OutputfileName){
//     FILE* fout = fopen(OutputfileName, "w");
//     while(!emptyList(l)){
//         fprintf(fout, "%d\n", getValue(getFirst(l)));
//         l = tailList(l);
//     }
//     fclose(fout);
// }

playlist createList(int n){
    playlist l = newList();
    
    for(int i = 0; i < n; i++){
        printf("Fornire nome: ");
        fflush(stdin);
        char* nome = malloc(MAXLEN);
        fgets(nome, MAXLEN, stdin);
        nome[strlen(nome)-1] = '\0';

        printf("Fornire artista: ");
        char* artista = malloc(MAXLEN);
        fgets(artista, MAXLEN, stdin);
        artista[strlen(artista)-1] = '\0';

        printf("Fornire durata: ");
        int durata;
        scanf("%d", &durata);

        item current = createItem(nome, artista, durata);
        l = consList(current, l);
    }
    printf("\n");
    return l = reverseList(l);
}

void printList(playlist l){
    int i = 0;
    while(!emptyList(l)){
        printf("Canzone n%d\n", i+1);
        i++;
        printItem(getFirst(l));
        l = tailList(l);
    }
}

playlist enqueueSong(playlist l, item song){
    return l = insertList(l, sizeList(l), song);
}

playlist removeSong (playlist l, int pos){
    return l = removeList(l, pos);
}

playlist forwardSong(playlist l, int pos){
    if (pos < 0 || pos >= sizeList(l)-1)
        return l;
    item temp = getItem(l, pos+1);
    l = removeList(l, pos+1);
    return l = insertList(l , pos ,temp);
}

playlist backSong(playlist l, int pos){
    if (pos <= 0 || pos >= sizeList(l))
        return l;
    item temp = getItem(l, pos-1);
    l = removeList(l, pos-1);
    return l = insertList(l , pos ,temp);
}

playlist sottoplaylistbyArtist (playlist l, char* artista){
    playlist sottoLista = newList();
    while(!emptyList(l)){
        if (sameArtist(getArtista(getFirst(l)), artista) == 0){
            sottoLista = consList(getFirst(l), sottoLista);
        }
        l = tailList(l);
    }
    return sottoLista;
}

int main(){
    printf("quante canzoni si desiderano inserire? ");
    int n;
    scanf("%d", &n);
    playlist l = createList(n);
    printList(l);

    // item song = createItem("Pino Mauro", "o bene mio", 50);
    // l = enqueueSong(l, song);
    // printList(l);

    // l = removeSong(l, 1);
    // printList(l);
    printf("forword: mette 1 in 2\n");
    l = forwardSong(l , 1);
    printList(l);

    printf("back: mette 1 in 0\n");
    l = backSong(l, 1);
    printList(l);

    // playlist sl  = sottoplaylistbyArtist(l, "gem");
    // printf("le canzoni di gem nella playlist sono:\n");
    // printList(sl); 
}