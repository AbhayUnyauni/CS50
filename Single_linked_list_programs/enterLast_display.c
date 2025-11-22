#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    int n, value;
    Node* head = NULL;
    Node* temp = NULL;
    n = get_int("Enter the number of nodes: ");
    if(n <= 0){
        printf("invalid number of nodes: ");
        return 1;
    }
    for(int i = 0; i < n; i++){
        value = get_int("Enter the value for each node: ");
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
    }
    printf("Linked List: ");
    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;

    }
    printf("NULL\n");
    return 0;
}
