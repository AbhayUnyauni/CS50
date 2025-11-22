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
    Node* temp = NULL;
    Node* head = NULL;

    n = get_int("Enter the number of nodes: ");
    if(n <= 0){
        printf("Invalid number of nodes!\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        value = get_int("Enter the value for each node: ");
        Node* newNode = createNode(value);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    printf("Doubly Linked list: ");
    temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}
