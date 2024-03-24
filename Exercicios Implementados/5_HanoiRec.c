#include<stdio.h>
#include<conio.h>


void hanoi (int discos, char origem, char destino, char auxiliar){
    if (discos==1){
        printf("Mova o disco: %d", discos);
        printf(" de %c", origem);
        printf(" para %c\n",destino);
    }
    else{
        hanoi(discos-1,origem,auxiliar,destino);

        printf("Mova o disco: %d", discos);
        printf(" de %c", origem);
        printf(" para %c\n",destino);

        hanoi(discos-1,auxiliar,destino,origem);
    }
}


int main (){
    int total_discos;

    printf("Introduza o numero de discos: ");
    scanf("%d", &total_discos);
    printf("\n\n");

    hanoi(total_discos,'A','B','C');
    printf("\n\n");

    return 0;
}

