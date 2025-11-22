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
        printf("Memory allocation failed!\n");
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
    n = get_int("Enter the value of Nodes: ");
    if(n <= 0){
        printf("Invalid number of nodes\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        value = get_int("Enter the value of node: ");
        Node* newNode = createNode(value);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Linked List before insertion: ");
    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    //insert new value at the end

    int newValue = get_int("Enter the new value which you want to insert at the end: ");
    Node* newNode = createNode(newValue);
    if(head == NULL){
        head = newNode;
    }else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Linked List after insertion: ");
    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}
