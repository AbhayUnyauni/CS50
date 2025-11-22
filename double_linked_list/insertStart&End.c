#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

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
    Node* head = NULL;
    Node* temp = NULL;
    n = get_int("Enter the value of nodes: ");
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
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
        printf("Doubly Linked List before insertion: ");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // -----------------------------
    // INSERT AT BEGINNING
    // -----------------------------
    int newBeg = get_int("Enter new value for beginning: ");
    Node* newNodeBeg = createNode(newBeg);
    if(head != NULL){
        newNodeBeg->next = head;
        head->prev = newNodeBeg;
    }
    head = newNodeBeg;

    // -----------------------------
    // INSERT AT END
    // -----------------------------
    int newValueEnd = get_int("Enter the value to insert at the end: ");
    Node* newNodeEnd = createNode(newValueEnd);

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNodeEnd;
    newNodeEnd->prev = temp;

    // -----------------------------
    // PRINT AFTER BOTH INSERTIONS
    // -----------------------------
    printf("Doubly Linked List after insertion: ");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;

}
