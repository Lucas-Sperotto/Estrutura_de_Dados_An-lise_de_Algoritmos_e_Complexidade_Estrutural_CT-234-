#include <stdio.h>
#include <stdlib.h>


int fat(int n){
    if (n!=0)
        return n*fat(n-1);
    else
    return 1;
}


int main(){
    int n;

    printf("Digite um valor para encontrar o fatorial: ");
    scanf("%d", &n);
    printf("\nO fatorial de %d e' %d\n", n, fat(n));

    return 0;
}
