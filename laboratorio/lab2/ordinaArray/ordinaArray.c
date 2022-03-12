#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#include "utility.h"

#define LEN 20

int runTestCase (char* tcId, int len){
    char oracleFileName[LEN];
    char inputFileName[LEN];
    char outputFileName[LEN];

    strcpy(oracleFileName, tcId);
    strcat(oracleFileName, "_oracle.txt");
    strcpy(inputFileName, tcId);
    strcat(inputFileName, "_input.txt");
    strcpy(outputFileName, tcId);
    strcat(outputFileName, "_output.txt");

    int* a = inputArrayFromFile(len, inputFileName);
    int* aOracle = inputArrayFromFile(len, oracleFileName);

    selectionSort(a, len);

    outputArrayToFile(a, len, outputFileName);
    
    FILE* result = fopen("result.txt", "w");
    if(!result){
        printf("Errore apertura file\n");
        exit(-1);
    }
    else{
        return confrontoArray(a, aOracle, len);
        fclose(result);
    }
}

int main(int argc, char *argv[]) { 	
    
    
    int len = 0;
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