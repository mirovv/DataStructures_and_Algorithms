#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define m 365

struct Node{
    int data;
    struct Node* next;
};
struct Node* HT[m];

struct Node* insertNode(struct Node* head, int data){
    if (head == NULL){
        head = malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
        return head;
    }else{
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return head;
    }
}

int calculateLengthList(struct Node* head){
    int length = 0;
    if (head == NULL){
        return 0;
    }else{
        struct Node* current = head;
        while (current->next != NULL){
            length++;
            current = current->next;
        }
    }
    return length;
}

void printList(struct Node* head){
    if (head == NULL){
        return;
    }else{
        struct Node* current = head;
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

int hash(int key){
    return key % m;
}

void insertHT(int key, int value){
    HT[hash(key)] = insertNode(HT[hash(key)], value);
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

int findNumberOfSharedBirthday(){
    int i;
    int sharedBirthday = 0;
    int length = 0;
    for (i = 0; i < m; i++){
        if (HT[i] != NULL){
            length = calculateLengthList(HT[i]);
        }if (length > 1){
            sharedBirthday++;
        }
    }
    return sharedBirthday;
}

int main(){
    srand(time(NULL));
    int r = rand();

    insertHT(1, 8);
    insertHT(1, 9);
    insertHT(4, 8);
    insertHT(5, 4);
    insertHT(6, 12);
    insertHT(10, 122);
    insertHT(12, 99);
    insertHT(5, 88);

    printHT();
    
    
}