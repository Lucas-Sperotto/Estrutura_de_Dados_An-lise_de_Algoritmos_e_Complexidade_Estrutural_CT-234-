#include <stdlib.h>
#include <stdio.h>

int MaxVal(int A[], int ult){
    int i;
	int max;
    if (ult==0){
        return A[ult];
        }
    else{
        max = A[ult];
        if (max > MaxVal(A, ult-1))
            return max;
        }
    }

int main(){
    int size = 10;
    int i;
    int j=20;
    int V[size];

    for (i = 0; i < 10; i++){
        V[i]=j++;
        }
    printf("%d\n",MaxVal(V, size-1));

return 0;
}
