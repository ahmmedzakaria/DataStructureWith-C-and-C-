#include <stdio.h>
#include <stdlib.h>
int *Add(int* a, int* b){
        int* c=(int)malloc(sizeof(int));
        *c= (*a)+(*b);
        //printf("Sum = %d\n",*c);
        //printf("Address = %d\n",c);
        return c;
    }
int main(){
    int a=2, b=4;
    int* p=Add(&a,&b);
    //printf("Address = %d\n",p);
    printf("Sum = %d\n",*p);
}
