#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* init(Node* head){
    if (head == NULL){
        head = malloc(sizeof(Node));
        head->next = NULL; 
        return head;
    }else{
        return head;
    }
}

void printLL(Node* head){
    struct Node* current = head;
    if (head == NULL){
        printf("Empty linked list\n");
    }
    while (current != NULL){
        if (current->next != NULL){
            printf(" %d ->", current->val);
        }else{    
            printf(" %d", current->val);
            printf("\n");
        }
        current = current->next;
    }
}

Node* insert_End(Node* head, int value){
    if (head == NULL){
        head = init(head);
        head->val = value;
    }else{
        Node* current = head;
        Node* newNode = malloc(sizeof(Node));
        newNode->val = value;
        newNode->next = NULL;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

Node* insert_Beginning(Node* head, int value){
    if (head == NULL){
        head = init(head);
        head->val = value;
    }else{
        Node* newNode = malloc(sizeof(Node));
        newNode->val = value;
        newNode->next = head;
        head = newNode;
    } 
    return head;
}

Node* delete_Last(Node* head){
    if(head->next == NULL){
        head = NULL;
    }else{
        Node* current = head;
        while(current->next->next != NULL){
            current = current->next;
        }
        Node* tmp = current->next;
        current->next = NULL;
        free(tmp);
    }
    return head;
}
Node* delete_First(Node* head){
    if(head->next == NULL){
        head = NULL;
    }else{
        Node* firstNode = head;
        Node* tmp = head->next;
        head = tmp;
        free(firstNode);
    }
    return head;
}

Node* delete_First_Occurence(Node* head, int value){
    if(head->next == NULL && head->val == value){
        head = NULL;
    }else{
        Node* current = head;
        if(current->val == value){
            Node* deleteMe = current;
            head = head->next;
            free(deleteMe);
        }else{
            while (current->next != NULL){
                if(current->next->val == value){
                    Node* deleteMe = current->next;
                    current->next = current->next->next;
                    free(deleteMe);
                    break;
                }
                current = current->next;
            }   
        }
    }
    return head;
}


int main(){
    Node* myLL = NULL;
    printLL(myLL);
    init(myLL);
    myLL = insert_End(myLL, 7);
    printLL(myLL);
    myLL = insert_End(myLL, 9);
    printLL(myLL);
    myLL = insert_Beginning(myLL, 6);
    printLL(myLL);
    myLL = insert_End(myLL, 8);
    printLL(myLL);
    myLL = insert_Beginning(myLL, 3);
    myLL = insert_End(myLL, 7);
    myLL = insert_End(myLL, 8);
    printLL(myLL);
    myLL = delete_First_Occurence(myLL, 8);
    myLL = delete_First_Occurence(myLL, 8);
    myLL = delete_First_Occurence(myLL, 3);
    printLL(myLL);



    return 1;
}