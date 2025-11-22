#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main(){
    int n, value;
    Node* temp = NULL;
    Node* head = NULL;
    n = get_int("Enter the number of nodes: ");
    if(n <= 0){
        printf("Invalid number of nodes\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        value = get_int("Enter the value for each node: ");
        Node* newNode = createNode(value);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        } else{
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    printf("Doubly Linked List before insertion: ");
    temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    int newValue = get_int("Enter new value: ");
    int pos = get_int("Enter the position: ");

    Node* newNode = createNode(newValue);

    if(pos == 1){
        newNode->next = head;
        if(head != NULL){
            head->prev = newNode;
        }
        head = newNode;
    }
    else{
        temp = head;
        for(int i = 1; i < pos - 1 && temp != NULL; i++){
            temp = temp->next;
        }

        if(temp == NULL){
            printf("Position out of range!\n");
            return 1;
        }
        newNode->next = temp->next;
        newNode->prev = temp;

        if(temp->next != NULL){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    printf("Doubly Linked List after insertion: ");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
