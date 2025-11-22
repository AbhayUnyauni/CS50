#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int main(){
    int n, value;
    Node* head = NULL;

    n = get_int("Enter the value of nodes: ");
    if(n <= 0){
        printf("Invalid number of nodes!\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        value = get_int("Enter the value of each node: ");
        Node* newNode = createNode(value);
        if(head == NULL){
            head = newNode;
        } else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    printf("Reversed doubly linked list: ");
    Node* temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}
