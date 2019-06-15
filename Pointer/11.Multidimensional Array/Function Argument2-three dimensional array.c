#include <stdio.h>
int Func1(int A[][2][2],int size){
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

int Func2(int (*A)[2][2],int size){
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
    int C[3][2][2]={{{2,5},{7,9}},
                    {{3,4},{6.1}},
                    {{0,8},{11,13}}};
    int size=sizeof(C)/sizeof(B[0]);
   // printf("%d elements\n",size);
    Func1(C,size);
    Func2(C,size);
}

