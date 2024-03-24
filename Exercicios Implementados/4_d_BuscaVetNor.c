#include<stdlib.h>
#include<stdio.h>

int Val(int V[], int val, int max){
    int i;
for (i = 0; i <= max; i++){
    if (V[i]== val)
        return val;
}
return -1;
}


int main(){
    int size = 10;
    int i=0;
    int A[size];

    for (i = 0; i < size; i++){
    A[i] = i;
    }
printf("Elemento na Posição: %d", Val(A,4,size-1));




return 0;
}
