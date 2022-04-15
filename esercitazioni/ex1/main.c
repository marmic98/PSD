#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "item.h"

list inputListFromFile (char* InputfileName){
    int x = 0;
    list l = newList();
    FILE* fin = fopen(InputfileName, "r");
    while(fscanf(fin, "%d", &x) == 1){
        item i = createItem(x);
        l = consList(i, l);
    }
    fclose(fin);
    l = reverseList(l);
    return l;
}

void printListOnFile (list l, char* OutputfileName){
    FILE* fout = fopen(OutputfileName, "w");
    while(!emptyList(l)){
        fprintf(fout, "%d\n", getValue(getFirst(l)));
        l = tailList(l);
    }
    fclose(fout);
}

void printList(list l){
    while(!emptyList(l)){
        printItem(getFirst(l));
        l = tailList(l);
    }
    printf("nil\n");
}

int cmpLists(list a, list b){
    while(!emptyList(a) && !emptyList(b)){
        if (cmp(getFirst(a), getFirst(b)) != 0)
            return 0;
        a = tailList(a);
        b = tailList(b);
    }
    return 1;
}

int runTestCase(char* tcId, int n){
    char outputFileName[20];
    char inputFileName[20];
    char oracleFileName[20];

    strcpy(inputFileName, tcId);
    strcat(inputFileName, "_input.txt");

    strcpy(outputFileName, tcId);
    strcat(outputFileName, "_output.txt");

    strcpy(oracleFileName, tcId);
    strcat(oracleFileName, "_oracle.txt");

    list lInput = inputListFromFile(inputFileName);
    list loutput = estraiMaxN(lInput, n);

    printListOnFile(loutput, outputFileName);

    list lOracle = inputListFromFile(oracleFileName);
    return cmpLists(loutput, lOracle);
}

int main(int argc, char* argv[]){

    if (argc != 3){
        printf("Parametri di input insufficienti\n");
        exit(-1);
    }

    FILE* testSuite = fopen(argv[1], "r");
    FILE* results = fopen(argv[2], "w");
    
    if (!testSuite || !results){
        printf("Impossibile aprire file\n");
        exit(-1);
    }

    int esito = 0;
    char tcId[20];
    int n = 0;
    while(fscanf(testSuite, "%s%d", tcId, &n) == 2){
        
        esito = runTestCase(tcId, n);
        fprintf(results, "%s: ", tcId);
        esito == 1 ? fprintf(results, "PASS\n") : fprintf(results, "FAIL\n");
    }
    fclose(results);
    fclose(testSuite);
}