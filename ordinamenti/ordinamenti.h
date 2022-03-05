#include <unistd.h>

void printArray(int *a, int len){
    for (int i = 0; i < len; i++){
        printf("| %d |", a[i]);
    }
    sleep(1);
    printf("\n");
}

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void bubbleSort(int a[], int len){
    int i;
    for (i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
        printArray(a, len);
    }
}

int posMinimo(int *a, int i, int len){
    int posMin = i; 
    for (int j = i + 1; j < len; j++){
        if (a[posMin] > a[j]){
            posMin = j;
        }
    }
    return posMin;
}

void selectionSort(int a[], int len){
    int i, p;
    for (i = 0; i < len - 1; i++){
        p = posMinimo(a, i, len);
        if (p != i)
            swap(&a[i], &a[p]);
        printArray(a, len);
    }
}

void insertionSort(int a[], int len){
    for (int i = 1; i < len; i++){
        int toSwap = a[i];
        int j = i - 1;
        while(j >= 0 && toSwap < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = toSwap;  
        printArray(a, len);
    }
}