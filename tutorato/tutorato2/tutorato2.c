#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "matrix.h"

#define LEN 50


int runTestCaseSum(char* tcId, int r1, int c1, int r2, int c2){
    printf("%s sum\n", tcId);
    char inputFileName1[LEN];
    strcpy(inputFileName1, tcId);
    strcat(inputFileName1, "_input1.txt");

    char inputFileName2[LEN];
    strcpy(inputFileName2, tcId);
    strcat(inputFileName2, "_input2.txt");

    char oracleFileName[LEN];
    strcpy(oracleFileName, tcId);
    strcat(oracleFileName, "_oracle.txt");

    char outputFileName[LEN];
    strcpy(outputFileName, tcId);
    strcat(outputFileName, "_output.txt");
    
    int** m1;
    int** m2;

    int** sum;
    if (r1 == r2 && c1 == c2){
        m1 = inputMatrixFromFile(inputFileName1, r1, c1); 
        m2 = inputMatrixFromFile(inputFileName2, r2, c2);
        
        // printf("M1:\n");    
        // printMatrix(m1, r1 , c1);
        // printf("M2:\n");
        // printMatrix(m2, r2 , c2);
        sum = somma(m1, m2, r1 ,c1);
        printMatrixOnFile(outputFileName, sum, r1, c1);    
        printf("somma m1+m2\n");
        printMatrix(sum, r1 , c1);
    }
    else{
        printf("Impossibile effettuare somma. r != c\n");
        FILE* fout = fopen(outputFileName, "r");
        FILE* oracle = fopen(oracleFileName, "r");
        fprintf(fout, "0\n");
        int test = 0;
        fscanf(oracle, "%d", &test);
        return test == 0;
        fclose(oracle);
        fclose(fout);
    }

    FILE* oracle = fopen(oracleFileName, "r");

    int** sumOracle;
    if (oracle){
        sumOracle = inputMatrixFromFile(oracleFileName, r1, c1); 
        fclose(oracle);
    }
    else{
        printf("impossibile aprire oracolo\n");
        exit(-1);
    }
    return confrontoMatrix(sum, sumOracle, r1, c1);

}

int runTestCaseProduct(char* tcId, int r1, int c1, int r2, int c2){
    printf("%s prod\n", tcId);
    
    char inputFileName1[LEN];
    strcpy(inputFileName1, tcId);
    strcat(inputFileName1, "_input1.txt");

    char inputFileName2[LEN];
    strcpy(inputFileName2, tcId);
    strcat(inputFileName2, "_input2.txt");

    char oracleFileName2[LEN];
    strcpy(oracleFileName2, tcId);
    strcat(oracleFileName2, "_oracle2.txt");

    char outputFileName2[LEN];
    strcpy(outputFileName2, tcId);
    strcat(outputFileName2, "_output2.txt");
    
    int** m1;
    int** m2;

    int** prod;
    if (c1 == r2){
        m1 = inputMatrixFromFile(inputFileName1, r1, c1); 
        m2 = inputMatrixFromFile(inputFileName2, r2, c2);
    
        prod = prodotto(m1, m2, r2, c2);
        
        printMatrixOnFile(outputFileName2, prod, r2, c2);    
        printf("prodotto m1 x m2\n");
        printMatrix(prod, r2, c2);
    }
    else{
        printf("Impossibile effettuare prodotto. c1 != r2\n");
        FILE* fout = fopen(outputFileName2, "w");
        FILE* oracle = fopen(oracleFileName2, "r");
        fprintf(fout, "0\n");
        int test = 0;
        fscanf(oracle, "%d", &test);
        return test == 0;
        fclose(oracle);
        fclose(fout);
    }

    FILE* oracle = fopen(oracleFileName2, "r");

    int** prodOracle;
    if (oracle){
        prodOracle = inputMatrixFromFile(oracleFileName2, r2, c2); 
        fclose(oracle);
    }
    else{
        printf("impossibile aprire oracolo\n");
        exit(-1);
    }
    return confrontoMatrix(prod, prodOracle, r2, c2);

}

int main(int argc, char* argv[]){
    char tcId[LEN];
    
    FILE* testSuite = fopen(argv[1], "r");
    FILE* result = fopen(argv[2], "w");

    if (!result || !testSuite){
        printf("file di test mancanti\n");
        exit(-1);
    }
    else{
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        while(fscanf(testSuite, "%s %d %d %d %d", tcId, &r1, &c1, &r2, &c2) == 5){
            fprintf(result, "%s ", tcId);
            runTestCaseSum(tcId, r1, c1, r2, c2) ? fprintf(result, "sum: PASS & ") : fprintf(result, "sum: FAILED & ");
            runTestCaseProduct(tcId, r1, c1, r2, c2) ? fprintf(result, "product: PASS\n") : fprintf(result, "product: FAILED\n");
        }
        fclose(result);
        fclose(testSuite);
    }
}