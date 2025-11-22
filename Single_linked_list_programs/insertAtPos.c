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
        value = get_int("Enter the value of  each node: ");
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

    int newValue = get_int("Enter the new value: ");
    int pos = get_int("Enter the position where you want to add the value: ");
    Node* newNode = createNode(newValue);
    if(pos == 0){
        printf("Invalid position!\n");
        return 1;
    }
    // Case 1: Insert at beginning
    else if (pos == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        temp = head;
        printf("the value of temp = %d\n\n\n", temp->data);
        // Move temp to (pos-1) node
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                printf("Position out of range!\n");
                return 1;
            }
            temp = temp->next;
            printf("the value of tempdfksad = %d\n\n\n", temp->data);
        }

        if (temp == NULL) {
            printf("Position out of range!\n");
            return 1;
        }

        newNode->next = temp->next;
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
