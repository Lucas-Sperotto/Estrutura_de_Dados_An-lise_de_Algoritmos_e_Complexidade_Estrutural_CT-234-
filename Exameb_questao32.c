#include<stdlib.h>
#include<stdio.h>
#include <sys/time.h>

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

int main(){

    int n = 100000;

    int i, j;
    int count = 0;
    int maior;
    int menor;
    int maior1;
    int menor1;
    int v[n];
    float t0, t1, t2, t3;

    for (i = n; i >= 0; i--)
        v[i]=i;

t0 = wall_time();

    maior = v[0];
    menor = v[0];

    for (i = 1; i < n; i++){
        count++;
        if (maior >= v[i]){
            count++;
            menor = v[i];
        }
        else{
            count++;
            maior = v[i];
        }
    }
    t1 = wall_time();

    printf("\nMaximo = %d\n", maior);
    printf("\nMinimo = %d\n", menor);
    printf("\nVetor com %d elementos\n", n);
    printf("\nUtilizou %d Comparações\n", count);
    printf("\nTEMPO = %f\n", t1-t0);

    count  = 0;
    t2 = wall_time();

    maior = v[0];
    menor = v[0];
    maior1 = v[n/2];
    menor1 = v[n/2];
    for (i = 1; i < n/2; i++){
        count++;
        count++;
        if (maior >= v[i]){
            //count++;
            menor = v[i];
        }
        else{
            //count++;
            maior = v[i];
        }
        count++;
        if (maior1 >= v[i+(n/2)]){
            //count++;
            menor1 = v[i+(n/2)];
        }
        else{
            //count++;
            maior1 = v[i+(n/2)];
        }
    }
    count++;
    if (maior < maior1){
        maior = maior1;
    }
    count++;
    if (menor > menor1){
        menor = menor1;
    }
    t3 = wall_time();

    printf("\nMaximo = %d\n", maior);
    printf("\nMinimo = %d\n", menor);
    printf("\nVetor com %d elementos\n", n);
    printf("\nUtilizou %d Comparações\n", count);
    printf("\nTEMPO = %f\n", t3-t2);


    return 0;
}
