#include<stdio.h>
#include<stdlib.h>

char P[6];

HanoiBinario(int n, char inicial, char final){
    int limite, i, x, dir;
    for (i=1;i<=n;i++)
        P[i]=inicial;
    dir=(n&1)!=(final-inicial ==1 || final-inicial==-2);
    limite=(1<<n)-1;
    for(x=1;x<=limite;x++){
        i=0;
        while(!(x>>i&1)) i++;
        printf("mover o disco %d ", ++i);
        printf("de %c ", P[i]);
        printf("para %c\n",
        P[i]='A'+(P[i]-'A'+1+(i&1?dir:1-dir))%3);
    }
}

int main(){


HanoiBinario(4, "A", "C");

    return 0;
}
