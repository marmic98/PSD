#include <stdio.h>
#include <stdlib.h>

// void printArray(int a[]){
//     int len = 0;
//     len = (sizeof(a)/sizeof(int));
//     for(int i = 0; i < len; i++)
//         printf("[%d]",a[i]);
// }

int main(){
    int *a = malloc(sizeof(int) * 5);
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    printf("size of a: %d\nsize of int: %d\n",sizeof(*a),sizeof(int));
    int len = (sizeof(a)/sizeof(int));
    for(int i = 0; i < len; i++)
        printf("[%d]",a[i]);
}
