#include<stdlib.h>
#include<stdio.h>

int Soma(int V[], int ult){
    int soma;
if (ult == 0)
return V[ult];
soma = V[ult] + Soma(V,ult-1);
return soma;

}

int main(){
    int size = 10;
    int i = 0;
    int A[size];

    for (i = 0; i < size; i++){
        A[i] = i;
    }
printf("%d", Soma(A,size-1));


return 0;
}
