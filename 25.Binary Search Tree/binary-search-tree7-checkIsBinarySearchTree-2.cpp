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
    cout << endl << endl << "Enter number be searched" <<endl;
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

void traversePreorder(BstNode* root){
    if(root == NULL)return;
    cout << root->data << " ";
    traversePreorder(root->left);
    traversePreorder(root->right);
}

void traverseInorder(BstNode* root){
    if(root == NULL)return;
    traversePreorder(root->left);
    cout << root->data << " ";
    traversePreorder(root->right);
}

void traversePostorder(BstNode* root){
    if(root == NULL)return;
    traversePreorder(root->left);
    traversePreorder(root->right);
    cout << root->data << " ";
}



bool IsBstUtil(BstNode* root, int minValue, int maxValue){
    if(root == NULL) return true;
    if(
       root->data > minValue &&
       root->data < maxValue &&
       IsBstUtil(root->left, minValue, root->data) &&
       IsBstUtil(root->right,root->data, maxValue)
       )
        return true;
    else
        return false;
}

bool IsBinarySearchTree(BstNode* root){
    return IsBstUtil(root, INT_MIN, INT_MAX);
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

    cout << endl << endl << "Label Order Traversal: " << endl;
    traverseLebelOrder(root);

    cout << endl << endl << "Preorder Traversal: " << endl;
    traversePreorder(root);

    cout << endl << endl << "Inorder Traversal: " << endl;
    traverseInorder(root);

    cout << endl << endl << "Postorder Traversal: " << endl;
    traversePostorder(root);

    cout << endl << endl << "Checking Is Binary Search Tree ... " << endl;
    if(IsBinarySearchTree(root))
        cout << endl << "The Tree is a Binary Search Tree !!! " << endl;
    else
         cout << endl << "The Tree is not a Binary Search Tree " << endl;
    SearchNumber(root);

}
