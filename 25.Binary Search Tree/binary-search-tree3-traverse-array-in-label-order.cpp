#include <iostream>
#include <queue>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    }else if(data <= root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;
}

bool Search(BstNode* root , int data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(root->data <= data) return Search(root->left,data);
    else return Search(root->right,data);
}

void SearchNumber(BstNode * root){
    int number;
    cout << "Enter number be searched" <<endl;
    cin >> number;
    if(Search(root, number)){
        cout << "Found" << endl;
    }else{
        cout << "Not Found" << endl;
    }
}

int FindMin(BstNode* root){
    if(root == NULL){
        cout << "Error! Tree is Empty" << endl;
        return -1;
    }else if(root->left == NULL){
        return root->data;
    }else{
        return FindMin(root->left);
    }
}

int FindMax(BstNode* root){
    if(root == NULL){
        cout << "Error! Tree is Empty" << endl;
        return -1;
    }else if(root->right == NULL){
        return root->data;
    }else{
        return FindMin(root->right->right);
    }
}
int FindHeight(BstNode* root){
    if(root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right))+1;
}

void traverseLebelOrder(BstNode* root){
    if(root == NULL)return;
    queue<BstNode*> Q;
    Q.push(root);

    while(!Q.empty()){
        BstNode* current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL)Q.push(current->left);
        if(current->right != NULL)Q.push(current->right);
        Q.pop();
    }

}
int main(){
    BstNode* root = NULL;
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,8);
    root=Insert(root,12);
    //cout << root->data << endl;
    int Min= FindMin(root);
    cout << "MIN: "<< Min << endl;

    int Max= FindMax(root);
    cout << "MAX: "<< Max << endl;

    int Height = FindHeight(root);
    cout << "Height: "<< Height << endl;

    traverseLebelOrder(root);
    SearchNumber(root);

}
