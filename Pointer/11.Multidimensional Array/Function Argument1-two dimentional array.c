#include <stdio.h>
int Func1(int A[][3],int size){
    printf("From Func1:\n");
    //int size=sizeof(A);
    //printf("%d bites \n",size);
    for(int i=0; i<size; i++){
        int size=sizeof(A[i])/sizeof(int);
        //printf("%d elements\n",size);
        for(int j=0; j<size; j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
}

int Func2(int (*A)[3],int size){
     printf("From Func2:\n");
    //int size=sizeof(A);
    //printf("%d bites \n",size);
    for(int i=0; i<size; i++){
        int size=sizeof(A[i])/sizeof(int);
        //printf("%d elements\n",size);
        for(int j=0; j<size; j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
}
main(){
    int B[2][3]={{2,4,5},{5,7,8}}; //B return pointer to one dimensional array of three integers
    int X[2][4]={{2,4,5,9},{5,7,8,13}}; //B return pointer to one dimensional array of three integers
    int size=sizeof(B)/sizeof(B[0]);
   // printf("%d elements\n",size);
    Func1(B,size);
    Func2(B,size);
}
