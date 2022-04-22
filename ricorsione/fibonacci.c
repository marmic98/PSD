#include <stdio.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0;37m"

int fibonacci(int n){
    if (n < 2)
        return n;
    return (fibonacci(n-1) + fibonacci(n-2));
}

int main(){
    int n;
    printf("FIBONACCI INCREDIBILE RICORSIVO\nFornisci numero: ");
    scanf("%d", &n);
    printf("il FATTORIALE di %d e' = %s%d%s\n",n,GREEN, fibonacci(n) ,RESET);
}