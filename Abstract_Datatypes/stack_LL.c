#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
}Node;

void push(Node** stack, int val){
    Node* top = *stack;
    // insert at the beginning
    if (top == NULL){
        top = malloc(sizeof(Node));
        top->next = NULL;
        top->val = val;
        *stack = top;
    }else{
        Node* temp = malloc(sizeof(Node));
        temp->val = val;
        temp->next = top;
        top = temp;
        *stack = top;
    }
}

int pop(Node** stack){
    Node* top = *stack; 
    
    // delete first element and return it
    if (*stack == NULL){
        printf("\nNo more items to pop...\n");
        return -1;
    }else{
        int res = top->val;
        Node* firstNode = top;
        Node* temp = top->next;
        top = temp;
        free(firstNode);
        *stack = top;
        return res;
    }
}

void printStack(Node** stack){
    Node* current = *stack;
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
}


int main(){
    Node** myStack = malloc(sizeof(Node));
    *myStack = NULL;
    printf("Should print 'Empty': -->");
    printStack(myStack);
    push(myStack, 5);
    push(myStack, 9);
    push(myStack, 22);
    push(myStack, 7);
    printStack(myStack);
    printf("\nShould print: 7 -- 22 -- 9 -- 5\n");
    printStack(myStack);
    printf("\nShould print 7: --> %d\n", pop(myStack));
    printf("Should print: 22 -- 9 -- 5\n");
    printStack(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    printf("Should print 'Stack is empty': -->");
    printStack(myStack);



    return 1;
}