#include <stdio.h>
#include <stdlib.h>

#define m 12 // size of HT

typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* HT[m];

Node* insert(Node* head, int value){
    if (head == NULL){
        Node* newNode = malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        head = newNode;
    }else{
        Node* newNode = malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int hash(int key){
    // division method
    return key % m;
}

void insertHT(int key){
    HT[hash(key)] = insert(HT[hash(key)], key);
}

void printList(Node* head){
    if (head == NULL){
        return;
    }else{
        Node* current = head;
        while (current != NULL){
            if (current->next == NULL){
                printf(" %d - END", current->data);
            }else{
                printf(" %d -->", current->data);
            }
        current = current->next;
        }
        printf("\n");
    }
}

void printHT(){
    int i;
    printf("Table size: %d\n", m);
    for (i = 0; i < m; i++){
        if (HT[i] == NULL){
            printf("Index %d in Hashtable ---> EMPTY\n", i);
        }else{
            printf("Index %d in Hashtable --->", i);
            printList(HT[i]);
        }
    }
}

void clearHT(){
    for (int i = 0; i < m; i++){
        HT[i] = NULL;
    }
}

int main(){
    insertHT(51);
    insertHT(12);
    insertHT(0);
    insertHT(27);
    insertHT(88);
    printHT();
}