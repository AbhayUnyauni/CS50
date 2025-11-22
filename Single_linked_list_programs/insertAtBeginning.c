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
        printf("Memory Allocation failed!\n");
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

    //insert new value at beginning!!
    int newValue = get_int("Enter the value which you want to add in the beginning: ");
    Node* newNode = createNode(newValue);
    newNode->next = head;
    head = newNode;


    printf("Linked List after insertion: ");
    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}
