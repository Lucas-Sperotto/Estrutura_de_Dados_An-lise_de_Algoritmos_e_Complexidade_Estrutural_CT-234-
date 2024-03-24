#include <stdlib.h>
#include <stdio.h>
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

int busca(int V[], int num,int inf, int sup){
int meio = 0;
while(inf <= sup){
    meio=(sup+inf)/2;
    if (V[meio]<num){
        inf = meio+1;}
    else{
        if (V[meio]>num){
            sup = meio-1;}
        else
            return meio;
        }
}
 return -1;
}



int main(){
float tstart, tend;
int size=99999;
int V[size];
int i=0;
tstart = wall_time();

for(i=0; i<size; i++){
V[i]=i;
}

printf("Elemento na posição %d \n",busca(V,9999,0,size-1));
tend = wall_time();
printf("Tempo total %f (s)\n", tend-tstart);
return 0;
}
