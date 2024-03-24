#include <stdlib.h>
#include <stdio.h>

const int size = 10;
int V[10];
int ult = 9;

//verifica numero de vivos
int VrfVivo(){
    int i = 0;
    int viv = 0;
    for (i = 0; i <= ult; i++){
        if (V[i] == 1)
            viv++;
        }
    return viv;
}

void Mata (int pos){
    int i = 0;
    for(i = pos; i <= ult; i++){
        V[i]=V[i+1];
    }
    ult--;
}


//verivica Josefus retorna vitorioso
int Josef(int pos){

    if (pos > ult){
        pos=0;
        }

    if (V[pos] == 1){
        if (VrfVivo(ult) == 1){
            return V[pos];
            }
        else{
            printf("Mata: %d\n", pos);
            Mata(pos);
            }
    }
pos = pos+2;
    Josef(pos);

}

int main(){


   // size = 10;
    //V[size];
   // int pri
    //

    int i = 0;

    for (i=0; i < size; i++){
    V[i] = i;
    }

    printf("O vencedor é: %d\n", Josef(0));




return 0;
}
