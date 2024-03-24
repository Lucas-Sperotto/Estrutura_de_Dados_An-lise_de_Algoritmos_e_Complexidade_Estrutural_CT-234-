#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

/*A estrutura heap

 Heap � uma �rvore bin�ria com duas propriedades:

1) Balanceamento: � uma �rvore completa, com a eventual
exce��o do �ltimo n�vel, onde as folhas est�o sempre
nas posi��es mais � esquerda.

2) Estrutural: o valor armazenado em cada n� n�o � menor
que os de seus filhos.*/

//int v[10] = {5, 7, 20, 1, 4, 40,30, 55, 25, 22};
//int n=9;


//int v[n] = {2,3,1,5,9999,9,3,764,5,4};

int n = 100000000;
int v[100000000];
/*Existe uma diferen�a em rela��o ao programa que esta na apostila, pois a linguagem em C come�a
a contar as linhas de um vertor come�ando com "0", difrente do fortran que come�a com "1" */

float wall_time(void)
{
  struct timeval tv;
  struct timezone tz;
  static long t0=0;
  static long t0usec=0;

  gettimeofday(&tv, &tz);
  if (t0==0) {
    t0=tv.tv_sec;
    t0usec=tv.tv_usec;
  }
  return (tv.tv_sec-t0 + (tv.tv_usec-t0usec)/1000000.0);
}

 void sift (int i, int n) {     //A fun��o void � usado para um volor n�o voltar//
      int aux;
      int esq = 2*i + 1;
      int dir = 2*i + 2;
      int maior = i;
      if (esq <= n && v[esq] > v[i])
          maior = esq;
      if (dir <= n && v[dir] > v[maior])
          maior = dir;
      if (maior != i) {
          aux = v[i];
          v[i] = v[maior];
          v[maior] = aux;
          sift(maior,n);
          }
}

void build() {
     int i;
     for (i=n/2; i>=0; i--)
           sift (i,n);
}


void HeapSort () {
     int aux, i;
     build();
     for (i=n; i>0; i--) {
         aux = v[i];
         v[i] = v[0];
         v[0] = aux;
         sift(0,i-1);
     }
}



int main()
{   float tinit=0.0, tend=0.0;
    int i;
    char c;
    for (i=0; i<n; i++) v[i]=rand();
   // for (i=0; i<n; i++) printf("%i\n",v[i]);
    printf("INICIO\n");
    tinit = wall_time();
    HeapSort();
    tend = wall_time();
    //for (i=0; i<n; i++) printf("%i\n",v[i]);
    printf("ordeno para %d em tempo %f\n", n, tend-tinit);
    getch(c);
}









