#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#include "utility.h"

#define MAXLEN 50

//richiesta 1: funzione che effettua il merge di due stringhe
char* merge(char* s1, char* s2){
    int len0 = strlen(s1);
    int len1 = strlen(s2);

    char* mergedStr = (char*)xmalloc(len0 + len1 + 1);

    strcpy(mergedStr, s1);
    
    int i = len0;
    for(i; i < (len0 + len1); i++){
        mergedStr[i] = s2[i-len0]; 
    }
    mergedStr[i] = '\0';
    return mergedStr;
}

int main(int argc, char* argv[]){
    //su windows in argv[0] c'è "path//a.exe"
    //su Linux contiene solo il nome dell'eseguibile
    
    if (argc < 3){ 
        printf("paramtri input insufficienti\n");
        exit (-1);
    }

    char* nome = argv[1];
    //char*nome = *(argv + 1)
    char* cognome = argv[2];

    printf("il merge di nome e cognome e' %s\n", merge(nome, cognome));
}