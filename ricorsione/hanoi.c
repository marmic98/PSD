#include <stdio.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0;37m"

void hanoi(char a, char b, char c, int n){
    if (n == 1)
        printf("da %c in %c\n", a, c);
    else{
        hanoi(a, b, c, n-1);
        printf("da %c in %c\n", a, c);
        hanoi(b, a, c, n-1);
    }
}

int main(){
    char a = 'a', b = 'b', c = 'c';
    hanoi(a, b, c, 5);
}