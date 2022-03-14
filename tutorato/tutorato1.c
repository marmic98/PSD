#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

void* xmalloc(size_t size){
    void* p = malloc(size);
    if (p == NULL){
        printf("Allocation of %lu bytes failed", size);
        exit(-1);
    }
    return p;
}

void* xrealloc(void* p, size_t size){
    p = realloc(p, size);
    if (p == NULL){
        printf("Allocation of %lu bytes failed", size);
        exit(-1);
    }
    return p;
}

void bubbleSort(char** strCollection, int counter){
    for (int i = 0; i < counter - 1; i++){
        for(int j = i + 1; j < counter; j++){
            if(strcmp(strCollection[i], strCollection[j]) > 0){
                char *temp = strCollection[i];
                strCollection[i] = strCollection[j];
                strCollection[j] = temp;
            }
        }
    }
}
    
int occurences (char* fInName, char* str){
    int len = strlen(str);
    FILE* fin = fopen(fInName, "r");
    int occ = 0;
    char* strFromFile = xmalloc(sizeof(char*));
    while(fscanf(fin, "%s", strFromFile) == 1){
        int lenFromFile = strlen(strFromFile);
        for (int i = 0; i < lenFromFile; i++){
            strncmp(strFromFile+i, str, len) == 0 ? occ++ : occ;
        }

    }
    fclose(fin);
    return occ;
}

void sort (char * fInName){
    char* temp = xmalloc(LEN);
    int counter = 0;

    FILE* fin = fopen(fInName, "r");
    if (fin){
        while(fscanf(fin, "%s", temp) == 1)  
            counter++;
        fclose(fin);
    }
    else 
        exit(-1);

    char** strCollection = xmalloc(sizeof(char*) * counter);
    fin = fopen(fInName, "r");
    if (fin){
        for (int i = 0; i < counter; i++){
            fscanf(fin, "%s", temp);
            strCollection[i] = xmalloc(strlen(temp));
            strcpy(strCollection[i], temp); 
        }
        fclose(fin);
        free(temp);
    }
    else
        exit(-1);
    
    bubbleSort(strCollection, counter);

    FILE* sortedFile = fopen("sorted.txt", "w");
    if(sortedFile){
        for(int i = 0; i < counter; i++)
            fprintf(sortedFile, "%s\n", strCollection[i]);
        fclose(sortedFile);
    }
    else
        exit(-1);

}

int main(int argc, char* argv[]){
    char mode = argv[1][0];
    char* fInName = argv[2];
    char* str = argv[3];
    if (mode == 'o'){
        printf("Le occorrenze della stringa %s sono %d\n", str, occurences(fInName, str));
    }
    else if(mode == 's'){
        sort(fInName);
    }
}