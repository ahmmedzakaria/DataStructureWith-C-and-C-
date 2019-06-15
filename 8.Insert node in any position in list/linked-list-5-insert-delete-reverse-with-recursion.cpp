#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    Node* next;
public:
    void printNode(){
        printf("Data: %d. next: %d Address: %d\n",data,next,this);
    }
    void printNode(Node* head){
        printf("Data: %d\tnext: %d\t Address: %d\t Head: %d\n",data,next,this,head);
    }
};
struct Node* head;

void printLinkList(){
    Node* temp=head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("\n");
}

int takeUserInput(char str[]){
    printf(str);
    printf("\n");
    int n;
    scanf("%d",&n);
    return n;
}

void insertNode(int data, int position){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    if(position == 1){
        newNode->next=head;
        head=newNode;
        return;
    }
    Node* nodeBeforePos = head;
    for (int i=0; i<position-2; i++){
        nodeBeforePos=nodeBeforePos->next;
    }
    newNode->next=nodeBeforePos->next;
    nodeBeforePos->next=newNode;
}

void deleteNode(int position){
    if(position == 1){
        Node* arrayHead=head;
        head=arrayHead->next;
        free(arrayHead);
        return;
    }
    Node* nodeBeforePos=head;
    Node* nodeOnPos;
    for(int i=0; i<position-2; i++){
        nodeBeforePos=nodeBeforePos->next;
    }
    nodeOnPos=nodeBeforePos->next;
    nodeBeforePos->next=nodeOnPos->next;
    free(nodeOnPos);
}

void reverseLinkedList(Node *ptr){
    if(ptr->next == NULL){
        head=ptr;
        return;
    }
    Node *nextNode=ptr->next;
    reverseLinkedList(nextNode);
    nextNode->next=ptr;
    ptr->next=NULL;
}

void insertElements(){
    insertNode(2,1);
    insertNode(3,2);
    insertNode(4,1);
    insertNode(5,2);
    printLinkList();
}
void insertElement(){
   int data=takeUserInput("Please give value, you want to insert\n");
   int position=takeUserInput("Please give list position\n");
   insertNode(data,position);
   printLinkList();
}
void deleteElement(){
    int position=takeUserInput("Enter position for delete element");
    deleteNode(position);
    printLinkList();
}
void printUserInstruction(){
    printf("\nArray Operations for Link List:\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Reverse\n");
}
void automateArrayOperation(){
    printUserInstruction();
    int selectOption=takeUserInput("\nPlease Select Any Array Operation for Link List");
    switch(selectOption){
    case 1:
        insertElement();
        automateArrayOperation();
        break;
    case 2:
        deleteElement();
        automateArrayOperation();
        break;
    case 3:
        reverseLinkedList(head);
        printLinkList();
        automateArrayOperation();
        break;
    }
}
main(){
    head=NULL;
    insertElements();
    automateArrayOperation();

}
