#include <stdio.h>


struct Node{
    int data;
    struct Node* next;
};

struct Node* top;
int size;

void push(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=top;
    top=newNode;
    size++;
}

void pop(){
    if(top == NULL){
        printf("Stack is Empty");
        return;
    }
    struct Node* temp=top;
    top=top->next;
    free(temp);
    size--;
}

void printStack(){
    printf("Stack is: ");
    struct Node* temp=top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp= temp->next;
    }
    printf("\nSize: %d\n",size);
}

main(){
    top=NULL;
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    printStack();

    pop();
    printStack();
}
