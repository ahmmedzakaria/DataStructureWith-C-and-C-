#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};


struct Node* insert(int x,struct Node* head){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
    return head;
}
void print(struct Node* head){
    printf("List is: ");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
main(){
    struct Node* head;
    head=NULL;
    printf("Please insert length of the list:\n");
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        printf("Enter number %d: ",i+1);
        int x;
        scanf("%d",&x);
        head=insert(x,head);
        print(head);
    }
}


int *takeUserInput(char str[]){
    int* userInput=(int)malloc(sizeof(int));
    printf(str);
    scanf("%d",userInput);
    return userInput;
}
