#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0;37m"

char inverti(char c){
    c = getchar();
    if (c == '.')
        return;
    inverti(c);
    printf("%s%c%s", GREEN,c,RESET); 
}

int main(){	
    char c;
    inverti(c);
}