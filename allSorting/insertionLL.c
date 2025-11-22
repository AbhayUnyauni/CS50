#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

Node* sortedInsert(Node* sorted, Node* newNode) {
    if (sorted == NULL || newNode->data <= sorted->data) {
        newNode->next = sorted;
        return newNode;
    }

    Node* temp = sorted;
    while (temp->next != NULL && temp->next->data < newNode->data) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return sorted;
}

Node* insertionSort(Node* head) {
    Node* sorted = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;
        sorted = sortedInsert(sorted, current);
        current = nextNode;
    }

    return sorted;
}


int main() {
    int n, value;
    Node* head = NULL;
    Node* temp = NULL;

    n = get_int("Enter the number of nodes: ");
    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        value = get_int("Enter value: ");
        Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nOriginal Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    head = insertionSort(head);

    printf("\nSorted Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
