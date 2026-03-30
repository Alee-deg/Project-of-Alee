#include<iostream>

using namespace std; 

struct Node{
    int value; 
    Node* next; 
}; 

Node* createNewNode(int value){
    Node* newNode = new Node(); 
    newNode -> value = value; 
    newNode -> next = NULL; 
    return newNode; 
}

void insertAtHead(Node** head, int value){
    Node* newNode = createNewNode(value); 
    newNode -> next = *head; 
    *head = newNode; 
}

Node* insertAtEnd(Node* head, int value){
    if(!head){
        return createNewNode(value);
    }
    if(head->next == NULL){
        head->next = createNewNode(value);
    } else {
        head->next = insertAtEnd(head->next, value);
    }
    return head; 
}

void traverse(Node *head){
    if(!head) return; 
    cout << head -> value << " "; 
    traverse(head -> next); 
}

void freeL(Node* head){
    if(!head) return; 
    freeL(head -> next); 
    delete head; 
}

int main(){
    Node* head = NULL; 
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    head = insertAtEnd(head, 1); 
    for(int i = 1; i < 10; i ++){
        head = insertAtEnd(head, arr[i]); 
    }
    traverse(head); 
    freeL(head); 
    return 0; 
}