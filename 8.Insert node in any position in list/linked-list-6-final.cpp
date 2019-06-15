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

void printLinkedList(Node *head){
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

Node* insertNode(Node* head,int data, int position){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    if(position == 1){
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node* nodeBeforePos = head;
    for (int i=0; i<position-2; i++){
        nodeBeforePos=nodeBeforePos->next;
    }
    newNode->next=nodeBeforePos->next;
    nodeBeforePos->next=newNode;
    return head;
}

Node* deleteNode(Node* head, int position){
    if(position == 1){
        Node* arrayHead=head;
        head=arrayHead->next;
        free(arrayHead);
        return head;
    }
    Node* nodeBeforePos=head;
    Node* nodeOnPos;
    for(int i=0; i<position-2; i++){
        nodeBeforePos=nodeBeforePos->next;
    }
    nodeOnPos=nodeBeforePos->next;
    nodeBeforePos->next=nodeOnPos->next;
    free(nodeOnPos);
    return head;
}

Node* reverseLinkedList(Node *head){
    Node *current, *prev, *next;
    current=head;
    prev=NULL;
    while(current != NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    printLinkedList(head);
    return head;
}

Node* insertElements(Node *head){
    head = insertNode(head,2,1);
    head = insertNode(head,3,2);
    head = insertNode(head,4,1);
    head = insertNode(head,5,2);
    printLinkedList(head);
    return head;
}
Node* insertElement(Node *head){
   int data=takeUserInput("Please give value, you want to insert\n");
   int position=takeUserInput("Please give list position\n");
   head = insertNode(head,data,position);
   printLinkedList(head);
   return head;
}
Node* deleteElement(Node* head){
    int position=takeUserInput("Enter position for delete element");
    head=deleteNode(head,position);
    printLinkedList(head);
    return head;
}
void printUserInstruction(){
    printf("\nArray Operations for Link List:\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Reverse\n");
}
Node* automateArrayOperation(Node *head){
    printUserInstruction();
    int selectOption=takeUserInput("\nPlease Select Any Array Operation for Link List");
    switch(selectOption){
    case 1:
        head=insertElement(head);
        head=automateArrayOperation(head);
        break;
    case 2:
        head=deleteElement(head);
        head=automateArrayOperation(head);
        break;
    case 3:
        head=reverseLinkedList(head);
        head=automateArrayOperation(head);
        break;
    }
}
main(){
    struct Node* head;
    head=NULL;
    head=insertElements(head);
    head=automateArrayOperation(head);
}
