#include <stdio.h>
int Add(int a, int b){
    return a+b;
}
int main(){
    int sum;
    int (*p)(int, int);
    p=Add;
    sum=p(2,3);
    printf("Sum = %d\n",sum);
}
