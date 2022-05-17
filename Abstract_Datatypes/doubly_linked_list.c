#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
    struct Node* previous;
}Node;

void insert(Node** head, Node** tail, int value){
    if (*head == NULL){
        Node* newNode = malloc(sizeof(Node));
        newNode->val = value;
        newNode->next = NULL;
        newNode->previous = NULL;
        *head = newNode;
        *tail = newNode;  
    }else{
        Node* newNode = malloc(sizeof(Node));
        newNode->val = value;
        newNode->next = *head;
        newNode->previous = NULL;
        (*head)->previous = newNode;
        *head = newNode;
    }
}

void deleteFirst(Node** head){
    if (*head == NULL){
        printf("Nothing to delete.. its already empty!");
        return;
    }else{
        Node* firstNode = *head;
        *head = (*head)->next;
        (*head)->previous = NULL;
        free(firstNode);
    }
}

void deleteTail(Node** tail){
    if (*tail == NULL){
        printf("Already empty\n");
        return;
    }else{
        Node* deleteNode = *tail;
        *tail = (*tail)->previous;
        (*tail)->next = NULL;
        free(deleteNode);
    }
}

void deleteFirstOccurence(Node** head, int value){
    if (*head == NULL){
        printf("Nothing to delete.. its already empty!");
        return;
    }else if ((*head)->val == value){
        Node* deleteNode = *head;
        *head = (*head)->next;
        (*head)->previous = NULL;
        free(deleteNode);
    }else{
        Node* current = *head;
        Node* lagging = current->previous;
        while(current->val != value){
            current = current->next;
            lagging = current->previous;
        }
        Node* deleteNode = current;
        lagging->next = current->next;
        // current->next->previous = lagging; // same as line 54 & 55
        current = current->next;
        current->previous = lagging;
        free(deleteNode);
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
    insert(head, tail, 1);
    insert(head, tail, 3);
    insert(head, tail, 4);
    insert(head, tail, 8);
    insert(head, tail, 8);
    insert(head, tail, 5);
    insert(head, tail, 8);
    insert(head, tail, 9);
    printList(head);
    printf("Tail %d\n", (*tail)->val);
    deleteFirst(head);
    printList(head);
    deleteFirstOccurence(head, 8);
    printList(head);
    deleteTail(tail);
    printList(head);

    return 1;
}