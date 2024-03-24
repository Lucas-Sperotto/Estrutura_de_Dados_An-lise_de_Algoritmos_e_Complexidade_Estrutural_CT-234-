/////////////////////////////////////////////////////////////
////     Coverting a decimal number to Gray code       /////
///////////////////////////////////////////////////////////



# include<stdio.h>
# include<conio.h>
# include<stdlib.h>
#include<iostream>
using namespace std;

static int a[8],b[8],k=1,i;

int main()
{   int n1;
	 //clrscr();
	 printf("Enter any Numbers :");
	 scanf("%d",&n1);
	 while(n1!=0)   /* converting number to its binary equivalent */
	 {  a[i]=n1 % 2;
		 n1/=2;
		 i++;
	 }
	/* printing binary equivalent */
		 printf("\nThe binary code of the given number is :");
	 for(i=7;i>=0;i--)
	 printf("%d",a[i]);


	 /* gray code conversion */
	 b[0]=a[7];

	 for(i=7;i>=0;i--)
	 {  if(a[i]==0 && a[i-1]==0)
		 b[k]=0;
		 if(a[i]==1 && a[i-1]==1)
		 b[k]=0;
		 if(a[i]==0 && a[i-1]==1)
		 b[k]=1;
		 if(a[i]==1 && a[i-1]==0)
		 b[k]=1;
		 k++;
	 }

	 /* printing the gray code */
	 printf("\nThe gray code of the given number is :");
	 for(i=0;i<8;i++)
	 printf("%d",b[i]);
}
