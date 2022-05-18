#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* previous;
}Node;

void insert(Node** head, Node** tail, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->val = value;
    if (*head == NULL){
        newNode->previous = NULL;
        newNode->next = NULL;
        *tail = newNode;
        *head = newNode;
    }else if (newNode->val <= (*head)->val){
        newNode->previous = NULL;
        newNode->next = *head;
        *head = newNode;
    }else{
        Node* current = *head;
        if (newNode->val >= (*tail)->val){
            (*tail)->next = newNode;
            newNode->previous = *tail;
            *tail = newNode;
        }else{
            while (current->next->val < newNode->val && current->next != NULL){
            current = current->next;
            }
            newNode->previous = current;
            newNode->next = current->next;
            current = current->next;
            current->previous = newNode;
        }
    }
}

void printList(Node** head){
    Node* current = *head;
    if (current == NULL){
        printf("  Empty\n");
        return;
    }
    while(current != NULL){
        if(current->next != NULL){
            printf(" %d --", current->val);
        }else{
            printf(" %d", current->val);
        }
        current = current->next;
    }
    printf("\n");
}

int main(){
    Node** head = malloc(sizeof(Node));
    Node** tail = malloc(sizeof(Node));
    *head = NULL;
    *tail = NULL;
    insert(head, tail, 7);
    printList(head);
    insert(head, tail, 4);
    printList(head);
    insert(head, tail, 9);
    printList(head);
    insert(head, tail, 1);
    printList(head);
    insert(head, tail, 0);
    printList(head);



    return 1;
}