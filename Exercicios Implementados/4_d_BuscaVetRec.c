#include<stdlib.h>
#include<stdio.h>

int Val(int V[], int val, int max){
if (max == 0){
printf("valor não encontrado");
return -1;}
else{
if (V[max] == val)
return V[max];
else
return Val(V,val, max-1);
}
}

int main(){
    int size = 10;
    int i=0;
    int A[size];

    for (i = 0; i < size; i++){
    A[i] = i;
    }
printf("Elemento na Posição: %d", Val(A,1,size-1));




return 0;
}
