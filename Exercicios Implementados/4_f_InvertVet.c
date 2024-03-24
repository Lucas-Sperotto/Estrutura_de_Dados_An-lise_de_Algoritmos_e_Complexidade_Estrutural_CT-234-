#include<stdlib.h>
#include<stdio.h>

void invert(int A[],int pri, int ult){
    int aux;
    if (pri >= ult)
        return 1;
    aux = A[pri];
    A[pri] = A[ult];
    A[ult] = aux;
    invert(A, pri+1, ult-1);
}



int main(){
int size = 10;
int i = 0;
int V[size];
for (i = 0; i < size; i++){
    V[i]=i;
    }
printf("Antes de Inverter \n");
    for (i = 0; i < size; i++){
    printf("%d\n",V[i]);
    }

invert(V,0,size-1);
printf("\nDepois de Inverter \n");
for (i = 0; i < size; i++){
    printf("%d\n",V[i]);
    }
return 0;
}
