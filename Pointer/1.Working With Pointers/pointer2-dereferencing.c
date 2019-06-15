int main(){
    int a;
    int *p;
    a=10;
    p=&a;
    printf("Address of P is: %d\n",p);
    printf("Value of P is: %d\n",*p);
    *p=12; //dereferencing
    printf("\nAfter Dereferencing:\n");
    printf("Address of P is: %d\n",p);
    printf("Value of P is: %d\n",*p);
}
