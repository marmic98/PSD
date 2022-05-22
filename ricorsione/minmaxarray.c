#include <stdio.h>

int maxArrayRicorsivo(int *a, int i, int n){
    if (n == 1)
        return a[0];
    if (i < n){
        if (a[i] < maxArrayRicorsivo(a, i+1, n))
            return maxArrayRicorsivo(a, i+1, n);
        else 
            return a[i];
    }
}

int minArrayRicorsivo(int *a, int i, int n){
    if (n == 1)
        return a[0];
    if (i < n){
        if (a[i] > minArrayRicorsivo(a, i+1, n))
            return minArrayRicorsivo(a, i+1, n);
        else 
            return a[i];
    }
}

int main(){
    int a[7] = {0,1,2,3,4,5,6};
    printf("max = %d\n", maxArrayRicorsivo(a, 0, 7));
    printf("min = %d\n", minArrayRicorsivo(a, 0, 7));
}