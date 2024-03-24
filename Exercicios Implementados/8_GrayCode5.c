/*
  Conversor de decimal para Gray Code
*/

# include<stdio.h>

#define SIZE 32

int bits[SIZE], i; // could be chars in 8 bit machine
unsigned long num; // could be int if less than 17 bit Grey code

void main(){
  printf("\nConversor de %d bits.\n",SIZE);
  printf("\nDigite um Numero Inteiro: ");
  scanf("%lu",&num);

  /* converting number to binary equivalent */
  /* MSB is 1st element in array */
  for(i = 0; i < SIZE; i ++){
    bits[SIZE-1-i] = (num >> i) & 1;
  }

  /* printing binary */
  printf(" Binary           ");
  for(i = 0; i < SIZE; i ++){
    printf("%d",bits[i]);
  }

  /* in-line gray code conversion */
  for(i = SIZE-1; i > 0; i --){
    bits[i] = bits[i] ^ bits[i - 1];
  }

  /* printing gray code */
  printf("\n Gray code        ");
  for(i = 0; i < SIZE; i ++){
    printf("%d",bits[i]);
  }

  /* in-line conversion back to binary */
  for(i = 1; i < SIZE; i++){
    bits[i] = bits[i] ^ bits[i - 1];
  }

  /* reprinting binary */
  printf("\n Restored binary  ");
  for(i=0;i<SIZE;i++){
    printf("%d",bits[i]);
  }

   /* convert back to decimal */
  num = 0;
  for (i = 0; i < SIZE; i ++){
    num = (num<<1) | bits[i];
  }

  /* reprinting decimal number */
  printf("\n Restored decimal ");
  printf("%lu",num);
  printf("\n");
}
