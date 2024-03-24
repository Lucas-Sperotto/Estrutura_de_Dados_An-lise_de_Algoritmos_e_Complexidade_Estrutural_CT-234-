#include <stdio.h>
#include <stdlib.h>

int v[2555555];// = {3,5,1,2,55,8,9,5};
int n = 2555554;


void sift (int i, int n){
     int aux;
     int esq = 2 * i + 1;
     int dir = 2 * i + 2;
     int maior = i;
     if (esq <= n && v[esq] > v[i])
         maior = esq;
     if (dir <= n && v[dir] > v[maior])
         maior = dir;
     if (maior != i){
         aux = v[i];
         v[i] = v[maior];
         v[maior] = aux;
         sift (maior, n);
     }
}

void build(){
     int i;
     for (i=n/2; i>=0; i--)
           sift(i,n);
     }

     void HeapSort () {

          int aux , i;
          build ();
          for (i=n; i>0; i--) {
              aux = v[i];
              v[i] = v[0];
              v[0] = aux;
              sift (0, i-1);
              }
              }

     int main()
     {
         int i;
         char c;
          for (i=0 ; i <=n; i++) v[i] = rand();
         //for (i=0 ; i <=n; i++) printf("%i\n", v[i]);
         printf("\n");
         HeapSort ();
         //for (i=0; i<=n; i++) printf("%i\n", v[i]);
         getch (c);

         }









