#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
}Node;

void push(Node* stack, int val){
    // insert at the beginning
    if (stack == NULL){
        stack = malloc(sizeof(Node));
        stack->next = NULL;
        stack->val = val;
    }else{
        Node* temp = malloc(sizeof(Node));
        temp->val = val;
        temp->next = stack;
        stack = temp;
    }
}

int pop(Node* stack){
    // delete first element and return it
    if (stack == NULL){
        printf("Stack is empty!\n")
        return -1;
    }else{
        Node* temp = stack;
        int res = stack->val;
        stack = stack->next
        free(temp);
        return res;
    }
}

void printStack(Node* stack){
    Node* current = stack;
    while(current != NULL){
        if(current->next != NULL){
            printf("%d --", current->val);
        }else{
            printf("%d", current->val);
        }
    }
}


int main(){
    Node* myStack = NULL;
    printf("Should print 'Stack is empty': -->")
    printStack(myStack);
    push(myStack, 5);
    push(myStack, 9);
    push(myStack, 22);
    push(myStack, 7);
    printf("\n\nShould print: 7 -- 22 -- 9 -- 5\n");
    printStack(myStack);
    printf("\n\nShould print 7: --> %d\n", pop(myStack));
    printf("\n\nShould print: 22 -- 9 -- 5\n");
    printStack(myStack);


    return 1;
}