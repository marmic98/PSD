#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#include "utility.h"

#define LEN 20

int* sumArray(int* a, int* b, int* c, int len){
    c = xcalloc(len, sizeof(int));
    for(int i = 0; i < len; i++)
        c[i] = a[i] + b[i];
    return c;
}

int runTestCase(char* tcId, int len){
    char oracleFileName[LEN];
    char inputFileName1[LEN];
    char inputFileName2[LEN];
    char outputFileName[LEN];

    strcpy(oracleFileName, tcId);
    strcat(oracleFileName, "_oracle.txt");
    
    strcpy(inputFileName1, tcId);
    strcat(inputFileName1, "_input1.txt");
    strcpy(inputFileName2, tcId);
    strcat(inputFileName2, "_input2.txt");
    
    strcpy(outputFileName, tcId);
    strcat(outputFileName, "_output.txt");

    int *a = inputArrayFromFile(len, inputFileName1);
    int *b = inputArrayFromFile(len, inputFileName2);

    int* c = sumArray(a, b, c, len);
    outputArray(c, len);

    int *aOracle = inputArrayFromFile(len, oracleFileName);

    outputArrayToFile(c, len, outputFileName);
    return confrontoArray(c, aOracle, len);

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
    while(fscanf(testSuite, "%s%d", tcId, &len) == 2){
        pass = runTestCase(tcId, len);
    
        fprintf(result,"%s ", tcId);
        pass ? fprintf(result, "PASS \n") : fprintf(result, "FAIL \n");			
    }	
    
    fclose(testSuite);  
    fclose(result);         
}