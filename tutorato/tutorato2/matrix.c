#include "matrix.h"
#include "utility.h"
#include <stdlib.h>
#include <stdio.h>

int** creaMatrice(int r, int c){
    int** matrix = xcalloc(r, sizeof(int*));
    for(int i = 0; i < r; i++)
        matrix[i] = xcalloc(c, sizeof(int));
    return matrix;
} 

int** inputMatrix(int r, int c){
    int** matrix = creaMatrice(r, c);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

int** inputMatrixFromFile(char* fInName, int r, int c){
    FILE* fin = fopen(fInName, "r");
    if (fin == NULL){
        perror("apertura file fallita\n");
        exit(-1);
    }
    else{
        int** matrix = creaMatrice(r, c);
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                fscanf(fin, "%d", &matrix[i][j]);
            }
        }
        fclose(fin);
        return matrix;
    }
}

int** printMatrixOnFile(char* fOutName, int** matrix, int r, int c){
    FILE* fout = fopen(fOutName, "w");
    if (!fout){
        printf("apertura file fallita\n");
        exit(-1);
    }
    else{
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                fprintf(fout, "%d\n", matrix[i][j]);
            }
        }
        fclose(fout);
        return matrix;
    }
}


void printMatrix(int **matrix, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("[%d]", matrix[i][j]);
        }
        printf("\n");
    }
}

int** somma(int** m1, int** m2, int r, int c){
    int** sum = creaMatrice(r, c);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            sum[i][j] = m1[i][j]+m2[i][j];
        }
    } 
    return sum;
}

int** prodotto(int** m1, int** m2, int r, int c){
    int** product = creaMatrice(r, c);
    int i,j;
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){

            for (int k = 0; k < r; k++){
                product[i][j] += m1[i][k]*m2[k][j]; 
            }
        }
    }
    return product;
}

int confrontoMatrix(int** m1, int** m2, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (m1[i][j] != m2[i][j])
                return 0;
        }
    }
    return 1;
}
  