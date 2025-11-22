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
        printf("Memory allocation failed !\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;

}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){

    int n, value;
    Node* head = NULL;
    Node* temp = NULL;

    n = get_int("Enter the number of nodes: ");
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

    printf("Linked list before deletion: ");
    printList(head);

    printf("\n Choose deletion type: \n");
    printf("1. Deletion from beginnign\n");
    printf("2. Deletion from ending\n");
    printf("3. Deletion from specific position\n");

    int choice = get_int("Enter choice: ");

    // ================================
    // 1. DELETE FROM BEGINNING
    // ================================

    if(choice == 1){
        if(head == NULL){
            printf("List is empty!\n");
            return 1;
        }
        Node* tempNode = head;
        head = head->next;
        free(tempNode);

        printf("\n After deleting beginning: ");
        printList(head);

    // ================================
    // 2. DELETE FROM END
    // ================================

    }else if(choice == 2){

            if(head == NULL){
                printf("List is empty!\n");
                return 1;
            }

            if (head->next == NULL) {
                free(head);
                head = NULL;
             }else{
                Node* prev = NULL;
                temp = head;

                while(temp->next != NULL){
                    prev = temp ;
                    temp = temp->next;
                }
                prev->next = NULL
                free(temp);
            }
            printf("\n After deleting end: ");
            printList(head);

    // ================================
    // 3. DELETE FROM GIVEN POSITION
    // ================================

        }else if(choice == 3){

            int pos = get_int("Enter position to delte: ");

            if(pos <= 0){
                printf("Invalid Position!\n");
                return 1;
            }
            if(pos == 1){
                Node* tempNode = head;
                head = head->next;
                free(tempNode);
            }else{
                temp = head;
                Node* prev = NULL;
                for(int i = 0; i < pos-1; i++){
                    if(temp == NULL){
                        printf("position out of range\n");
                        return 1;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                if(temp == NULL){
                    printf("Position out of range\n");
                    return 1;
                }
                prev->next = temp->next;
                free(temp);
            }
            printf("\n After deleting at position: ");
            printList(head);
        }else{
            printf("Invalid choice!\n");
        }
    return 0;
}

