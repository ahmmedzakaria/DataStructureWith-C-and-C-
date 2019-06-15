#include <stdio.h>
main(){
    int x=5;
    int* p=&x;
    int** q=&p;
    int *** r=&q;

    printf("value of *p: %d \n",*p);
    printf("value of &x: %d\n",&x);
    printf("value of &p: %d\n",&p);
    printf("value of *q: %d\n",*q);
    printf("value of **q: %d\n",**q);
    printf("value of **r: %d\n",**r);
    printf("value of ***r: %d\n",***r);

    ***r=10;
    printf("x = %d\n",x);
    **q=*p+2;
    printf("x = %d\n",x);

}
