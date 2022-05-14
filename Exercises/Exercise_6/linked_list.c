#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;        
};

struct Node* insertList(struct Node* head, int value){
    if (head == NULL){
        head = malloc(sizeof(struct Node));
        head->data = value;
        head ->next = NULL;
        return head;
    }else{
        struct Node* newNode = malloc(sizeof(struct Node));
        struct Node* current = head;
        newNode->data = value;
        newNode->next = NULL;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

void displayList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    if (current->next != NULL) {
      printf(" %d ->", current->data);
    } else {
      printf(" %d", current->data);
      printf("\n");
    }
    current = current->next;
  }
}

struct Node* joining2LinkedLists(struct Node* odd, struct Node* even){
    struct Node* groupedList = NULL;
    struct Node* current = NULL;
    if (odd == NULL){
        groupedList = even;
    }else{
        groupedList = odd;
        current = groupedList;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = even;
    }
    return groupedList;
}

struct Node* groupingLinkedList(struct Node* head){
    struct Node* odd = NULL;
    struct Node* even = NULL;
    struct Node* groupedList = NULL;
    struct Node* current = head;

    while(current != NULL){
        if(current->data % 2 != 0){
            odd = insertList(odd, current->data);
        }else{
            even = insertList(even, current->data);
        }
        current = current->next;
    }
    groupedList = joining2LinkedLists(odd, even);

    return groupedList;
}

int main(){
    int n, x, i;
    struct Node* head = NULL;

    printf("Input the number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Input the data of the node %d:  ",i);
        scanf("%d", &x);
        head = insertList(head, x);
    }
    printf("Before Grouping: \n");
    displayList(head);

    struct Node* gList = groupingLinkedList(head);
    
    printf("After Grouping: \n");
    displayList(gList);
    
    return 0;
}