#include <stdio.h>

#define MAX 10

void Merge(int A[], int p, int q, int r){
	int B[MAX], i=p, j=q+1, k=p;
	while (i<=q && j<=r)
		if (A[i] < A[j]) 
			B[k++] = A[i++];
		else 
            B[k++] = A[j++];
	while (i<=q) 
        B[k++] = A[i++];
	while (j<=r) 
        B[k++] = A[j++];
	for (k=p; k<=r; k++) 
        A[k] = B[k];
	return;
}

void MergeSort(int A[], int p, int r) { 
	int q; 
	if (p < r) { 
		q = (p + r)/2; 
		MergeSort(A, p, q); 
		MergeSort(A, q+1, r); 
		Merge(A, p, q, r); 
	} 
	return; 
}

void inputArray(int* a, int size){
    for(int i = 0; i < size; i++){
        printf("elemento %d/%d\n", i+1,size);
        scanf("%d", &a[i]);
    }
}

void printArray(int* a, int size){
    for(int i = 0; i < size; i++){
        printf("[%d]", a[i]);
    }
}

int main(){
    int a[MAX];
    
    inputArray(a, MAX);
    MergeSort(a, 0, MAX);
    printArray(a,MAX);
}