int main(){
    int a=10;
    int *p=&a;
    printf("Address of P is: %d\n",p);
    printf("Size of integer is: %d bytes\n",sizeof(p));
    printf("Address of P+1 is %d\n",p+1);

    printf("Value of P is: %d\n",*p);
    printf("Value of P+1 is: %d\n",*(p+1));
}

