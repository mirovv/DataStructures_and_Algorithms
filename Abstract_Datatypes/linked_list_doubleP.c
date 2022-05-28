#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

void insert(Node** root, int val){
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if(*root == NULL){
        printf("hää");
        *root = newNode;
    }else{
        newNode->next = *root;
        *root = newNode;
    }
}

void printLL(Node** head){
    while(*head != NULL){
        if((*head)->next == NULL){
            printf("%d", (*head)->val);
        }else{
            printf("%d -> ", (*head)->val);
        }
        *head = (*head)->next;
    }
    printf("\n");
}

void merge(Node** l1, Node** l2){
    Node* curr;
    Node* next;
    Node* other;
    if(*l1 && *l2 == NULL){
        printf("he");
        return;
    }
    else if(*l1 == NULL){
        printf("wieso");
        *l1 = *l2;
        return;
    }
    else if(*l2 == NULL){
        printf("uncool");
        *l2 = *l1;
        return;
    }else if((*l1)->val < (*l2)->val){
        Node* curr = *l1;
        Node* next = (*l1)->next;
        Node* other = *l2;
        printf("were here");
    }else{
        Node* curr = *l2;
        Node* next = (*l2)->next;
        Node* other = *l1;
    }
    while(next && other != NULL){
        if(next->val < other->val){
            curr = curr->next;
            next = next->next;
        }else{
            curr->next = other;
            other = other->next;
        }
        curr = curr->next;
    }
    if(next != NULL){
        other->next = next; 
    }
    if(other != NULL){
        curr->next = other;
    }
    printf("ume?");
    printf("Merged list: \n");
}


int main(){
    Node* l1 = malloc(sizeof(Node));
    Node* l2 = malloc(sizeof(Node));

    insert(&l1, 83);
    insert(&l1, 77);
    insert(&l1, 33);
    insert(&l1, 23);
    insert(&l1, 8);
    insert(&l1, 3);
    insert(&l1, 2);
    insert(&l1, 1);

    insert(&l2, 69);
    insert(&l2, 43);
    insert(&l2, 21);
    insert(&l2, 19);
    insert(&l2, 7);
    insert(&l2, 2);
    insert(&l2, 1);
    insert(&l2, 0);

    printf("List 1: \n");
    printLL(&l1);
    printf("List 2: \n");
    printLL(&l2);
    merge(&l1, &l2);

}