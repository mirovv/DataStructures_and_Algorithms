#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
    struct Node* previous;
}Node;

void enqueue(Node** head, Node** tail, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->val = value;
    if (*head == NULL){
        newNode->previous = NULL;
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;
    }else{
        newNode->next = *head;
        newNode->previous = NULL;
        (*head)->previous = newNode;
        *head = newNode;
    }
}

int dequeue(Node** tail){
    if (*tail == NULL){
        printf("Cannot dequeue any item, since the Queue is empty..\n");
        return -1;
    }else if((*tail)->previous == NULL){
        int res = (*tail)->val;
        Node* deleteNode = *tail;
        *tail = NULL;
        free(deleteNode);
        return res;
    }else{
        int res = (*tail)->val;
        Node* deleteNode = *tail;
        *tail = (*tail)->previous;
        (*tail)->next = NULL;
        free(deleteNode);
        return res;
    }
}

void printList(Node** head){
    printf("Remaining Queue: ");
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
    printf("\n\n");
}

int main(){
    Node** head = malloc(sizeof(Node));
    Node** tail = malloc(sizeof(Node));
    *head = NULL;
    *tail = NULL;
    enqueue(head, tail, 21);
    enqueue(head, tail, 52);
    enqueue(head, tail, 78);
    enqueue(head, tail, 1);
    enqueue(head, tail, 32);
    enqueue(head, tail, 27);
    printList(head);
    printf("Just dequeued: %d\n", (*tail)->val);
    dequeue(tail);
    printList(head);    
    printf("Just dequeued: %d\n", (*tail)->val);
    dequeue(tail);
    printList(head);    
    printf("Just dequeued: %d\n", (*tail)->val);
    dequeue(tail);
    printList(head);    
    printf("Just dequeued: %d\n", (*tail)->val);
    dequeue(tail);
    printList(head);    
    printf("Just dequeued: %d\n", (*tail)->val);
    dequeue(tail);
    printList(head);    
    printf("Just dequeued: %d\n", (*tail)->val);
    dequeue(tail);   
    dequeue(tail);

    return 1;
}