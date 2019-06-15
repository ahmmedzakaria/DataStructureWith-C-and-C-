#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int *A = (int*)calloc(n,sizeof(int));
    for(int i=0; i<n; i++){
        A[i]=i+1;
    }

    for(int i=0; i<n; i++){
        printf("%d\t",A[i]);
    }

    int *B=(int*)realloc(A,2*n*sizeof(int));
    printf("\nprev block address = %d, new address = %d\n",A,B);

    for(int i=0; i<2*n; i++){
        printf("%d\t",B[i]);
    }
}

