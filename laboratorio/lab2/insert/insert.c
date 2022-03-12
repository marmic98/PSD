#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "vettore.h"

#define LEN 20

int shiftDx(int a[], int len, int pos){
    for(int i = len; i > pos; i--)
        a[i] = a[i-1];
    return len+1;
}

void arrayCopy(int* toCopy, int* copied, int len){
    for(int i = 0; i < len; i++){
        copied[i] = toCopy[i];
    }
}

int insert(int a[], int len, int element, int pos){
    a = xrealloc(a, (len + 1) * sizeof(int));
    shiftDx(a, len, pos);
    a[pos] = element;
    return len+1;
}

int runTestCase(char* tcId, int len, int element, int pos){
    char oracleFileName[LEN];
    char inputFileName[LEN];
    char outputFileName[LEN];

    strcpy(oracleFileName, tcId);
    strcat(oracleFileName, "_oracle.txt");
    
    strcpy(inputFileName, tcId);
    strcat(inputFileName, "_input.txt");
    
    strcpy(outputFileName, tcId);
    strcat(outputFileName, "_output.txt");

    int *a = inputArrayFromFile(len, inputFileName);

    len = insert(a, len, element, pos);
    outputArray(a, len);

    int *aOracle = inputArrayFromFile(len, oracleFileName);

    outputArrayToFile(a, len, outputFileName);
    return confrontoArray(a, aOracle, len);

}

int main(int argc, char *argv[]) { 	
    int len = 0;
    int element;
    int pos;
    char tcId[LEN]; 

    if(argc < 3){
         printf("Nomi dei file mancanti \n");
         exit(1);
    }    
    
    FILE *testSuite = fopen(argv[1], "r");               
    FILE* result = fopen(argv[2], "w");           
    
    if( testSuite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }

    int pass;
    while(fscanf(testSuite, "%s%d%d%d", tcId, &len, &element, &pos) == 4){
        pass = runTestCase(tcId, len, element, pos);
    
        fprintf(result,"%s ", tcId);
        pass ? fprintf(result, "PASS \n") : fprintf(result, "FAIL \n");			
    }	
    
    fclose(testSuite);  
    fclose(result);         
}