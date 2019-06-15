#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
}
void print(){
    struct Node* temp=head;
    printf("List is: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
main(){
    head=NULL;
    printf("Please insert length of the list:\n");
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        printf("Enter number %d: ",i+1);
        int x;
        scanf("%d",&x);
        insert(x);
        print();
    }
}


int *takeUserInput(char str[]){
    int* userInput=(int)malloc(sizeof(int));
    printf(str);
    scanf("%d",userInput);
    return userInput;
}
