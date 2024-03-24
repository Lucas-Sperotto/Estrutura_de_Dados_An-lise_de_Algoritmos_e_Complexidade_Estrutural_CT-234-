#include<stdlib.h>
#include<stdio.h>
#include <sys/time.h>


float v[1000][1000];

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
Rec(int n) {
    if (n==1) return 1;
    else return 3*Rec(n-1) + Funcao(n);
}

Funcao(int n) {
    int i;
    int j;
    for (i=0; i<n; i++)
        for(j=i; j>0; j--)
            v[i][j] = 4*i*i+j;
    return v[n-1][n-1];
}

int main(){
    float t1,t2;
    t1 = wall_time();

    printf("\nResultado = %E\n",Rec(1000));

    t2 = wall_time();
    //printf("\nMaximo = %d\n", maior);
    //printf("\nMinimo = %d\n", menor);
    //printf("\nVetor com %d elementos\n", n);
    //printf("\nUtilizou %d Comparações\n", count);
    printf("\nTEMPO = %f\n", t2-t1);


    return 0;
}

