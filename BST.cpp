#include<iostream>

using namespace std; 

struct BST{
    float value; 
    struct BST* left; 
    struct BST* right; 
}; 

BST* createNewNode(float val){
    BST* newNode = new BST(); 
    newNode -> left = NULL; 
    newNode -> right = NULL; 
    newNode -> value = val; 
    return newNode; 
}

BST* insertNewNode(BST *node, float value){
    if(!node){
        return createNewNode(value); 
    }
    if(node -> value < value){
        node -> right = insertNewNode(node -> right, value); 
    }
    else if(node -> value > value){
        node -> left = insertNewNode(node -> left, value); 
    }
    return node; 
}

void traverse(BST* node){
    if(!node){
        return; 
    }
    traverse(node -> left); 
    cout << node -> value << " "; 
    traverse(node -> right); 
}

void freeT(BST* root){
    if(!root){
        return; 
    }
    freeT(root -> left); 
    freeT(root -> right);
    delete root; 
}

BST* findNode(BST* node, float value){
    if(!node){
        return NULL; 
    }
    if(node -> value == value){
        return node; 
    }
    if(node -> value < value){
        return findNode(node -> right, value); 
    }
    else{
        return findNode(node -> left, value); 
    }
}

BST* findNodeLeft(BST* node){
    if(!(node -> left)){
        return node; 
    }
    return findNodeLeft(node -> left); 
}

BST* deleteNode(BST* node, float value){
    if(!node){
        return NULL; 
    }
    if(node -> value < value){
        node -> right = deleteNode(node -> right, value); 
    }
    else if(node -> value > value){
        node -> left = deleteNode(node -> left, value); 
    }
    else{
        if(!node -> left && !node -> right){
            delete node; 
            return NULL; 
        }
        if(!node -> left || !node -> right){
            if(!node -> left){
                BST* temp = node -> right; 
                delete node; 
                return temp; 
            }
            else{
                BST* temp = node -> left; 
                delete node; 
                return temp;
            }
        }
        BST* temp = findNodeLeft(node -> right); 
        node -> value = temp -> value; 
        node -> right = deleteNode(node -> right, node -> value); 
    }
    return node;
}

int main(){
    BST* root = NULL; 
    float arr[] = {1, 4, 9, 2, 11, 15, 10, 12, 13, 21, 18, 20}; 
    root = insertNewNode(root, 10); 
    for(int i = 1; i < sizeof(arr) / sizeof(arr[0]);i ++){
        insertNewNode(root, arr[i]); 
    }
    traverse(root); 
    BST* node = findNode(root, 21); 
    if(!node){
        cout << "Not Found\n"; 
    }
    else{
        cout << "Found\n"; 
    }
    root = deleteNode(root, 21); 
    traverse(root); 
    freeT(root); 
    return 0; 
}