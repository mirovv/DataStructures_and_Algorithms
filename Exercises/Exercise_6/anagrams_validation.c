#include <stdio.h>
#include <stdlib.h>

struct Node{
    char letter;
    struct Node* next;
};


void displayList(struct Node* head){
    struct Node* current = head;
    
    if(head == NULL){
        printf("Linked list is empty");
    }else{
        while (current != NULL){
            if(current->next != NULL){
                printf(" %c ->", current->letter);
            }else{
                printf(" %c", current->letter);
                printf("\n");
            }
            current = current->next;
        }
    }
}

struct Node* insertNodeinList(struct Node* head, char letter){

    if (head == NULL){
        head = malloc(sizeof(struct Node));
        head->letter = letter;
        head->next = NULL;
    }else{
        struct Node* newNode = malloc(sizeof(struct Node));
        struct Node* current = head;
        newNode->letter = letter;
        newNode->next = NULL;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

struct Node* bubblesortLinkedList(struct Node* head){
    struct Node* current = head;
    struct Node* j = head;
    struct Node* sortedList = current;
    char temp;

    for (current = head; current->next != NULL; current = current->next){
        for (j = head; j->next != NULL; j = j->next){
            if (j->letter > j->next->letter){
                temp = j->next->letter;
                j->next->letter = j->letter;
                j->letter = temp;
            }
        }
    }
    return sortedList;
}

void isAnagram(struct Node* list1, struct Node* list2){
    struct Node* current = list1;

    while (current != NULL){
        if (current->letter != list2->letter){
            printf("Not Anagrams!");
            return;
        }else{
            current = current->next;
            list2 = list2->next;
        }
    }
    printf("Anagrams :D");   
}

int main(){
    int amount, i;
    char x;

    struct Node* head = NULL;

    head = insertNodeinList(head, 'a');
    head = insertNodeinList(head, 'f');
    head = insertNodeinList(head, 'e');
    head = insertNodeinList(head, 'a');
    head = insertNodeinList(head, 'r');

    struct Node* second = NULL;

    second = insertNodeinList(second, 'a');
    second = insertNodeinList(second, 'd');
    second = insertNodeinList(second, 'e');
    second = insertNodeinList(second, 'a');
    second = insertNodeinList(second, 'r');

    printf("Before: \n");
    displayList(head);
    printf("\n");
    displayList(second);
    printf("After Bubblesort: \n");
    struct Node* sortedList1 = bubblesortLinkedList(head);
    struct Node* sortedList2 = bubblesortLinkedList(second);
    displayList(sortedList1);
    printf("\n");
    displayList(sortedList2);
    isAnagram(sortedList1,sortedList2);

    return 0;
}