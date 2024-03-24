#include <stdio.h>
#include <stdlib.h>



void PrintSec(int n){
    if (n > 0)
    PrintSec(n-1);
    printf("%d\n", n);
    }

void PrintDec(int n){
    printf("%d\n", n);
    if (n > 0)
    PrintDec(n-1);
}

int main(){
int valor = 45;
PrintSec(valor);
return 0;
}
