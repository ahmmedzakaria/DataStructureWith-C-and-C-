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
    free(A);
    A[2]=22;
    for(int i=0; i<n; i++){
        printf("%d\t",A[i]);
    }
}
